namespace Nc\Serializer;

interface SerializerInterface
{
    public function serialize(var data) -> string;
    public function unserialize(string str);
}
