namespace Nc\Application;

use Nc\Std;
use Nc\Storage\StorageAbstract;

class Uploader
{
    const INVALID_EXTENSION = -1;
    const INVALID_SIZE      = -2;

    protected validExtensions;
    protected maxSize;
    protected storage;

    public function __construct(string validExtensions, string maxSize = "2M") -> void
    {
        let this->validExtensions = array_flip(
            preg_split("#[,/\\s\\|\\.]+#", validExtensions->lower(), -1, PREG_SPLIT_NO_EMPTY)
        );

        let this->maxSize = Std::sizeToBytes(maxSize);
    }

    public function setStorage(<StorageAbstract> storage) -> void
    {
        let this->storage = storage;
    }

    public function getStorage() -> <StorageAbstract>
    {
        return this->storage;
    }

    public function save(<UploadedFile> uploadedFile, string prefix = "", bool keep = false) -> string
    {
        var error, size, tmpName, extension;
        long flag;

        let error = uploadedFile->getError();
        let size = uploadedFile->getSize();
        let tmpName = uploadedFile->getTmpName();
        let extension = uploadedFile->getExtension();

        if unlikely error !== 0 {
            throw new UploaderException("Invalid uploaded file with error: " . error, error);
        }

        if unlikely ! isset this->validExtensions[extension] {
            throw new UploaderException("Invalid uploaded file extension: " . extension, self::INVALID_EXTENSION);
        }

        if unlikely size < 1 || size > this->maxSize {
            throw new UploaderException("Invalid uploaded file size: " . size, self::INVALID_SIZE);
        }

        if keep {
            let flag = StorageAbstract::COPY;
        } else {
            let flag = StorageAbstract::MOVE_UPLOADED_FILE;
        }

        return this->storage->store(tmpName, prefix, extension, flag);
    }

}
