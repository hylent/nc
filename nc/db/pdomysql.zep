namespace Nc\Db;

class PdoMysql extends PdoAbstract
{
    public function insert(string table, array data, string returningId = "", bool upsert = false)
    {
        string sql;
        var returningIdValue;

        let sql = (string) this->insertSql(table, data);

        if upsert {
            let sql = (string) preg_replace("/^INSERT/i", "REPLACE", sql);
        }

        this->query(sql, data);

        if returningId->length() < 1 {
            return;
        }

        if fetch returningIdValue, data[returningId] {
            return (string) returningIdValue;
        }

        return this->query("SELECT LAST_INSERT_ID()", [], DbAbstract::CELL);
    }

    public function upsert(string table, array data, var primaryKey) -> void
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

    public function countAndSelect(string table, array options = [], long mode = DbAbstract::ALL) -> array
    {
        string s;
        var d;

        let s = (string) this->selectSql(table, options);
        let s = (string) preg_replace("/^SELECT /i", "SELECT SQL_CALC_FOUND_ROWS ", s);

        let d = this->query(s, [], mode);

        return [
            (long) this->query("SELECT FOUND_ROWS()", [], DbAbstract::CELL),
            d
        ];
    }

    public function paginationSql(string query, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("%s LIMIT %d", query, limit);
        }

        return sprintf("%s LIMIT %d, %d", query, skip, limit);
    }

    public function randomOrderSql() -> string
    {
        return "RAND()";
    }

}
