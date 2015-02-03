namespace Nc\Storage\Backend;

class FileSystem extends StorageBackendAdapter
{
    protected baseDirectory;

    public function __construct(string baseDirectory) -> void
    {
        let this->baseDirectory = baseDirectory;
    }

    public function store(string source, string group = "", string extension = "", boolean mv = false) -> string
    {
        var temp, success;
        string destUri, destPath;

        let destUri = (string) this->generateUri(source, group, extension);
        let destPath = this->baseDirectory . destUri;

        let temp = dirname(destPath);
        if unlikely ! is_dir(temp) && ! mkdir(temp, 0755, true) {
            throw new Exception("Cannot mkdir: " . temp);
        }

        if mv {
            let success = rename(source, destPath);
        } else {
            let success = copy(source, destPath);
        }

        if success {
            return destUri;
        }

        return "";
    }

    public function remove(string uri) -> boolean
    {
        var path;

        let path = this->baseDirectory . uri;
        if file_exists(path) {
            return unlink(path);
        }

        return false;
    }
}
