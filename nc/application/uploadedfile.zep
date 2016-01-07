namespace Nc\Application;

class UploadedFile
{
    protected error;
    protected size;
    protected name;
    protected tmpName;
    protected extension;

    public function __construct(long error, long size, string name, string tmpName) -> void
    {
        var eit;

        let this->error = error;
        let this->size = size;
        let this->name = name;
        let this->tmpName = tmpName;

        let eit = exif_imagetype(this->tmpName);
        if eit === false {
            let this->extension = strtolower(pathinfo(this->name, PATHINFO_EXTENSION));
        } else {
            let this->extension = image_type_to_extension(eit, false);
        }
    }

    public function getError() -> long
    {
        return this->error;
    }

    public function getSize() -> long
    {
        return this->size;
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function getTmpName() -> string
    {
        return this->tmpName;
    }

    public function getExtension() -> string
    {
        return this->extension;
    }

}
