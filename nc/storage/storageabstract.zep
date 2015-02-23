namespace Nc\Storage;

use Nc\Storage\Naming\StorageNamingInterface;
use Nc\Storage\Naming\StorageNamingAwareInterface;

abstract class StorageAbstract implements StorageInterface, StorageNamingAwareInterface
{
    protected storageNaming;

    public function setStorageNaming(<StorageNamingInterface> storageNaming) -> void
    {
        let this->storageNaming = storageNaming;
    }

    public function getStorageNaming() -> <StorageNamingInterface>
    {
        return this->storageNaming;
    }

    protected function generateUri(string source, string group, string extension) -> string
    {
        string uri = "/";

        if group && preg_match("#^\\w+(/\\w+)*$#", group) {
            let uri .= group . "/";
        }

        let uri .= this->storageNaming->generateName();

        if extension {
            let uri .= "." . extension;
        }

        return uri;
    }
}
