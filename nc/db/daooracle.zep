namespace Nc\Db;

class DaoOracle extends DaoAbstract
{
    public function upsert(array inserts, array updates = []) -> long
    {
        var iPre = "i_", uPre = "u_", k, kPrefixed, v, ds = [], cs = [], iks = [], ivs = [], us = [], params = [], s;

        if unlikely count(this->primaryKey) < 1 {
            throw new Exception(__FUNCTION__, Exception::UPSERT_PK_EMPTY);
        }

        for k in this->primaryKey {
            if unlikely ! fetch v, inserts[k] || v === null {
                throw new Exception(k, Exception::UPSERT_PK_UNSATISFIED);
            }

            let ds[] = sprintf(":%s%s %s", iPre, k, k);
            let cs[] = sprintf("t1.%s = t2.%s", k, k);
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
            "MERGE INTO %s t1 USING (SELECT %s FROM dual WHERE rownum < 2) t2 ON (%s)",
            this->table,
            implode(", ", ds),
            implode(" AND ", cs)
        );

        if count(updates) > 0 {
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
                " WHEN MATCHED THEN UPDATE SET %s",
                implode(", ", us)
            );
        }

        let s .= sprintf(
            " WHEN NOT MATCHED THEN INSERT (%s) VALUES (%s)",
            implode(", ", iks),
            implode(", ", ivs)
        );

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
            "UPDATE %s SET %s WHERE (%s) IN (SELECT %s FROM %s%s%s where rownum <= %d)",
            this->table,
            implode(", ", us),
            pks,
            pks,
            this->table,
            this->makeWhere(where),
            this->makeOrder(order),
            limit
        );

        return this->db->execute(s, updates);
    }

    public function deleteTop(var where = "", var order = null, long limit = 1) -> long
    {
        var pks, s;

        let pks = implode(", ", this->primaryKey);

        let s = sprintf(
            "DELETE FROM %s WHERE (%s) IN (SELECT %s FROM %s%s%s where rownum <= %d)",
            this->table,
            pks,
            pks,
            this->table,
            this->makeWhere(where),
            this->makeOrder(order),
            limit
        );

        return this->db->execute(s);
    }

    protected function makeRandomOrder() -> string
    {
        return "dbms_random.value()";
    }

    protected function makePagination(string sql, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("SELECT t1.* FROM (%s) t1 WHERE rownum <= %d", sql, limit);
        }

        return sprintf(
            "SELECT * FROM (SELECT t1.*, rownum r FROM (%s) t1 WHERE rownum <= %d) t2 WHERE r > %d",
            sql,
            limit + skip,
            skip
        );
    }

}
