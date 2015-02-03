namespace Nc\Storage\Backend;

interface StorageBackendAwareInterface
{
    public function setStorageBackend(<StorageBackendInterface> storageBackend) -> void;
    public function getStorageBackend() -> <StorageBackendInterface>;
}
