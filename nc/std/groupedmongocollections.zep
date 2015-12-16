namespace Nc\Std;

class GroupedMongoCollections implements GroupedInterface
{
    const DEFAULT_PREFIX = "grouped_";

    protected mongoDb;
    protected prefix;

    public function __construct(var mongoDb, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->mongoDb = mongoDb;
        let this->prefix = prefix;
    }

    public function setGrouped(string identifier, string key, var value) -> void
    {
        this->collection(identifier)->update([
            "_id": key
        ], [
            "$set": [
                "value": value
            ]
        ], [
            "upsert": true
        ]);
    }

    public function getGrouped(string identifier, string key)
    {
        var row, value;

        let row = this->collection(identifier)->findOne([
            "_id": key
        ]);

        if typeof row == "array" && fetch value, row["value"] {
            return value;
        }
    }

    public function deleteGrouped(string identifier, string key) -> void
    {
        this->collection(identifier)->remove([
            "_id": key
        ]);
    }

    public function setManyGrouped(string identifier, array keyValues) -> void
    {
        var k, v;

        for k, v in keyValues {
            this->setGrouped(identifier, k, v);
        }
    }

    public function getManyGrouped(string identifier, array keys) -> array
    {
        var rows, row, a = [], k, v;

        if unlikely count(keys) < 1 {
            return a;
        }

        let rows = this->collection(identifier)->find([
            "_id": [
                "$in": keys
            ]
        ]);

        for row in iterator_to_array(rows) {
            if fetch k, row["_id"] {
                if fetch v, row["value"] {
                    let a[k] = v;
                }
            }
        }

        return a;
    }

    public function deleteManyGrouped(string identifier, array keys) -> void
    {
        this->collection(identifier)->remove([
            "_id": [
                "$in": keys
            ]
        ]);
    }

    public function setAllGrouped(string identifier, array keyValues) -> void
    {
        this->deleteAllGrouped(identifier);
        this->setManyGrouped(identifier, keyValues);
    }

    public function getAllGrouped(string identifier) -> array
    {
        var rows, row, a = [], k, v;

        let rows = this->collection(identifier)->find();

        for row in iterator_to_array(rows) {
            if fetch k, row["_id"] {
                if fetch v, row["value"] {
                    let a[k] = v;
                }
            }
        }

        return a;
    }

    public function deleteAllGrouped(string identifier) -> void
    {
        this->collection(identifier)->drop();
    }

    protected function collection(string identifier)
    {
        return this->mongoDb->selectCollection(this->prefix . identifier);
    }

}
