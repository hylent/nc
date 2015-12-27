namespace Nc\Storage;

class Fastdfs extends StorageAbstract
{
    protected prefixGroups;

    public function __construct(array prefixGroups = []) -> void
    {
        if unlikely ! extension_loaded("fastdfs_client") {
            throw new Exception("Missing extension: fastdfs_client");
        }

        let this->prefixGroups = prefixGroups;
    }

    public function store(string source, string prefix = "", string extension = "", long flag = 0) -> string
    {
        var extensionArg = null, groupArg, destUri;
        string fun = "fastdfs_storage_upload_by_filename1";

        if extension->length() > 0 {
            let extensionArg = extension;
        }
        if ! fetch groupArg, this->prefixGroups[prefix] {
            let groupArg = null;
        }

        let destUri = {fun}(source, extensionArg, [], groupArg);
        if unlikely destUri === false {
            throw new Exception("Cannot store file");
        }

        switch flag {
            case StorageAbstract::MOVE_UPLOADED_FILE:
            case StorageAbstract::MOVE:
                unlink(source);
                break;
        }

        return "/" . destUri;
    }

    public function remove(string uri) -> bool
    {
        string fun = "fastdfs_storage_delete_file1";
        return {fun}(ltrim(uri, "/"));
    }

    public function exists(string uri) -> bool
    {
        string fun = "fastdfs_storage_file_exist1";
        return {fun}(ltrim(uri, "/"));
    }

}
