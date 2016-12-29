namespace Nc\Db;

class DaoMysql extends DaoAbstract
{
    public function queryLastInsertId() -> string
    {
        return this->db->queryCell("SELECT last_insert_id()");
    }

    public function replace(array data) -> long
    {
        var s, k, v, ks = [], vs = [];

        let this->lastSequence = "";

        for k, v in data {
            if is_int(k) {
                unset data[k];
                continue;
            }

            let ks[] = k;
            if typeof v == "array" {
                let vs[] = this->db->expression(v);
                unset data[k];
            } else {
                let vs[] = ":" . k;
            }
        }

        let s = sprintf(
            "REPLACE INTO %s (%s) VALUES (%s)",
            this->table,
            implode(", ", ks),
            implode(", ", vs)
        );

        return this->db->execute(s, data);
    }

    public function insert(array inserts, boolean ignoreSequence = false) -> long
    {
        var rc, sequence;

        let rc = parent::insert(inserts, true);

        loop {
            if ignoreSequence || strlen(this->sequenceField) < 1 {
                break;
            }

            if fetch sequence, inserts[this->sequenceField] && sequence !== null {
                let this->lastSequence = (string) sequence;
                break;
            }

            let this->lastSequence = this->queryLastInsertId();
            break;
        }

        return rc;
    }

    public function upsert(array inserts, array updates = []) -> long
    {
        var iPre = "i_", uPre = "u_", k, kPrefixed, v, iks = [], ivs = [], us = [], params = [], s;

        if unlikely count(this->primaryKey) < 1 {
            throw new Exception(__FUNCTION__, Exception::UPSERT_PK_EMPTY);
        }
        for k in this->primaryKey {
            if unlikely ! fetch v, inserts[k] || v === null {
                throw new Exception(k, Exception::UPSERT_PK_UNSATISFIED);
            }
        }

        for k, v in inserts {
            if ! is_int(k) {
                let iks[] = k;
                if typeof v == "array" {
                    let ivs[] = this->db->expression(v);
                } else {
                    let kPrefixed           = iPre . k;
                    let ivs[]               = ":" . kPrefixed;
                    let params[kPrefixed]   = v;
                }
            }
        }

        if count(updates) < 1 {
            for k in this->primaryKey {
                let us[] = k . " = " . k;
                break;
            }
        } else {
            for k, v in updates {
                if is_int(k) {
                    if typeof v == "array" {
                        let us[] = this->db->expression(v);
                    } else {
                        let us[] = (string) v;
                    }
                } else {
                    let kPrefixed           = uPre . k;
                    let us[]                = k . " = :" . kPrefixed;
                    let params[kPrefixed]   = v;
                }
            }
        }

        let s = sprintf(
            "INSERT INTO %s (%s) VALUES (%s) ON DUPLICATE KEY UPDATE %s",
            this->table,
            implode(", ", iks),
            implode(", ", ivs),
            implode(", ", us)
        );

        return this->db->execute(s, params);
    }

    public function updateTop(array updates, var where = "", var order = null, long limit = 1) -> long
    {
        var k, v, us = [], s;

        for k, v in updates {
            if is_int(k) {
                if typeof v == "array" {
                    let us[] = this->db->expression(v);
                } else {
                    let us[] = (string) v;
                }
                unset updates[k];
            } else {
                let us[] = k . " = :" . k;
            }
        }

        let s = sprintf(
            "UPDATE %s SET %s%s%s LIMIT %d",
            this->table,
            implode(", ", us),
            this->makeWhere(where),
            this->makeOrder(order),
            limit
        );

        return this->db->execute(s, updates);
    }

    public function deleteTop(var where = "", var order = null, long limit = 1) -> long
    {
        var s;

        let s = sprintf(
            "DELETE FROM %s%s%s LIMIT %d",
            this->table,
            this->makeWhere(where),
            this->makeOrder(order),
            limit
        );

        return this->db->execute(s);
    }

    public function countAndFind(string fields, var where, var order, long limit, long skip, boolean lock) -> array
    {
        var s, data, numRows;

        let s = sprintf(
            "SELECT SQL_CALC_FOUND_ROWS %s FROM %s%s%s",
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

        let data = this->db->query(s);
        let numRows = (long) this->db->queryCell("SELECT found_rows()");

        return [numRows, data];
    }

    protected function makeRandomOrder() -> string
    {
        return "RAND()";
    }

    protected function makePagination(string sql, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("%s LIMIT %d", sql, limit);
        }

        return sprintf("%s LIMIT %d, %d", sql, skip, limit);
    }

}
