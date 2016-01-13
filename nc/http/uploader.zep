namespace Nc\Http;

use Nc\Std;
use Nc\Storage\StorageAbstract;

class Uploader
{
    const INVALID_EXTENSION = -1;
    const INVALID_SIZE      = -2;

    protected imageExtensions;
    protected otherExtensions;
    protected maxSize;

    protected storage;

    public function __construct(string imageExtensions, string otherExtensions = "", string maxSize = "2M") -> void
    {
        string pattern = "#[,/\\s\\|\\.]+#";

        let this->imageExtensions = array_flip(
            preg_split(pattern, imageExtensions->lower(), -1, PREG_SPLIT_NO_EMPTY)
        );

        let this->otherExtensions = array_flip(
            preg_split(pattern, otherExtensions->lower(), -1, PREG_SPLIT_NO_EMPTY)
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

        loop {
            if uploadedFile->isImage() {
                if isset this->imageExtensions[extension] {
                    break;
                }
            } else {
                if isset this->otherExtensions[extension] {
                    break;
                }
            }
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
