namespace Nc\Storage\NamePolicy;

interface StorageNamePolicyAwareInterface
{
    public function setStorageNamePolicy(<StorageNamePolicyInterface> storageNamePolicy) -> void;
    public function getStorageNamePolicy() -> <StorageNamePolicyInterface>;
}
