namespace Nc\Db;

abstract class DbAbstract implements DbInterface
{
    protected inTransaction = false;
    protected savepoints;
    protected queries;

    public function inTransaction() -> boolean
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
            throw new TransactionException(sprintf("Duplicate savepoint '%s'", savepoint));
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
            throw new TransactionException(sprintf("Cannot find savepoint '%s'", savepoint));
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
            throw new TransactionException(sprintf("Cannot find savepoint '%s'", savepoint));
        }

        this->query("ROLLBACK TO SAVEPOINT " . savepoint);

        loop {
            if (string) array_pop(this->savepoints) === savepoint {
                let this->savepoints[savepoint] = savepoint;
                break;
            }
        }
    }

    public function atomic(var cb, string savepoint = "sp0")
    {
        boolean inTransaction;
        var re, ex;

        let inTransaction = (boolean) this->inTransaction;
        if inTransaction {
            this->savepoint(savepoint);
        } else {
            this->begin();
        }

        try {
            let re = call_user_func(cb, this);
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

    public function query(string sql, array params = []) -> array
    {
        return this->execute(sql, params, DbInterface::ALL);
    }

    public function queryRow(string sql, array params = [])
    {
        return this->execute(sql, params, DbInterface::ROW);
    }

    public function queryCell(string sql, array params = []) -> string
    {
        return this->execute(sql, params, DbInterface::CELL);
    }

    public function queryColumns(string sql, array params = []) -> array
    {
        return this->execute(sql, params, DbInterface::COLUMNS);
    }

    public function getQueries() -> array
    {
        if count(this->queries) > 0 {
            return this->queries;
        }

        return [];
    }

    protected function addQuery(string sql, array params, double startTime) -> string
    {
        var q;

        let q = sprintf("%s # %0.3fms", sql, 1000.0 * ((double) microtime(true) - startTime));
        if count(params) > 0 {
            let q .= " " . json_encode(params, JSON_UNESCAPED_UNICODE);
        }

        let this->queries[] = q;
        return q;
    }

    public function delete(string t, array where = []) -> void
    {
        this->execute(
            "DELETE FROM " . t . this->makeWhere(where)
        );
    }

    public function insert(string t, array data, string returningId = "")
    {
        var s, r;

        let s = this->makeInsert(t, data);

        if returningId->length() > 0 {
            if fetch r, data[returningId] {
                this->execute(s, data);
                return r;
            }

            let s .= " RETURNING " . returningId;
            return this->queryCell(s, data);
        }

        this->execute(s, data);
    }

    public function update(string t, array data, array where = []) -> void
    {
        var k, v, v1, v2, kvs = [];

        for k, v in data {
            if typeof v == "array" {
                let v1 = array_shift(v);
                let v2 = array_shift(v);

                switch v1 {
                    case "+":
                    case "-":
                        let kvs[k] = sprintf("%s = %s %s (:%s)", k, k, v1, k);
                        let data[k] = v2;
                        break;

                    case "raw":
                        let kvs[k] = v2;
                        unset data[k];
                        break;

                    default:
                        throw new QueryException(sprintf("Invalid update type '%s'", v1));
                }
            } else {
                let kvs[k] = k . " = :" . k;
            }
        }

        this->execute(
            "UPDATE " . t . " SET " . implode(", ", kvs) . this->makeWhere(where),
            data
        );
    }

    public function select(string t, array where = [], array options = [])
    {
        return this->query(this->makeSelect(t, where, options));
    }

    public function selectRow(string t, array where = [], array options = [])
    {
        return this->queryRow(this->makeSelect(t, where, options));
    }

    public function selectCell(string t, array where = [], array options = [])
    {
        return this->queryCell(this->makeSelect(t, where, options));
    }

    public function selectColumns(string t, array where = [], array options = [])
    {
        return this->queryColumns(this->makeSelect(t, where, options));
    }

    public function countAndSelect(string t, array where = [], array options = []) -> array
    {
        long c;

        let c = (long) this->countAll(t, where);
        if c < 1 {
            return [0, []];
        }

        return [
            c,
            this->select(t, where, options)
        ];
    }

    public function first(string t, array where = [], var orderBy = null, boolean forUpdate = false)
    {
        return this->selectRow(t, where, [
            "orderBy": orderBy,
            "limit": 1,
            "forUpdate": forUpdate
        ]);
    }

    public function find(string t, array where = [], var orderBy = null, long limit = 0, long skip = 0) -> array
    {
        return this->select(t, where, [
            "orderBy": orderBy,
            "limit": limit,
            "skip": skip
        ]);
    }

    public function paged(string t, array where = [], var orderBy = null, long limit = 10, long page = 1) -> array
    {
        long skip, numRows, numPages;
        var nd, data;

        if limit < 1 {
            let limit = 1;
        }
        if page < 1 {
            let page = 1;
        }

        let skip = limit * (page - 1);

        let nd = this->countAndSelect(t, where, [
            "orderBy": orderBy,
            "limit": limit,
            "skip": skip
        ]);

        let numRows = (long) array_shift(nd);
        let data = array_shift(nd);

        if unlikely typeof data != "array" {
            throw new QueryException("Invalid result returned");
        }

        if numRows < 1 || count(data) < 1 {
            let numPages = 0;
        } else {
            let numPages = 1 + (long) ((numRows - 1) / limit);
        }

        return [
            "limit": limit,
            "page": page,
            "skip": skip,
            "numRows": numRows,
            "numPages": numPages,
            "data": data
        ];
    }

    public function chunk(string t, var cb, array where = [], var orderBy = null, long limit = 5000) -> long
    {
        var collection;
        long sum = 0, c, skip = 0;

        if unlikely limit < 1 {
            throw new QueryException(sprintf("Invalid limit '%d'", limit));
        }

        loop {
            let collection = this->find(t, where, orderBy, limit, skip);
            let c = count(collection);
            if c < 1 {
                break;
            }

            let sum += c;
            if call_user_func(cb, collection) === false || c < limit {
                break;
            }

            let skip += limit;
        }

        return sum;
    }

    public function chunkDynamicly(string t, var cb, array where = [], var orderBy = null, long limit = 5000) -> long
    {
        var collection, w;
        long sum = 0, c;

        if unlikely limit < 1 {
            throw new QueryException(sprintf("Invalid limit '%d'", limit));
        }

        let w = where;

        loop {
            let collection = this->find(w, orderBy, limit);
            let c = count(collection);
            if c < 1 {
                break;
            }

            let sum += c;
            let w = call_user_func(cb, collection, w);
            if typeof w != "array" || count(w) < 1 || c < limit {
                break;
            }
        }

        return sum;
    }

    public function group(string t, string groupBy, array aggrs, array where = [], array options = []) -> array
    {
        string s = "SELECT ";
        var k, v, o;

        let s .= groupBy;
        for k, v in aggrs {
            let s .= ", " . v . " AS " . k;
        }

        let s .= " FROM " . t . this->makeWhere(where) . " GROUP BY " . groupBy;

        if fetch o, options["having"] && typeof o == "array" {
            let s .= this->makeWhere(o, " HAVING ");
        }

        if fetch o, options["orderBy"] && o {
            let s .= this->makeOrderBy(o);
        }

        return this->query(s);
    }

    public function aggregations(string t, array aggrs, array where = []) -> array
    {
        var k, v, a = [];

        for k, v in aggrs {
            let a[] = v . " AS " . k;
        }

        return this->queryRow(
            "SELECT " . implode(", ", a) . " FROM " . t . this->makeWhere(where)
        );
    }

    public function aggregation(string t, string aggrFunction, string column, array where = []) -> string
    {
        return this->queryCell(
            "SELECT " . aggrFunction . "(" . column . ") FROM " .  t . this->makeWhere(where)
        );
    }

    public function countAll(string t, array where = []) -> long
    {
        return (long) this->aggregation(t, "COUNT", "*", where);
    }

    public function count(string t, string column, array where = []) -> long
    {
        return (long) this->aggregation(t, "COUNT", column, where);
    }

    public function max(string t, string column, array where = [])
    {
        return this->aggregation(t, "MAX", column, where);
    }

    public function min(string t, string column, array where = [])
    {
        return this->aggregation(t, "MIN", column, where);
    }

    public function sum(string t, string column, array where = [])
    {
        return this->aggregation(t, "SUM", column, where);
    }

    public function avg(string t, string column, array where = [])
    {
        return this->aggregation(t, "AVG", column, where);
    }

    abstract protected function tryToBegin() -> boolean;
    abstract protected function tryToCommit() -> boolean;
    abstract protected function tryToRollback() -> boolean;

    abstract protected function makeRandomOrder() -> string;
    abstract protected function makePagination(string query, long limit, long skip) -> string;

    protected function makeInsert(string t, array data) -> string
    {
        var k, ks = [], vs = [];

        for k, _ in data {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        return "INSERT INTO " . t . " (" . implode(", ", ks) . ") VALUES (" . implode(", ", vs) . ")";
    }

    protected function checkUpsert(array data, var primaryKey) -> array
    {
        var k, ks = [];

        if typeof primaryKey == "array" {
            for k in primaryKey {
                if unlikely ! isset data[k] {
                    throw new QueryException(sprintf("Cannot upsert when missing value of key '%s'", k));
                }
                let ks[k] = 1;
            }
        } else {
            let k = (string) primaryKey;
            if unlikely strlen(k) < 1 {
                throw new QueryException(sprintf("Invalid key '%s' to upsert", k));
            }
            let ks[k] = 1;
        }

        return ks;
    }

    protected function makeSelect(string t, array where, array options) -> string
    {
        string s = "SELECT ";
        var o;
        long limit, skip = 0;

        if fetch o, options["field"] && typeof o == "string" && strlen(o) > 0 {
            let s .= o;
        } else {
            let s .= "*";
        }

        let s .= " FROM " . t . this->makeWhere(where);

        if fetch o, options["orderBy"] && o {
            let s .= this->makeOrderBy(o);
        }

        if fetch o, options["limit"] {
            let limit = (long) o;
            if limit > 0 {
                if fetch o, options["skip"] {
                    let skip = (long) o;
                }
                let s = (string) this->makePagination(s, limit, skip);
            }
        }

        if fetch o, options["forUpdate"] && o {
            let s .= " FOR UPDATE";
        }

        return s;
    }

    protected function makeWhere(array where, string connector = " WHERE ") -> string
    {
        var s;

        let s = this->parseWhere(where);
        if strlen(s) > 0 {
            return connector . s;
        }

        return s;
    }

    protected function parseWhere(array where, string sep = " AND ") -> string
    {
        var k, v, ks, ws = [];
        string k1, k2, tmp;

        for k, v in where {
            let ks = explode("$", k, 3);
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
                        throw new QueryException("Invalid between");
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
                        throw new QueryException("Invalid in");
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
                        throw new QueryException("Invalid expression");
                    }

                    let tmp = (string) str_replace(["%", "?"], ["%%", "%s"], (string) array_shift(v));
                    if unlikely tmp->length() > 0 {
                        let ws[] = "(" . vsprintf(tmp, array_map([this, "quote"], v)) . ")";
                    }
                    break;

                case "and":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new QueryException("Invalid and");
                    }
                    let ws[] = "(" . this->parseWhere(v, " AND ") . ")";
                    break;
                case "or":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new QueryException("Invalid or");
                    }
                    let ws[] = "(" . this->parseWhere(v, " OR ") . ")";
                    break;
                case "xor":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new QueryException("Invalid xor");
                    }
                    let ws[] = "(" . this->parseWhere(v, " XOR ") . ")";
                    break;

                default:
                    throw new QueryException("Invalid k2: " . k2);
            }
        }

        return implode(sep, ws);
    }

    protected function parseWhereMultipleIn(string columns, array values, string isNot = "") -> string
    {
        long c;
        var k, v, vs = [], quoter;

        let c = 1 + (long) substr_count(columns, ",");
        if unlikely c < 2 {
            throw new QueryException(sprintf("Invalid multiple in columns '%s'", columns));
        }

        let quoter = [this, "quote"];

        for k, v in values {
            if unlikely typeof v != "array" || count(v) != 2 {
                throw new QueryException(sprintf("Invalid multiple in value at '%s'", k));
            }
            let vs[] = "(" . implode(", ", array_map(quoter, v)) . ")";
        }

        return "(" . columns . ")" . isNot . " in (" . implode(", ", vs) . ")";
    }

    protected function makeOrderBy(var orderBy)
    {
        if orderBy === true {
            return " ORDER BY " . this->makeRandomOrder();
        }

        return " ORDER BY " . (string) orderBy;
    }

}
