namespace Nc\Db;

use Nc\Std;

abstract class DbAbstract
{
    const NONE      = 0;
    const ALL       = 1;
    const ROW       = 2;
    const CELL      = 3;
    const COLUMNS   = 4;

    protected queries;
    protected inTransaction = false;
    protected savepoints;
    protected nextFlag = 1;

    public static function profiledQuery(string q, array p, double t) -> string
    {
        string s;

        let s = (string) sprintf("%s # %0.3fms", q, t * 1000.0);
        if count(p) > 0 {
            let s .= " " . json_encode(p);
        }

        return s;
    }

    abstract public function getInternalHandler();

    abstract public function quote(string value) -> string;
    abstract public function query(string sql, array params = [], long mode = self::NONE);

    public function getQueries() -> array
    {
        if this->queries {
            return this->queries;
        }

        return [];
    }

    public function insert(string table, array data, string returningId = "")
    {
        string sql;

        let sql = (string) this->insertSql(table, data);

        if returningId->length() > 0 {
            let sql .= " RETURNING " . returningId;
            return this->query(sql, data, self::CELL);
        }

        this->query(sql, data);
    }

    public function delete(string table, array where = []) -> void
    {
        this->query(this->deleteSql(table, where));
    }

    public function update(string table, array data, array where = []) -> void
    {
        this->query(this->updateSql(table, data, where), data);
    }

    public function upsert(string table, array data, var primaryKey) -> void
    {
        var k, v, where = [];

        if typeof primaryKey == "array" {
            for k in primaryKey {
                if unlikely ! fetch v, data[k] {
                    throw new Exception("Cannot find primary key value in data: " . k);
                }
                let where[k] = v;
            }
            if unlikely ! where {
                throw new Exception("Cannot upsert with empty where");
            }
        } else {
            let k = (string) primaryKey;
            if unlikely ! fetch v, data[k] {
                throw new Exception("Cannot find primary key value in data: " . k);
            }
            let where[k] = v;
        }

        this->delete(table, where);
        this->insert(table, data);
    }

    public function select(string table, array options = [], long mode = self::ALL)
    {
        return this->query(this->selectSql(table, options), [], mode);
    }

    public function countAndSelect(string table, array options = [], long mode = self::ALL) -> array
    {
        long c;

        let c = (long) this->query(this->selectCountSql(table, options), [], self::CELL);
        if c < 1 {
            return [0, []];
        }

        return [
            c,
            this->select(table, options, mode)
        ];
    }

    public function selectUnionAll(array selects, var orderBy = null, long limit = 0, long skip = 0) -> array
    {
        string s;

        let s = (string) this->selectUnionAllSql(selects, orderBy, limit, skip);
        return this->query(s, [], self::ALL);
    }

    public function countAndSelectUnionAll(array selects, var orderBy = null, long limit = 0, long skip = 0) -> array
    {
        long c;

        if count(selects) < 1 {
            return [0, []];
        }

        let c = (long) this->query(this->selectCountUnionAllSql(selects), [], self::CELL);
        if c < 1 {
            return [0, []];
        }

        return [
            c,
            this->selectUnionAll(selects, orderBy, limit, skip)
        ];
    }

    public function aggregations(string table, array aggregations, array where = []) -> array
    {
        return this->query(this->aggregationsSql(table, aggregations, where), [], self::ROW);
    }

    public function aggregation(string table, string column, string aggregation, array where = [])
    {
        return this->query(this->aggregationSql(table, column, aggregation, where), [], self::CELL);
    }

    public function count(string table, string column = "*", array where = []) -> long
    {
        return (long) this->aggregation(table, column, "COUNT", where);
    }

    public function max(string table, string column, array where = [])
    {
        return this->aggregation(table, column, "MAX", where);
    }

    public function min(string table, string column, array where = [])
    {
        return this->aggregation(table, column, "MIN", where);
    }

    public function sum(string table, string column, array where = [])
    {
        return this->aggregation(table, column, "SUM", where);
    }

    public function avg(string table, string column, array where = [])
    {
        return this->aggregation(table, column, "AVG", where);
    }

    public function groupAggregations(string table, string groupBy, array aggregations, array options = []) -> array
    {
        return this->query(this->groupAggregationsSql(table, groupBy, aggregations, options), [], self::ALL);
    }

    public function inTransaction() -> bool
    {
        return this->inTransaction;
    }

    public function begin() -> void
    {
        if unlikely !! this->inTransaction {
            throw new TransactionException("Cannot begin when already in transaction");
        }

        if unlikely ! this->tryToBegin() {
            throw new TransactionException("Cannot begin transaction");
        }

        let this->inTransaction = true;
    }

    public function commit() -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot commit when not in transaction");
        }

        if unlikely ! this->tryToCommit() {
            throw new TransactionException("Cannot commit transaction");
        }

        let this->inTransaction = false;
    }

    public function rollback() -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot rollback when not in transaction");
        }

        if unlikely ! this->tryToRollback() {
            throw new TransactionException("Cannot rollback transaction");
        }

        let this->inTransaction = false;
    }

    public function savepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot acquire a savepoint when not in a transaction");
        }

        if unlikely isset this->savepoints[savepoint] {
            throw new TransactionException("Duplicate savepoint: " . savepoint);
        }

        this->query("SAVEPOINT " . savepoint);
        let this->savepoints[savepoint] = savepoint;
    }

    public function releaseSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot release a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new TransactionException("Cannot find savepoint: " . savepoint);
        }

        this->query("RELEASE SAVEPOINT " . savepoint);
        unset this->savepoints[savepoint];
    }

    public function releaseLastSavepoint() -> void
    {
        string savepoint;

        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot release last savepoint when not in a transaction");
        }

        if unlikely ! this->savepoints {
            throw new TransactionException("Empty savepoint stack");
        }

        let savepoint = (string) end(this->savepoints);

        this->query("RELEASE SAVEPOINT " . savepoint);
        unset this->savepoints[savepoint];
    }

    public function rollbackToSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot rollback to a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new TransactionException("Cannot find savepoint: " . savepoint);
        }

        this->query("ROLLBACK TO SAVEPOINT " . savepoint);

        loop {
            if (string) array_pop(this->savepoints) === savepoint {
                let this->savepoints[savepoint] = savepoint;
                break;
            }
        }
    }

    public function rollbackToLastSavepoint() -> void
    {
        string savepoint;

        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot rollback to last savepoint when not in a transaction");
        }

        if unlikely ! this->savepoints {
            throw new TransactionException("Empty savepoint stack");
        }

        let savepoint = (string) end(this->savepoints);
        this->query("ROLLBACK TO SAVEPOINT " . savepoint);
    }

    public function insertSql(string table, array data) -> string
    {
        var k, ks = [], vs = [];

        for k, _ in data {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        return "INSERT INTO " . table . " (" . implode(", ", ks) . ") VALUES (" . implode(", ", vs) . ")";
    }

    public function deleteSql(string table, array where) -> string
    {
        string s, w;

        let s = "DELETE FROM " . table;
        let w = (string) this->whereSql(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        return s;
    }

    public function updateSql(string table, array data, array where) -> string
    {
        var k, kvs = [];
        string s, w;

        for k, _ in data {
            let kvs[k] = k . " = :" . k;
        }

        let s = "UPDATE " . table . " SET " . implode(", ", kvs);
        let w = (string) this->whereSql(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        return s;
    }

    public function selectSql(string table, array options) -> string
    {
        string field, w;
        var where, orderBy;
        long limit, skip;
        bool forUpdate;
        string s = "SELECT ";

        let field = (string) Std::valueAt(options, "field", "*");
        let where = (array) Std::valueAt(options, "where", []);
        let orderBy = Std::valueAt(options, "orderBy", null, true);
        let limit = (long) Std::valueAt(options, "limit", 0);
        let skip = (long) Std::valueAt(options, "skip", 0);
        let forUpdate = (bool) Std::valueAt(options, "forUpdate", false);

        if field->length() > 0 {
            let s .= field;
        } else {
            let s .= "*";
        }

        let s .= " FROM " . table;

        let w = (string) this->whereSql(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->randomOrderSql();
                let skip = 0;
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        if limit > 0 {
            let s = (string) this->paginationSql(s, limit, skip);
        }

        if forUpdate {
            let s .= " FOR UPDATE";
        }

        return s;
    }

    public function selectCountSql(string table, array options) -> string
    {
        var where;
        string s, w;

        let where = (array) Std::valueAt(options, "where", []);

        let s = "SELECT COUNT(*) FROM " . table;
        let w = (string) this->whereSql(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        return s;
    }

    public function selectUnionAllSql(array selects, var orderBy, long limit, long skip) -> string
    {
        var i, a = [];
        string s;

        if unlikely count(selects) < 1 {
            throw new Exception("Invalid union all, empty selects");
        }

        for i in selects {
            let a[] = "(" . i . ")";
        }

        let s = "SELECT * FROM (" . (string) implode(" UNION ALL ", a) . ") AS " . (string) this->nextFlag("u");

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->randomOrderSql();
                let skip = 0;
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        if limit < 1 {
            return s;
        }

        return this->paginationSql(s, limit, skip);
    }

    public function selectCountUnionAllSql(array selects) -> string
    {
        var i, a = [];

        if unlikely count(selects) < 1 {
            throw new Exception("Invalid union all, empty selects");
        }

        for i in selects {
            let a[] = "(" . i . ")";
        }

        return "SELECT COUNT(*) FROM (" . (string) implode(" UNION ALL ", a) . ") AS " . (string) this->nextFlag("u");
    }

    public function aggregationsSql(string table, array aggregations, array where) -> string
    {
        var k, v, a = [];
        string s, w;

        for k, v in aggregations {
            let a[] = v . " AS " . k;
        }

        let s = "SELECT " . implode(", ", a) . " FROM " .table;

        let w = (string) this->whereSql(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        return s;
    }

    public function aggregationSql(string table, string column, string aggregation, array where) -> string
    {
        string s, w;

        let s = "SELECT " . aggregation . "(" . column . ") FROM " .  table;

        let w = (string) this->whereSql(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        return s;
    }

    public function groupAggregationsSql(string table, string groupBy, array aggregations, array options) -> string
    {
        var where, having;
        var orderBy;
        var k, v, a = [];
        string s, w;

        let where = (array) Std::valueAt(options, "where", []);
        let having = (array) Std::valueAt(options, "having", []);
        let orderBy = Std::valueAt(options, "orderBy", null, true);

        let a[] = groupBy;

        for k, v in aggregations {
            let a[] = v . "(" . groupBy . ") AS " . k;
        }

        let s = "SELECT " . implode(", ", a) . " FROM " .table;

        let w = (string) this->whereSql(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        let s .= " GROUP BY " . groupBy;

        let w = (string) this->whereSql(having);
        if w->length() > 0 {
            let s .= " HAVING " . w;
        }

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->randomOrderSql();
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        return s;
    }

    public function whereSql(array where, string sep = " AND ") -> string
    {
        var k, v, ks, ws = [];
        string k1, k2, tmp;

        for k, v in where {
            let ks = explode("$", k);
            let k1 = (string) array_shift(ks);
            let k2 = (string) array_shift(ks);
            let tmp = "";

            switch k2 {
                case "":
                    if v === null {
                        let ws[] = k1 . " IS NULL";
                    } else {
                        let ws[] = k1 . " = " . this->quote(v);
                    }
                    break;
                case "neq":
                    if v === null {
                        let ws[] = k1 . "IS NOT NULL";
                    } else {
                        let ws[] = k1 . " <> " . this->quote(v);
                    }
                    break;
                case "lt":
                    let ws[] = k1 . " < " . this->quote(v);
                    break;
                case "lte":
                    let ws[] = k1 . " <= " . this->quote(v);
                    break;
                case "gt":
                    let ws[] = k1 . " > " . this->quote(v);
                    break;
                case "gte":
                    let ws[] = k1 . " >= " . this->quote(v);
                    break;
                case "notBetween":
                    let tmp = " NOT";
                case "between":
                    if unlikely typeof v != "array" || ! isset v[0] || ! isset v[1] {
                        throw new Exception("Invalid between");
                    }
                    let ws[] = k1 . tmp . " BETWEEN " . this->quote(v[0]) . " AND " . this->quote(v[1]);
                    break;
                case "notLike":
                    let tmp = " NOT";
                case "like":
                    let ws[] = k1 . tmp . " LIKE " . this->quote(v);
                    break;
                case "notIn":
                    let tmp = " NOT";
                case "in":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid in");
                    }
                    if strpos(k1, ",") === false {
                        let ws[] = k1 . tmp . " IN (" . implode(", ", array_map([this, "quote"], v)) . ")";
                    } else {
                        let ws[] = this->whereMultipleInSql(k1, v, tmp);
                    }
                    break;
                case "notInSelect":
                    let tmp = " NOT";
                case "inSelect":
                    if strpos(k1, ",") !== false {
                        let k1 = "(" . k1 . ")";
                    }
                    let ws[] = k1 . tmp . " IN (" . v . ")";
                    break;

                case "raw":
                    let ws[] = "(" . v . ")";
                    break;
                case "expression":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid expression");
                    }

                    let tmp = (string) str_replace(["%", "?"], ["%%", "%s"], (string) array_shift(v));
                    if unlikely tmp->length() > 0 {
                        let ws[] = "(" . vsprintf(tmp, array_map([this, "quote"], v)) . ")";
                    }
                    break;

                case "and":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid and");
                    }
                    let ws[] = "(" . this->whereSql(v, " AND ") . ")";
                    break;
                case "or":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid or");
                    }
                    let ws[] = "(" . this->whereSql(v, " OR ") . ")";
                    break;
                case "xor":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid xor");
                    }
                    let ws[] = "(" . this->whereSql(v, " XOR ") . ")";
                    break;

                default:
                    throw new Exception("Invalid k2: " . k2);
            }
        }

        return implode(sep, ws);
    }

    public function whereMultipleInSql(string columns, array values, string isNot = "") -> string
    {
        long c;
        var k, v, vs = [], quoter;

        let c = 1 + (long) substr_count(columns, ",");
        if unlikely c < 2 {
            throw new Exception("Invalid multiple in columns: " . columns);
        }

        let quoter = [this, "quote"];

        for k, v in values {
            if unlikely typeof v != "array" || count(v) != 2 {
                throw new Exception("Invalid multiple in value at: " . k);
            }
            let vs[] = "(" . implode(", ", array_map(quoter, v)) . ")";
        }

        return "(" . columns . ")" . isNot . " in (" . implode(", ", vs) . ")";
    }

    abstract public function paginationSql(string query, long limit, long skip) -> string;
    abstract public function randomOrderSql() -> string;

    abstract protected function tryToBegin() -> bool;
    abstract protected function tryToCommit() -> bool;
    abstract protected function tryToRollback() -> bool;

    protected function nextFlag(string pre = "") -> string
    {
        long flag;

        let flag = (long) this->nextFlag;
        let this->nextFlag = flag + 1;

        return sprintf("%s%d", pre, flag);
    }

}
