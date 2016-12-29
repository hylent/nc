namespace Nc\Db;

class DaoPgsql extends DaoAbstract
{
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

        let s = sprintf(
            "INSERT INTO %s (%s) VALUES (%s) ON CONFLICT (%s) DO",
            this->table,
            implode(", ", iks),
            implode(", ", ivs),
            implode(", ", this->primaryKey)
        );

        if count(updates) < 1 {
            let s .= " NOTHING";
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

            let s .= sprintf(
                " UPDATE SET %s",
                implode(", ", us)
            );
        }

        return this->db->execute(s, params);
    }

    public function updateTop(array updates, var where = "", var order = null, long limit = 1) -> long
    {
        var k, v, us = [], pks, s;

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

        let pks = implode(", ", this->primaryKey);

        let s = sprintf(
            "WITH t1 AS (SELECT %s FROM %s%s%s LIMIT %d) UPDATE %s SET %s WHERE (%s) IN (SELECT %s FROM t1)",
            pks,
            this->table,
            this->makeWhere(where),
            this->makeOrder(order),
            limit,
            this->table,
            implode(", ", us),
            pks,
            pks
        );

        return this->db->execute(s, updates);
    }

    public function deleteTop(var where = "", var order = null, long limit = 1) -> long
    {
        var pks, s;

        let pks = implode(", ", this->primaryKey);

        let s = sprintf(
            "WITH t1 AS (SELECT %s FROM %s%s%s LIMIT %d) DELETE FROM %s WHERE (%s) IN (SELECT %s FROM t1)",
            pks,
            this->table,
            this->makeWhere(where),
            this->makeOrder(order),
            limit,
            this->table,
            pks,
            pks
        );

        return this->db->execute(s);
    }

    protected function makeRandomOrder() -> string
    {
        return "RANDOM()";
    }

    protected function makePagination(string sql, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("%s LIMIT %d", sql, limit);
        }

        return sprintf("%s LIMIT %d OFFSET %d", sql, limit, skip);
    }

}
