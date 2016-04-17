namespace Nc\Sequence;

class MongoCollection extends SequenceBackendAbstract
{
    protected mongoCollection;

    public function __construct(var mongoCollection) -> void
    {
        let this->mongoCollection = mongoCollection;
    }

    public function getMongoCollection()
    {
        return this->mongoCollection;
    }

    public function next(string name) -> long
    {
        var r, s;

        let r = this->mongoCollection->findAndModify([
            "_id": name
        ], [
            "$inc": [
                "sequence": 1
            ]
        ], null, [
            "upsert": true,
            "new": true
        ]);

        if unlikely typeof r != "array" || ! fetch s, r["sequence"] {
            throw new Exception(sprintf("Cannot get next sequence of '%s'", name));
        }

        return (long) s;
    }

    public function restore(string name, long sequence) -> void
    {
        this->mongoCollection->insert([
            "_id": name
        ], [
            "$set": [
                "sequence": sequence
            ]
        ], [
            "upsert": true
        ]);
    }

    public function clear() -> void
    {
        this->mongoCollection->drop();
    }

}
