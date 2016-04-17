namespace Nc\Storage;

class Fastdfs extends StorageAbstract
{
    protected prefixGroups;

    public function __construct(array prefixGroups = []) -> void
    {
        if unlikely ! extension_loaded("fastdfs_client") {
            throw new Exception("Missing extension 'fastdfs_client'");
        }

        let this->prefixGroups = prefixGroups;
    }

    public function store(string src, string pre = "", string ext = "", long type = StorageInterface::COPY) -> string
    {
        var extArg = null, groupArg, destUri;
        string fun = "fastdfs_storage_upload_by_filename1";

        if ext->length() > 0 {
            let extArg = ext;
        }
        if ! fetch groupArg, this->prefixGroups[pre] {
            let groupArg = null;
        }

        let destUri = {fun}(src, extArg, [], groupArg);
        if unlikely destUri === false {
            throw new Exception("Cannot store file");
        }

        switch type {
            case StorageAbstract::MOVE_UPLOADED_FILE:
            case StorageAbstract::MOVE:
                unlink(src);
                break;
        }

        return "/" . destUri;
    }

    public function remove(string uri) -> boolean
    {
        string fun = "fastdfs_storage_delete_file1";

        return {fun}(ltrim(uri, "/"));
    }

    public function exists(string uri) -> boolean
    {
        string fun = "fastdfs_storage_file_exist1";

        return {fun}(ltrim(uri, "/"));
    }

}
