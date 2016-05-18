namespace Nc\Db;

class DaoBase
{
    protected db;
    protected table;
    protected primaryKey;
    protected condition;

    public function __construct(<DbInterface> db, string table, var primaryKey = "id", array condition = []) -> void
    {
        let this->db = db;
        let this->table = table;
        let this->primaryKey = primaryKey;
        let this->condition = condition;
    }

    public function select(array where = [], array options = [])
    {
        return this->db->select(this->table, array_merge(this->condition, where), options);
    }

    public function selectRow(array where = [], array options = [])
    {
        return this->db->selectRow(this->table, array_merge(this->condition, where), options);
    }

    public function selectCell(array where = [], array options = [])
    {
        return this->db->selectCell(this->table, array_merge(this->condition, where), options);
    }

    public function selectColumns(array where = [], array options = [])
    {
        return this->db->selectColumns(this->table, array_merge(this->condition, where), options);
    }

    public function countAndSelect(array where = [], array options = []) -> array
    {
        return this->db->countAndSelect(this->table, array_merge(this->condition, where), options);
    }

    public function group(string groupBy, array aggrs, array where = [], array options = []) -> array
    {
        return this->db->group(this->table, groupBy, aggrs, array_merge(this->condition, where), options);
    }

    public function aggregations(array aggrs, array where = []) -> array
    {
        return this->db->aggregations(this->table, aggrs, array_merge(this->condition, where));
    }

    public function aggregation(string aggrFunction, string column, array where = []) -> string
    {
        return this->db->aggregation(this->table, aggrFunction, column, array_merge(this->condition, where));
    }

    public function countAll(array where = []) -> long
    {
        return this->db->countAll(this->table, array_merge(this->condition, where));
    }

    public function count(string column, array where = []) -> long
    {
        return this->db->count(this->table, column, array_merge(this->condition, where));
    }

    public function max(string column, array where = [])
    {
        return this->db->max(this->table, column, array_merge(this->condition, where));
    }

    public function min(string column, array where = [])
    {
        return this->db->min(this->table, column, array_merge(this->condition, where));
    }

    public function sum(string column, array where = [])
    {
        return this->db->sum(this->table, column, array_merge(this->condition, where));
    }

    public function avg(string column, array where = [])
    {
        return this->db->avg(this->table, column, array_merge(this->condition, where));
    }

    public function first(array where = [], var orderBy = null, boolean forUpdate = false)
    {
        return this->selectRow(where, [
            "orderBy": orderBy,
            "limit": 1,
            "forUpdate": forUpdate
        ]);
    }

    public function find(array where = [], var orderBy = null, long limit = 0, long skip = 0) -> array
    {
        return this->select(where, [
            "orderBy": orderBy,
            "limit": limit,
            "skip": skip
        ]);
    }

    public function paged(array where = [], var orderBy = null, long limit = 10, long page = 1) -> array
    {
        long skip, numRows, numPages;
        var nd, data;

        if limit < 1 {
            let limit = 1;
        }
        if page < 1 {
            let page = 1;
        }

        let skip = limit * (page - 1);

        let nd = this->countAndSelect(where, [
            "orderBy": orderBy,
            "limit": limit,
            "skip": skip
        ]);

        let numRows = (long) array_shift(nd);
        let data = array_shift(nd);

        if unlikely typeof data != "array" {
            throw new DaoException("Invalid result returned");
        }

        if numRows < 1 || count(data) < 1 {
            let numPages = 0;
        } else {
            let numPages = 1 + (long) ((numRows - 1) / limit);
        }

        return [
            "limit": limit,
            "page": page,
            "skip": skip,
            "numRows": numRows,
            "numPages": numPages,
            "data": data
        ];
    }

    public function chunk(var cb, array where = [], var orderBy = null, long limit = 5000) -> long
    {
        var collection;
        long sum = 0, c, skip = 0;

        if unlikely limit < 1 {
            throw new DaoException(sprintf("Invalid limit '%d'", limit));
        }

        loop {
            let collection = this->find(where, orderBy, limit, skip);
            let c = count(collection);
            if c < 1 {
                break;
            }

            let sum += c;
            if call_user_func(cb, collection) === false || c < limit {
                break;
            }

            let skip += limit;
        }

        return sum;
    }

    public function chunkDynamicly(var cb, array where = [], var orderBy = null, long limit = 5000) -> long
    {
        var collection, w;
        long sum = 0, c;

        if unlikely limit < 1 {
            throw new DaoException(sprintf("Invalid limit '%d'", limit));
        }

        let w = where;

        loop {
            let collection = this->find(w, orderBy, limit);
            let c = count(collection);
            if c < 1 {
                break;
            }

            let sum += c;
            let w = call_user_func(cb, collection, w);
            if typeof w != "array" || count(w) < 1 || c < limit {
                break;
            }
        }

        return sum;
    }

}
