namespace Nc\Db;

class PdoPgsql extends PdoAbstract
{
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
