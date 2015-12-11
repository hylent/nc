namespace Nc\Upload;

class UploadedFile
{
    public error;
    public size;
    public name;
    public extension;
    public tmpName;

    protected uploader;

    public function __construct(<Uploader> uploader) -> void
    {
        let this->uploader = uploader;
    }

    public function isValid() -> bool
    {
        return this->error === 0;
    }

    public function save(string prefix = "", bool keep = false) -> string
    {
        if unlikely this->error !== 0 {
            throw new Exception("Invalid uploaded file cannot be saved");
        }

        return this->uploader->saveUploadedFile(this, prefix, keep);
    }

}
