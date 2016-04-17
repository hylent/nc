namespace Nc\Db;

class PdoMysql extends PdoAbstract
{
    public function insert(string t, array data, string returningId = "", boolean upsert = false)
    {
        var s, r;

        let s = this->makeInsert(t, data);

        if upsert {
            let s = (string) preg_replace("/^INSERT /i", "REPLACE ", s);
        }

        this->execute(s, data);

        if returningId->length() > 0 {
            if fetch r, data[returningId] {
                return r;
            }

            return this->queryCell("SELECT LAST_INSERT_ID()");
        }
    }

    public function upsert(string t, array data, var primaryKey = "id") -> void
    {
        this->checkUpsert(data, primaryKey);
        this->insert(t, data, "", true);
    }

    public function countAndSelect(string t, array where = [], array options = []) -> array
    {
        var d;

        let d = this->query(preg_replace(
            "/^SELECT /i",
            "SELECT SQL_CALC_FOUND_ROWS ",
            this->makeSelect(t, where, options)
        ));

        return [
            (long) this->queryCell("SELECT FOUND_ROWS()"),
            d
        ];
    }

    protected function makeRandomOrder() -> string
    {
        return "RAND()";
    }

    protected function makePagination(string query, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("%s LIMIT %d", query, limit);
        }

        return sprintf("%s LIMIT %d, %d", query, skip, limit);
    }

}
