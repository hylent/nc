namespace Nc\Db;

class PdoPgsql extends PdoAbstract
{
    public function upsert(string table, array data, var primaryKey = "id") -> void
    {
        var where, k, ks = [], vs = [], os = [], us = [];
        string s;

        let where = this->pickWhereByKey(data, primaryKey);
        if unlikely count(where) < 1 {
            throw new Exception("Cannot upsert with empty where");
        }

        for k, _ in data {
            let ks[] = k;
            let vs[] = ":" . k;

            if isset where[k] {
                let os[] = k;
            } else {
                let us[] = k . " = EXCLUDED." . k;
            }
        }

        let s = "INSERT INTO " . table . " (" . implode(", ", ks) . ") VALUES (" . implode(", ", vs) . ")";
        if count(us) > 0 {
            let s .= " ON CONFLICT (" . implode(", ", os) . ") DO UPDATE SET " . implode(", ", us);
        } else {
            let s .= " ON CONFLICT (" . implode(", ", os) . ") DO NOTHING";
        }

        this->query(s, data);
    }

    public function parsePagination(string query, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("%s LIMIT %d", query, limit);
        }

        return sprintf("%s LIMIT %d OFFSET %d", query, limit, skip);
    }

    public function parseRandomOrder() -> string
    {
        return "RANDOM()";
    }

}
