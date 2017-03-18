namespace Nc\Db;

abstract class DaoAbstract
{
    protected db;
    protected table;
    protected primaryKey;
    protected sequenceField;

    protected lastSequence = "";

    public function __construct(<DbInterface> db, string tb, array pk, string sf) -> void
    {
        let this->db            = db;
        let this->table         = tb;
        let this->primaryKey    = pk;
        let this->sequenceField = sf;
    }

    public function getDb() -> <DbInterface>
    {
        return this->db;
    }

    public function getTable() -> string
    {
        return this->table;
    }

    public function getPrimaryKey() -> array
    {
        return this->primaryKey;
    }

    public function getSequenceField() -> string
    {
        return this->sequenceField;
    }

    public function lastSequence() -> string
    {
        return this->lastSequence;
    }

    public function insert(array inserts, boolean ignoreSequence = false) -> long
    {
        var s, k, v, ks = [], vs = [];

        let this->lastSequence = "";

        for k, v in inserts {
            if is_int(k) {
                unset inserts[k];
                continue;
            }

            let ks[] = k;
            if typeof v == "array" {
                let vs[] = this->db->expression(v);
                unset inserts[k];
            } else {
                let vs[] = ":" . k;
            }
        }

        let s = sprintf(
            "INSERT INTO %s (%s) VALUES (%s)",
            this->table,
            implode(", ", ks),
            implode(", ", vs)
        );

        if ignoreSequence || strlen(this->sequenceField) < 1 {
            return this->db->execute(s, inserts);
        }

        let s .= " RETURNING " . this->sequenceField;
        let this->lastSequence = this->db->queryCell(s, inserts);

        return 1;
    }

    public function upsert(array inserts, array updates = []) -> long
    {
        throw new Exception(__FUNCTION__, Exception::QUERY_NOT_IMPLEMENTED);
    }

    public function update(array updates, var where = "") -> long
    {
        var s, k, v, kvs = [];

        for k, v in updates {
            if is_int(k) {
                if typeof v == "array" {
                    let kvs[k] = this->db->expression(v);
                } else {
                    let kvs[k] = (string) v;
                }
                unset updates[k];
            } else {
                let kvs[k] = k . " = :" . k;
            }
        }

        let s = sprintf(
            "UPDATE %s SET %s%s",
            this->table,
            implode(", ", kvs),
            this->makeWhere(where)
        );

        return this->db->execute(s, updates);
    }

    public function updateTop(array updates, var where = "", var order = null, long limit = 1) -> long
    {
        throw new Exception(__FUNCTION__, Exception::QUERY_NOT_IMPLEMENTED);
    }

    public function delete(var where = "") -> long
    {
        var s;

        let s = sprintf(
            "DELETE FROM %s%s",
            this->table,
            this->makeWhere(where)
        );

        return this->db->execute(s);
    }

    public function deleteTop(var where = "", var order = null, long limit = 1) -> long
    {
        throw new Exception(__FUNCTION__, Exception::QUERY_NOT_IMPLEMENTED);
    }

    public function find(string fields, var where, var order, long limit, long skip, boolean lock) -> array
    {
        var s;

        let s = sprintf(
            "SELECT %s FROM %s%s%s",
            fields,
            this->table,
            this->makeWhere(where),
            this->makeOrder(order)
        );

        if limit > 0 {
            let s = (string) this->makePagination(s, limit, skip);
        }

        if lock {
            let s .= " FOR UPDATE";
        }

        return this->db->query(s);
    }

    public function countAndFind(string fields, var where, var order, long limit, long skip, boolean lock) -> array
    {
        var numRows, data = [];

        let numRows = this->countAll(where);
        if numRows > 0 && numRows > skip {
            let data = this->find(fields, where, order, limit, skip, lock);
        }

        return [numRows, data];
    }

    public function findAll(var where = "", var order = null, long limit = 0, long skip = 0) -> array
    {
        return this->find("*", where, order, limit, skip, false);
    }

    public function findPaged(var where = "", var order = null, long limit = 10, long page = 1) -> array
    {
        long skip, numRows, numPages;
        var result, data;

        if limit < 1 {
            let limit = 1;
        }
        if page < 1 {
            let page = 1;
        }

        let skip    = limit * (page - 1);
        let result  = this->countAndFind("*", where, order, limit, skip, false);

        if unlikely typeof result != "array" {
            let result = [];
        }

        let numRows = (long) array_shift(result);
        let data    = array_shift(result);

        if numRows < 1 || count(data) < 1 {
            let numPages = 0;
        } else {
            let numPages = 1 + (long) ((numRows - 1) / limit);
        }

        return [
            "data"      : data,
            "limit"     : limit,
            "page"      : page,
            "skip"      : skip,
            "numRows"   : numRows,
            "numPages"  : numPages
        ];
    }

    public function findTop(var where = "", var order = null, long limit = 1, boolean lock = false) -> array
    {
        return this->find("*", where, order, limit, 0, lock);
    }

    public function findFirst(var where = "", var order = null, boolean lock = false)
    {
        var data, row;

        let data = this->find("*", where, order, 1, 0, lock);

        if fetch row, data[0] {
            return row;
        }
    }

    public function findVector(string field, var where = "", var order = null, long limit = 0) -> array
    {
        var data, row, result = [];

        let data = this->find(field, where, order, limit, 0, false);

        for row in data {
            if typeof row == "array" {
                let result[] = (string) array_shift(row);
            }
        }

        return result;
    }

    public function findMap(string kField, string vField, var where = "", var order = null, long limit = 0) -> array
    {
        var data, row, k, v, result = [];

        let data = this->find(kField . ", " . vField, where, order, limit, 0, false);

        for row in data {
            if typeof row == "array" {
                let k = (string) array_shift(row);
                let v = (string) array_shift(row);
                let result[k] = v;
            }
        }

        return result;
    }

    public function findCell(string field, var where = "", var order = null) -> string
    {
        var data, row;

        let data = this->find(field, where, order, 1, 0, false);

        if fetch row, data[0] && typeof row == "array" {
            return (string) array_shift(row);
        }

        return "";
    }

    public function group(string byField, array aggrs, var where = "", var having = "", var order = null) -> array
    {
        var f, k, v, s;

        let f = byField;
        for k, v in aggrs {
            let f .= ", " . v . " AS " . k;
        }

        let s = sprintf(
            "SELECT %s FROM %s%s GROUP BY %s%s%s",
            f,
            this->table,
            this->makeWhere(where),
            byField,
            this->makeWhere(having, " HAVING "),
            this->makeOrder(order)
        );

        return this->db->query(s);
    }

    public function aggregations(array aggrs, var where = "") -> array
    {
        var k, v, a = [], s;

        for k, v in aggrs {
            let a[] = v . " AS " . k;
        }

        let s = sprintf(
            "SELECT %s FROM %s%s",
            implode(", ", a),
            this->table,
            this->makeWhere(where)
        );

        return this->db->queryRow(s);
    }

    public function aggregation(string aggrFunction, string field, var where = "") -> string
    {
        var s;

        let s = sprintf(
            "SELECT %s(%s) FROM %s%s",
            aggrFunction,
            field,
            this->table,
            this->makeWhere(where)
        );

        return this->db->queryCell(s);
    }

    public function countAll(var where = "") -> long
    {
        return (long) this->aggregation("COUNT", "*", where);
    }

    public function count(string field, var where = "") -> long
    {
        return (long) this->aggregation("COUNT", field, where);
    }

    public function max(string field, var where = "") -> string
    {
        return this->aggregation("MAX", field, where);
    }

    public function min(string field, var where = "") -> string
    {
        return this->aggregation("MIN", field, where);
    }

    public function sum(string field, var where = "") -> string
    {
        return this->aggregation("SUM", field, where);
    }

    public function avg(string field, var where = "") -> string
    {
        return this->aggregation("AVG", field, where);
    }

    protected function makeWhere(var where, string connector = " WHERE ") -> string
    {
        var s;

        if typeof where == "array" {
            let s = this->parseWhere(where);
        } else {
            let s = (string) where;
        }

        if strlen(s) > 0 {
            return connector . s;
        }

        return s;
    }

    protected function parseWhere(array where, string sep = " AND ") -> string
    {
        var k, v, ws = [], ks, k1, k2;

        for k, v in where {
            if is_int(k) {
                if typeof v == "array" {
                    let ws[] = "(" . this->db->expression(v) . ")";
                } else {
                    let ws[] = "(" . v . ")";
                }
                continue;
            }

            let ks = explode("$", k, 3);
            let k1 = (string) array_shift(ks);
            let k2 = (string) array_shift(ks);

            if k2 === "" {
                let ws[] = k1 . " " . this->db->quote(v);
                continue;
            }

            switch k2 {
                case "in":
                    if unlikely typeof v == "array" && count(v) < 1 {
                        throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
                    }
                    let ws[] = this->parseWhereIn(k1, v, false);
                    break;
                case "notIn":
                    if unlikely typeof v == "array" && count(v) < 1 {
                        throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
                    }
                    let ws[] = this->parseWhereIn(k1, v, true);
                    break;

                case "between":
                    if unlikely typeof v != "array" || count(v) != 2 {
                        throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
                    }
                    let ws[] = this->parseWhereBetween(k1, v, false);
                    break;
                case "notBetween":
                    if unlikely typeof v != "array" || count(v) != 2 {
                        throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
                    }
                    let ws[] = this->parseWhereBetween(k1, v, true);
                    break;

                case "and":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
                    }
                    let ws[] = "(" . this->parseWhere(v, " AND ") . ")";
                    break;
                case "or":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
                    }
                    let ws[] = "(" . this->parseWhere(v, " OR ") . ")";
                    break;
                case "xor":
                    if unlikely typeof v != "array" || count(v) < 1 {
                        throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
                    }
                    let ws[] = "(" . this->parseWhere(v, " XOR ") . ")";
                    break;

                default:
                    throw new Exception(k2, Exception::QUERY_INVALID_WHERE);
            }
        }

        return implode(sep, ws);
    }

    protected function parseWhereIn(string field, var values, boolean not = false) -> string
    {
        var v;

        if typeof values == "array" {
            let v = implode(", ", array_map([this->db, "quote"], values));
        } else {
            let v = (string) values;
        }

        if not {
            return sprintf("%s NOT IN (%s)", field, v);
        }

        return sprintf("%s IN (%s)", field, v);
    }

    protected function parseWhereBetween(string field, array values, boolean not = false) -> string
    {
        var v1, v2;

        let v1 = this->db->quote(array_shift(values));
        let v2 = this->db->quote(array_shift(values));

        if not {
            return sprintf("%s NOT BETWEEN %s AND %s", field, v1, v2);
        }

        return sprintf("%s BETWEEN %s AND %s", field, v1, v2);
    }

    protected function makeOrder(var order) -> string
    {
        var s = " ORDER BY ", a, k, v;

        loop {
            if order === true {
                let s .= this->makeRandomOrder();
                break;
            }

            if typeof order == "array" {
                if unlikely count(order) < 1 {
                    return "";
                }
                let a = [];
                for k, v in order {
                    if v {
                        let a[] = k . " ASC";
                    } else {
                        let a[] = k . " DESC";
                    }
                }
                let s .= implode(", ", a);
                break;
            }

            if order {
                let s .= (string) order;
                break;
            }

            return "";
        }

        return s;
    }

    protected function makeRandomOrder() -> string
    {
        throw new Exception(__FUNCTION__, Exception::QUERY_NOT_IMPLEMENTED);
    }

    protected function makePagination(string sql, long limit, long skip) -> string
    {
        throw new Exception(__FUNCTION__, Exception::QUERY_NOT_IMPLEMENTED);
    }

}
