namespace Nc\Storage;

interface StorageAwareInterface
{
    public function setStorage(<StorageInterface> storage) -> void;
    public function getStorage() -> <StorageInterface>;
}
