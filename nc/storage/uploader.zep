namespace Nc\Storage;

use Nc\Storage\Backend\StorageBackendInterface;
use Nc\Storage\Backend\StorageBackendAwareInterface;

use Nc\Std;

class Uploader implements StorageBackendAwareInterface
{
    const FILE_ARRAY_NOT_FOUND = 0x1001;
    const FILE_ARRAY_MISSING_VALUE = 0x1002;
    const SIZE_TOO_LARGE = 0x1003;
    const EXTENSION_INVALID = 0x1004;
    const STORAGE_FAILED = 0x1005;

    protected storageBackend;
    protected validExtensions;
    protected maxSize;

    protected lastError = 0;
    protected fileArray;

    public function __construct(string validExtensions, string maxSize = "2M") -> void
    {
        let this->validExtensions = array_flip(explode(",", validExtensions->lower()));
        let this->maxSize = Std::sizeToByte(maxSize);
    }

    public function setStorageBackend(<StorageBackendInterface> storageBackend) -> void
    {
        let this->storageBackend = storageBackend;
    }

    public function getStorageBackend() -> <StorageBackendInterface>
    {
        return this->storageBackend;
    }

    public function upload(string index, string group = "", boolean reserveTmp = false)
    {
        var fa, error, tmpName, name, size, extension, uri;

        let this->lastError = 0;

        if unlikely ! fetch fa, _FILES[index] || typeof fa != "array" {
            let this->lastError = self::FILE_ARRAY_NOT_FOUND;
            return;
        }

        if unlikely ! fetch error, fa["error"] || ! fetch size, fa["size"]
            || ! fetch tmpName, fa["tmp_name"] || ! fetch name, fa["name"] {
            let this->lastError = self::FILE_ARRAY_MISSING_VALUE;
            return;
        }

        if unlikely error != 0 {
            let this->lastError = error;
            return;
        }

        if unlikely this->maxSize > 0 && size > this->maxSize {
            let this->lastError = self::SIZE_TOO_LARGE;
            return;
        }

        let extension = strtolower(pathinfo(name, PATHINFO_EXTENSION));
        if unlikely ! isset this->validExtensions[extension] {
            let this->lastError = self::EXTENSION_INVALID;
            return;
        }

        let uri = this->storageBackend->store(tmpName, group, extension, ! reserveTmp);

        if unlikely ! uri {
            let this->lastError = self::STORAGE_FAILED;
            return;
        }

        let this->fileArray = fa;
        let this->fileArray["extension"] = extension;
        let this->fileArray["uri"] = uri;

        return uri;
    }

    public function getLastError() -> long
    {
        return this->lastError;
    }

    public function __get(string name)
    {
        var value;
        string nameUncamelCase;

        let nameUncamelCase = (string) Std::uncamelCase(name, "_");
        if fetch value, this->fileArray[nameUncamelCase] {
            return value;
        }
    }
}
