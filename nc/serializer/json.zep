namespace Nc\Serializer;

class Json implements SerializerInterface
{
    protected serializeFlag;
    protected unserializeToArray;

    public function __construct(long serializeFlag = 0, boolean unserializeToArray = true) -> void
    {
        let this->serializeFlag = serializeFlag;
        let this->unserializeToArray = unserializeToArray;
    }

    public function serialize(var data) -> string
    {
        return json_encode(data, this->serializeFlag);
    }

    public function unserialize(string str)
    {
        return json_decode(str, this->unserializeToArray);
    }
}
