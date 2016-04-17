namespace Nc\Storage;

class FileSystem extends StorageAbstract
{
    protected baseDirectory;
    protected mode;

    public function __construct(string baseDirectory, long mode = 0777) -> void
    {
        let this->baseDirectory = baseDirectory;
        let this->mode = mode;
    }

    public function getBaseDirectory() -> string
    {
        return this->baseDirectory;
    }

    public function getMode() -> long
    {
        return this->mode;
    }

    public function getPath(string uri) -> string
    {
        return this->baseDirectory . uri;
    }

    public function store(string src, string pre = "", string ext = "", long type = StorageInterface::COPY) -> string
    {
        var temp, success;
        string destUri, destPath;

        let destUri = (string) this->generateUri(src, pre, ext);
        let destPath = this->baseDirectory . destUri;

        let temp = dirname(destPath);
        if unlikely ! is_dir(temp) && ! mkdir(temp, this->mode, true) {
            throw new Exception("Cannot mkdir: " . temp);
        }

        switch type {
            case StorageAbstract::MOVE_UPLOADED_FILE:
                let success = move_uploaded_file(src, destPath);
                break;

            case StorageAbstract::MOVE:
                let success = rename(src, destPath);
                break;

            default:
                let success = copy(src, destPath);
                break;
        }

        if unlikely ! success {
            throw new Exception("Cannot store file to path: " . destPath);
        }

        return destUri;
    }

    public function remove(string uri) -> boolean
    {
        var path;

        let path = this->getPath(uri);
        if file_exists(path) {
            return unlink(path);
        }

        return false;
    }

    public function exists(string uri) -> boolean
    {
        return file_exists(this->getPath(uri));
    }

}
