namespace Nc\Storage\Backend;

use Nc\Storage\NamePolicy\StorageNamePolicyInterface;
use Nc\Storage\NamePolicy\StorageNamePolicyAwareInterface;

abstract class StorageBackendAdapter implements StorageBackendInterface, StorageNamePolicyAwareInterface
{
    protected storageNamePolicy;

    public function setStorageNamePolicy(<StorageNamePolicyInterface> storageNamePolicy) -> void
    {
        let this->storageNamePolicy = storageNamePolicy;
    }

    public function getStorageNamePolicy() -> <StorageNamePolicyInterface>
    {
        return this->storageNamePolicy;
    }

    protected function generateUri(string source, string group, string extension) -> string
    {
        string uri = "/";

        if group && preg_match("#^\\w+(/\\w+)*$#", group) {
            let uri .= group . "/";
        }

        let uri .= this->storageNamePolicy->generateName();

        if extension {
            let uri .= "." . extension;
        }

        return uri;
    }
}
