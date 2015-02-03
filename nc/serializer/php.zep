namespace Nc\Serializer;

class Php implements SerializerInterface
{
    public function serialize(var data) -> string
    {
        return serialize(data);
    }

    public function unserialize(string str)
    {
        return unserialize(str);
    }
}
