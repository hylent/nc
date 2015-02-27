namespace Nc\Filter;

use Nc\Storage\StorageInterface;
use Nc\Storage\StorageAwareInterface;

use Nc\Std;

class Uploader implements StorageAwareInterface
{
    const FILE_ARRAY_NOT_FOUND = 0x11;
    const FILE_ARRAY_MISSING_VALUE = 0x12;
    const SIZE_TOO_LARGE = 0x13;
    const EXTENSION_INVALID = 0x14;
    const STORAGE_FAILED = 0x15;

    protected storage;
    protected validExtensions;
    protected maxSize;

    protected lastError = 0;
    protected fileArray;

    public function __construct(string validExtensions, string maxSize = "2M") -> void
    {
        let this->validExtensions = array_flip(
            preg_split("@[,/\\s\\|]+@", validExtensions->lower(), -1, PREG_SPLIT_NO_EMPTY)
        );
        let this->maxSize = Std::sizeToByte(maxSize);
    }

    public function setStorage(<StorageInterface> storage) -> void
    {
        let this->storage = storage;
    }

    public function getStorage() -> <StorageInterface>
    {
        return this->storage;
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

        let uri = this->storage->store(tmpName, group, extension, ! reserveTmp);

        if unlikely ! uri {
            let this->lastError = self::STORAGE_FAILED;
            return;
        }

        let this->fileArray = fa;
        let this->fileArray["tmpName"] = tmpName;
        let this->fileArray["extension"] = extension;
        let this->fileArray["uri"] = uri;

        return uri;
    }

    public function lastError() -> long
    {
        return this->lastError;
    }

    public function fileArray() -> array
    {
        return this->fileArray;
    }

    public function __get(string name)
    {
        var value;

        if fetch value, this->fileArray[name] {
            return value;
        }
    }
}
