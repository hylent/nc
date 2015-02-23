namespace Nc\Storage\Naming;

interface StorageNamingAwareInterface
{
    public function setStorageNaming(<StorageNamingInterface> storageNaming) -> void;
    public function getStorageNaming() -> <StorageNamingInterface>;
}
