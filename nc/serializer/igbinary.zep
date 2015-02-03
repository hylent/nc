namespace Nc\Serializer;

class Igbinary implements SerializerInterface
{
    public function __construct() -> void
    {
        if unlikely ! function_exists("igbinary_serialize") {
            throw new Exception("Missing extension: igbinary");
        }
    }

    public function serialize(var data) -> string
    {
        return igbinary_serialize(data);
    }

    public function unserialize(string str)
    {
        return igbinary_unserialize(str);
    }
}
