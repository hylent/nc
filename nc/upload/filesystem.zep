namespace Nc\Upload;

class FileSystem extends StorageAbstract
{
    protected baseDirectory;

    public function __construct(string baseDirectory) -> void
    {
        let this->baseDirectory = baseDirectory;
    }

    public function store(string source, string prefix = "", string extension = "", long flag = 0) -> string
    {
        var temp, success;
        string destUri, destPath;

        let destUri = (string) this->generateUri(source, prefix, extension);
        let destPath = this->baseDirectory . destUri;

        let temp = dirname(destPath);
        if unlikely ! is_dir(temp) && ! mkdir(temp, 0755, true) {
            throw new Exception("Cannot mkdir: " . temp);
        }

        switch flag {
            case StorageAbstract::MOVE_UPLOADED_FILE:
                let success = move_uploaded_file(source, destPath);
                break;

            case StorageAbstract::MOVE:
                let success = rename(source, destPath);
                break;

            default:
                let success = copy(source, destPath);
                break;
        }

        if success {
            return destUri;
        }

        return "";
    }

    public function remove(string uri) -> bool
    {
        var path;

        let path = this->baseDirectory . uri;
        if file_exists(path) {
            return unlink(path);
        }

        return false;
    }

    public function exists(string uri) -> bool
    {
        return file_exists(this->baseDirectory . uri);
    }

}
