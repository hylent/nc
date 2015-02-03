namespace Nc\Serializer;

interface SerializerAwareInterface
{
    public function setSerializer(<SerializerInterface> serializer) -> void;
    public function getSerializer() -> <SerializerInterface>;
}
