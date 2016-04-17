namespace Nc\Db;

class PdoPgsql extends PdoAbstract
{
    public function upsert(string t, array data, var primaryKey = "id") -> void
    {
        var pks, k, ks = [], vs = [], os = [], us = [], s;

        let pks = this->checkUpsert(data, primaryKey);

        for k, _ in data {
            let ks[] = k;
            let vs[] = ":" . k;

            if isset pks[k] {
                let os[] = k;
            } else {
                let us[] = k . " = EXCLUDED." . k;
            }
        }

        let s = "INSERT INTO " . t . " (" . implode(", ", ks) . ") VALUES (" . implode(", ", vs) . ")";
        if count(us) > 0 {
            let s .= " ON CONFLICT (" . implode(", ", os) . ") DO UPDATE SET " . implode(", ", us);
        } else {
            let s .= " ON CONFLICT (" . implode(", ", os) . ") DO NOTHING";
        }

        this->execute(s, data);
    }

    protected function makeRandomOrder() -> string
    {
        return "RANDOM()";
    }

    protected function makePagination(string query, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("%s LIMIT %d", query, limit);
        }

        return sprintf("%s LIMIT %d OFFSET %d", query, limit, skip);
    }

}
