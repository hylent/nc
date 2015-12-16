namespace Nc\Std;

class SequenceMongoCollection implements SequenceInterface
{
    protected mongoCollection;

    public function __construct(var mongoCollection) -> void
    {
        let this->mongoCollection = mongoCollection;
    }

    public function getNextSequence(string identifier) -> long
    {
        var r, s;

        let r = this->mongoCollection->findAndModify([
            "_id": identifier
        ], [
            "$inc": [
                "sequence": 1
            ]
        ], null, [
            "upsert": true,
            "new": true
        ]);

        if unlikely typeof r != "array" || ! fetch s, r["sequence"] {
            throw new Exception("Cannot get next sequence of: " . identifier);
        }

        return (long) s;
    }

    public function restoreSequence(string identifier, long sequence) -> void
    {
        this->mongoCollection->insert([
            "_id": identifier
        ], [
            "$set": [
                "sequence": sequence
            ]
        ], [
            "upsert": true
        ]);
    }

}
