namespace Nc\Db;

class Model
{
    protected db;
    protected table;
    protected primaryKey;
    protected autoIncrement;

    public function __construct(<DbAbstract> db, string table, var primaryKey, string autoIncrement) -> void
    {
        let this->db = db;
        let this->table = table;
        let this->primaryKey = primaryKey;
        let this->autoIncrement = autoIncrement;
    }

    public function setDb(<DbAbstract> db) -> void
    {
        let this->db = db;
    }

    public function getDb() -> <DbAbstract>
    {
        return this->db;
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

    public function delete(array where = []) -> void
    {
        // cache write

        this->db->delete(this->table, where);
    }

    public function newEntity(array row = [], bool isNew = true, <Collection> collection = null) -> <Entity>
    {
        var entity;

        let entity = new Entity(this, row, isNew);
        if collection {
            entity->setCollection(collection);
        }

        return entity;
    }

    public function create(array row) -> <Entity>
    {
        return this->newEntity(this->insert(row), false);
    }

    public function first(array where = [], var orderBy = null) -> <Entity>
    {
        var row;

        let row = this->db->select(this->table, [
            "where": where,
            "orderBy": orderBy,
            "limit": 1
        ], DbAbstract::ROW);

        if ! row {
            return;
        }

        return this->newEntity(this->onFetch(row), false);
    }

    public function id(var id) -> <Entity>
    {
        return this->first(this->packPrimaryKeyValue(id));
    }

    public function newCollection(array data) -> <Collection>
    {
        return new Collection(this, data);
    }

    public function all(array where = [], var orderBy = null, long limit = 0, long offset = 0) -> <Collection>
    {
        return this->newCollection(array_map([this, "onFetch"], this->db->select(this->table, [
            "where": where,
            "orderBy": orderBy,
            "limit": limit,
            "offset": offset
        ])));
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

    public function chunkByDynamicWhere(var delegate, array where = [], var orderBy = null, long limit = 5000) -> long
    {
        var collection, w;
        long sum = 0, c;

        if unlikely limit < 1 {
            throw new Exception("Invalid limit");
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
        long sum = 0, c, offset = 0;

        if unlikely limit < 1 {
            throw new Exception("Invalid limit");
        }

        loop {
            let collection = this->all(where, orderBy, limit, offset);
            let c = (long) collection->count();
            if c < 1 {
                break;
            }

            let sum += c;
            if call_user_func(delegate, collection) === false || c < limit {
                break;
            }

            let offset += limit;
        }

        return sum;
    }

    public function aggregation(array aggregations, array where = []) -> array
    {
        return this->db->queryAggregation(this->table, aggregations, where);
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
            throw new Exception("Empty primary key");
        }

        if typeof pk == "array" {
            for k in pk {
                if unlikely ! fetch v, row[k] {
                    throw new Exception("Cannot pick primary key values: " . k);
                }
                let a[k] = v;
            }
        } else {
            let k = (string) pk;
            if unlikely ! fetch v, row[k] {
                throw new Exception("Cannot pick primary key value: " . k);
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
            throw new Exception("Empty primary key");
        }

        if typeof pk == "array" {
            if unlikely typeof id != "array" || count(id) != count(pk) {
                throw new Exception("Invalid id to pack");
            }

            return array_combine(pk, id);
        }

        let a = [];
        let a[(string) pk] = (string) id;

        return a;
    }

}
