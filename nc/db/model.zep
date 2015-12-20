namespace Nc\Db;

class Model
{
    protected db;
    protected table;
    protected primaryKey;
    protected autoIncrement;

    public function __construct(<DbInterface> db, string table, var primaryKey, string autoIncrement) -> void
    {
        let this->db = db;
        let this->table = table;
        let this->primaryKey = primaryKey;
        let this->autoIncrement = autoIncrement;
    }

    public function setDb(<DbInterface> db) -> void
    {
        let this->db = db;
    }

    public function getDb() -> <DbInterface>
    {
        return this->db;
    }

    public function delete(array where = []) -> void
    {
        // cache write

        this->db->delete(this->table, where);
    }

    public function insert(array row) -> array
    {
        var r;
        string ai, aiValue;

        let r = this->onStore(row);
        let ai = (string) this->autoIncrement;

        if ai->length() > 0 && ! isset r[ai] {
            let aiValue = (string) this->db->insert(this->table, r, ai);
            let r[ai] = aiValue;
        } else {
            this->db->insert(this->table, r);
        }

        // cache drop

        return r;
    }

    public function update(array updates, array where = []) -> array
    {
        var r;

        let r = this->onStore(updates, true, where);
        if count(r) > 0 {
            this->db->update(this->table, r, where);
        }

        // cache drop

        return r;
    }

    public function newEntity(bool isNew, array row = [], <Collection> collection = null) -> <Entity>
    {
        return new Entity(this, isNew, row, collection);
    }

    public function entity(array newRow = []) -> <Entity>
    {
        return this->newEntity(true, newRow);
    }

    public function create(array row) -> <Entity>
    {
        return this->newEntity(false, this->insert(row));
    }

    public function first(array where = [], var orderBy = null, bool forUpdate = false) -> <Entity>
    {
        var row;

        let row = this->db->selectRow(this->table, [
            "where": where,
            "orderBy": orderBy,
            "limit": 1,
            "forUpdate": forUpdate
        ]);

        if ! row {
            return;
        }

        return this->newEntity(false, this->onFetch(row));
    }

    public function id(var id, bool forUpdate = false) -> <Entity>
    {
        return this->first(this->packPrimaryKeyValue(id), null, forUpdate);
    }

    public function newCollection(array data, array properties = []) -> <Collection>
    {
        return new Collection(this, data, properties);
    }

    public function find(array options = []) -> <Collection>
    {
        return this->newCollection(array_map([this, "onFetch"], this->db->select(this->table, options)));
    }

    public function all(array where = [], var orderBy = null, long limit = 0, long skip = 0) -> <Collection>
    {
        return this->find([
            "where": where,
            "orderBy": orderBy,
            "limit": limit,
            "skip": skip
        ]);
    }

    public function ids(array ids) -> <Collection>
    {
        string k;

        if typeof this->primaryKey == "array" {
            let k = (string) implode(", ", this->primaryKey);
        } else {
            let k = (string) this->primaryKey;
        }
        let k .= "$in";

        return this->all([k: ids]);
    }

    public function paged(array where = [], var orderBy = null, long limit = 10, long page = 1) -> <Collection>
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

        let nd = this->db->countAndSelect(this->table, [
            "where": where,
            "orderBy": orderBy,
            "limit": limit,
            "skip": skip
        ]);

        let numRows = (long) array_shift(nd);
        let data = (array) array_shift(nd);

        if numRows < 1 || count(data) < 1 {
            let numRows = 0;
            let numPages = 0;
            let data = [];
        } else {
            let numPages = 1 + (long) ((numRows - 1) / limit);
            let data = array_map([this, "onFetch"], data);
        }

        return this->newCollection(data, [
            "paged": true,
            "limit": limit,
            "page": page,
            "skip": skip,
            "numRows": numRows,
            "numPages": numPages
        ]);
    }

    public function chunkByDynamicWhere(var delegate, array where = [], var orderBy = null, long limit = 5000) -> long
    {
        var collection, w;
        long sum = 0, c;

        if unlikely limit < 1 {
            throw new ModelException("Invalid limit: " . strval(limit));
        }

        let w = where;

        loop {
            let collection = this->all(w, orderBy, limit);

            let c = (long) collection->count();
            if c < 1 {
                break;
            }

            let sum += c;
            let w = call_user_func(delegate, collection, w);
            if typeof w != "array" || count(w) < 1 || c < limit {
                break;
            }
        }

        return sum;
    }

    public function chunkByFixedWhere(var delegate, array where = [], var orderBy = null, long limit = 5000) -> long
    {
        var collection;
        long sum = 0, c, skip = 0;

        if unlikely limit < 1 {
            throw new ModelException("Invalid limit: " . strval(limit));
        }

        loop {
            let collection = this->all(where, orderBy, limit, skip);
            let c = (long) collection->count();
            if c < 1 {
                break;
            }

            let sum += c;
            if call_user_func(delegate, collection) === false || c < limit {
                break;
            }

            let skip += limit;
        }

        return sum;
    }

    public function countAll(array where = []) -> long
    {
        return this->count("*", where);
    }

    public function count(string column = "*", array where = []) -> long
    {
        return this->db->count(this->table, column, where);
    }

    public function max(string column, array where = [])
    {
        return this->db->max(this->table, column, where);
    }

    public function min(string column, array where = [])
    {
        return this->db->min(this->table, column, where);
    }

    public function sum(string column, array where = [])
    {
        return this->db->sum(this->table, column, where);
    }

    public function avg(string column, array where = [])
    {
        return this->db->avg(this->table, column, where);
    }

    public function aggregation(string aggregationFunction, string column, array where = [])
    {
        return this->db->aggregation(this->table, aggregationFunction, column, where);
    }

    public function aggregations(array aggregations, array where = []) -> array
    {
        return this->db->aggregations(this->table, aggregations, where);
    }

    public function groupAggregations(string groupBy, array aggregations, array options = []) -> array
    {
        return this->db->groupAggregations(this->table, groupBy, aggregations, options);
    }

    public function onStore(array row, bool isUpdate = false, array where = []) -> array
    {
        return row;
    }

    public function onFetch(array row) -> array
    {
        return row;
    }

    public function pickPrimaryKeyValue(array row) -> array
    {
        var pk, k, v, a = [];

        let pk = this->primaryKey;

        if unlikely ! pk {
            throw new ModelException("Empty primary key");
        }

        if typeof pk == "array" {
            for k in pk {
                if unlikely ! fetch v, row[k] {
                    throw new ModelException("Cannot pick primary key values: " . k);
                }
                let a[k] = v;
            }
        } else {
            let k = (string) pk;
            if unlikely ! fetch v, row[k] {
                throw new ModelException("Cannot pick primary key value: " . k);
            }
            let a[k] = v;
        }

        return a;
    }

    public function packPrimaryKeyValue(var id) -> array
    {
        var pk, a;

        let pk = this->primaryKey;

        if unlikely ! pk {
            throw new ModelException("Empty primary key");
        }

        if typeof pk == "array" {
            if unlikely typeof id != "array" || count(id) != count(pk) {
                throw new ModelException("Invalid id to pack");
            }

            return array_combine(pk, id);
        }

        let a = [];
        let a[(string) pk] = (string) id;

        return a;
    }

}
