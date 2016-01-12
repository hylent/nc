namespace Nc\Db;

use Nc\Std;

abstract class DbAbstract implements DbInterface
{
    protected queries;
    protected inTransaction = false;
    protected savepoints;
    protected nextFlag = 1;

    public static function profiledQuery(string q, array p, double t) -> string
    {
        string s;

        let t = (double) microtime(true) - t;
        let s = (string) sprintf("%s # %0.3fms", q, t * 1000.0);
        if count(p) > 0 {
            let s .= " " . json_encode(p);
        }

        return s;
    }

    public function getQueries() -> array
    {
        if this->queries {
            return this->queries;
        }

        return [];
    }

    public function query(string sql, array params = [])
    {
        return this->queryAndFetch(DbInterface::NONE, sql, params);
    }

    public function queryAll(string sql, array params = [])
    {
        return this->queryAndFetch(DbInterface::ALL, sql, params);
    }

    public function queryRow(string sql, array params = [])
    {
        return this->queryAndFetch(DbInterface::ROW, sql, params);
    }

    public function queryCell(string sql, array params = [])
    {
        return this->queryAndFetch(DbInterface::CELL, sql, params);
    }

    public function queryColumns(string sql, array params = [])
    {
        return this->queryAndFetch(DbInterface::COLUMNS, sql, params);
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
        let this->savepoints = null;
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
        let this->savepoints = null;
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

    public function atomic(var delegate)
    {
        bool inTransaction;
        string savepoint;
        var re, ex;

        let inTransaction = (bool) this->inTransaction;
        if inTransaction {
            let savepoint = (string) this->nextFlag("upsert");
            this->savepoint(savepoint);
        } else {
            this->begin();
        }

        try {
            let re = call_user_func(delegate, this);
        } catch \Exception, ex {
            if inTransaction {
                this->rollbackToSavepoint(savepoint);
            } else {
                this->rollback();
            }
            throw ex;
        }

        if inTransaction {
            this->releaseSavepoint(savepoint);
        } else {
            this->commit();
        }

        return re;
    }

    public function delete(string table, array where = []) -> void
    {
        string s, w;

        let s = "DELETE FROM " . table;
        if count(where) > 0 {
            let w = (string) this->parseWhere(where);
            if w->length() > 0 {
                let s .= " WHERE " . w;
            }
        }

        this->query(s);
    }

    public function insert(string table, array data, string returningId = "")
    {
        var k, ks = [], vs = [];
        string s;

        for k, _ in data {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        let s = "INSERT INTO " . table . " (" . implode(", ", ks) . ") VALUES (" . implode(", ", vs) . ")";

        if returningId->length() > 0 {
            let s .= " RETURNING " . returningId;
            return this->queryCell(s, data);
        }

        this->query(s, data);
    }

    public function update(string table, array data, array where = []) -> void
    {
        var k, kvs = [];
        string s, w;

        for k, _ in data {
            let kvs[k] = k . " = :" . k;
        }

        let s = "UPDATE " . table . " SET " . implode(", ", kvs);

        if count(where) > 0 {
            let w = (string) this->parseWhere(where);
            if w->length() > 0 {
                let s .= " WHERE " . w;
            }
        }

        this->query(s, data);
    }

    public function parseSelect(string table, array options) -> string
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

        let w = (string) this->parseWhere(where);
        if w->length() > 0 {
            let s .= " WHERE " . w;
        }

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->parseRandomOrder();
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        if limit > 0 {
            let s = (string) this->parsePagination(s, limit, skip);
        }

        if forUpdate {
            let s .= " FOR UPDATE";
        }

        return s;
    }

    public function select(string table, array options = [], long $fetch = DbInterface::ALL)
    {
        return this->queryAndFetch($fetch, this->parseSelect(table, options));
    }

    public function selectRow(string table, array options = [])
    {
        return this->select(table, options, DbInterface::ROW);
    }

    public function selectCell(string table, array options = [])
    {
        return this->select(table, options, DbInterface::CELL);
    }

    public function selectColumns(string table, array options = [])
    {
        return this->select(table, options, DbInterface::COLUMNS);
    }

    public function countAndSelect(string table, array options = [], long $fetch = DbInterface::ALL) -> array
    {
        string s, w;
        var where;
        long c;

        let s = "SELECT COUNT(*) FROM " . table;

        let where = (array) Std::valueAt(options, "where", []);
        if count(where) > 0 {
            let w = (string) this->parseWhere(where);
            if w->length() > 0 {
                let s .= " WHERE " . w;
            }
        }

        let c = (long) this->queryCell(s);
        if c < 1 {
            return [0, []];
        }

        return [
            c,
            this->select(table, options, $fetch)
        ];
    }

    public function selectUnionAll(array selects, array options = [], long $fetch = DbInterface::ALL)
    {
        var i, t, a = [];
        string s;
        var orderBy;
        long limit, skip;

        if count(selects) < 1 {
            return [];
        }

        for i in selects {
            if typeof i == "array" && fetch t, i["table"] {
                let i = this->parseSelect(t, i);
            }
            let a[] = "(" . i . ")";
        }

        let s = "SELECT * FROM (" . (string) implode(" UNION ALL ", a) . ") AS " . (string) this->nextFlag("u");

        let orderBy = Std::valueAt(options, "orderBy", null, true);
        let limit = (long) Std::valueAt(options, "limit", 0);
        let skip = (long) Std::valueAt(options, "skip", 0);

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->parseRandomOrder();
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        if limit > 0 {
            let s = (string) this->parsePagination(s, limit, skip);
        }

        return this->queryAndFetch($fetch, s);
    }

    public function countAndSelectUnionAll(array selects, array options = [], long $fetch = DbInterface::ALL) -> array
    {
        var i, t, a = [];
        string s;
        long c;

        if count(selects) < 1 {
            return [0, []];
        }

        for i in selects {
            if typeof i == "array" && fetch t, i["table"] {
                let i = this->parseSelect(t, i);
            }
            let a[] = "(" . i . ")";
        }

        let s = "SELECT COUNT(*) FROM (" . (string) implode(" UNION ALL ", a) . ") AS " . (string) this->nextFlag("u");

        let c = (long) this->queryCell(s);
        if c < 1 {
            return [0, []];
        }

        return [
            c,
            this->selectUnionAll(selects, options, $fetch)
        ];
    }

    public function count(string table, string column = "*", array where = []) -> long
    {
        return (long) this->aggregation(table, "COUNT", column, where);
    }

    public function max(string table, string column, array where = [])
    {
        return this->aggregation(table, "MAX", column, where);
    }

    public function min(string table, string column, array where = [])
    {
        return this->aggregation(table, "MIN", column, where);
    }

    public function sum(string table, string column, array where = [])
    {
        return this->aggregation(table, "SUM", column, where);
    }

    public function avg(string table, string column, array where = [])
    {
        return this->aggregation(table, "AVG", column, where);
    }

    public function aggregation(string table, string aggregationFunction, string column, array where = [])
    {
        string s, w;

        let s = "SELECT " . aggregationFunction . "(" . column . ") FROM " .  table;

        if count(where) > 0 {
            let w = (string) this->parseWhere(where);
            if w->length() > 0 {
                let s .= " WHERE " . w;
            }
        }

        return this->queryCell(s);
    }

    public function aggregations(string table, array aggregations, array where = []) -> array
    {
        var k, v, a = [];
        string s, w;

        for k, v in aggregations {
            let a[] = v . " AS " . k;
        }

        let s = "SELECT " . implode(", ", a) . " FROM " .table;

        if count(where) > 0 {
            let w = (string) this->parseWhere(where);
            if w->length() > 0 {
                let s .= " WHERE " . w;
            }
        }

        return this->queryRow(s);
    }

    public function groupAggregations(string table, string groupBy, array aggregations, array options = []) -> array
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

        if count(where) > 0 {
            let w = (string) this->parseWhere(where);
            if w->length() > 0 {
                let s .= " WHERE " . w;
            }
        }

        let s .= " GROUP BY " . groupBy;

        if count(having) > 0 {
            let w = (string) this->parseWhere(having);
            if w->length() > 0 {
                let s .= " HAVING " . w;
            }
        }

        if orderBy {
            if orderBy === true {
                let s .= " ORDER BY " . (string) this->parseRandomOrder();
            } else {
                let s .= " ORDER BY " . (string) orderBy;
            }
        }

        return this->queryAll(s);
    }

    public function parseWhere(array where, string sep = " AND ") -> string
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
                        let ws[] = this->parseWhereMultipleIn(k1, v, tmp);
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
                    let ws[] = "(" . this->parseWhere(v, " AND ") . ")";
                    break;
                case "or":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid or");
                    }
                    let ws[] = "(" . this->parseWhere(v, " OR ") . ")";
                    break;
                case "xor":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception("Invalid xor");
                    }
                    let ws[] = "(" . this->parseWhere(v, " XOR ") . ")";
                    break;

                default:
                    throw new Exception("Invalid k2: " . k2);
            }
        }

        return implode(sep, ws);
    }

    public function parseWhereMultipleIn(string columns, array values, string isNot = "") -> string
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

    public function pickWhereByKey(array data, var key) -> array
    {
        var k, v, where = [];

        if typeof key == "array" {
            for k in key {
                if unlikely ! fetch v, data[k] {
                    throw new Exception("Cannot find value in data: " . k);
                }
                let where[k] = v;
            }
        } else {
            let k = (string) key;
            if unlikely ! fetch v, data[k] {
                throw new Exception("Cannot find value in data: " . k);
            }
            let where[k] = v;
        }

        return where;
    }

    abstract public function parsePagination(string query, long limit, long skip) -> string;
    abstract public function parseRandomOrder() -> string;

    abstract protected function tryToBegin() -> bool;
    abstract protected function tryToCommit() -> bool;
    abstract protected function tryToRollback() -> bool;

    protected function nextFlag(string prefix = "") -> string
    {
        long flag;

        let flag = (long) this->nextFlag;
        let this->nextFlag = flag + 1;

        return sprintf("%s%d", prefix, flag);
    }

}
