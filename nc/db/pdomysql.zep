namespace Nc\Db;

class PdoMysql extends PdoAbstract
{
    public function insert(string table, array data, string returningId = "", bool upsert = false)
    {
        var k, ks = [], vs = [];
        string s;
        var returningIdValue;

        for k, _ in data {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        if upsert {
            let s = "REPLACE";
        } else {
            let s = "INSERT";
        }

        let s .= " INTO " . table . " (" . implode(", ", ks) . ") VALUES (" . implode(", ", vs) . ")";

        this->query(s, data);

        if returningId->length() < 1 {
            return;
        }

        if fetch returningIdValue, data[returningId] {
            return (string) returningIdValue;
        }

        return this->queryCell("SELECT LAST_INSERT_ID()");
    }

    public function upsert(string table, array data, var primaryKey = "id") -> void
    {
        var k;

        if typeof primaryKey == "array" {
            if unlikely ! primaryKey {
                throw new Exception("Cannot upsert with empty where");
            }
            for k in primaryKey {
                if unlikely ! isset data[k] {
                    throw new Exception("Cannot find primary key value in data: " . k);
                }
            }
        } else {
            let k = (string) primaryKey;
            if unlikely ! isset data[k] {
                throw new Exception("Cannot find primary key value in data: " . k);
            }
        }

        this->insert(table, data, "", true);
    }

    public function countAndSelect(string table, array options = [], long $fetch = DbInterface::ALL) -> array
    {
        string s;
        var d;

        let s = (string) this->parseSelect(table, options);
        let s = (string) preg_replace("/^SELECT /i", "SELECT SQL_CALC_FOUND_ROWS ", s);

        let d = this->queryAndFetch($fetch, s);

        return [
            (long) this->queryCell("SELECT FOUND_ROWS()"),
            d
        ];
    }

    public function parsePagination(string query, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("%s LIMIT %d", query, limit);
        }

        return sprintf("%s LIMIT %d, %d", query, skip, limit);
    }

    public function parseRandomOrder() -> string
    {
        return "RAND()";
    }

}
