namespace Nc\Application;

class UploadedFile
{
    protected error;
    protected size;
    protected name;
    protected tmpName;
    protected extension;

    public function __construct(long error, long size, string name, string tmpName, string extension) -> void
    {
        let this->error = error;
        let this->size = size;
        let this->name = name;
        let this->tmpName = tmpName;
        let this->extension = extension;
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
