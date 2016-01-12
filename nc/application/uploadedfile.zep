namespace Nc\Application;

class UploadedFile
{
    protected error;
    protected size;
    protected name;
    protected tmpName;

    protected imageType = 0;
    protected extension = "";

    public function __construct(long error, long size, string name, string tmpName) -> void
    {
        var imageType;

        let this->error = error;
        let this->size = size;
        let this->name = name;
        let this->tmpName = tmpName;

        if error == UPLOAD_ERR_OK {
            let imageType = exif_imagetype(tmpName);
            if imageType === false {
                let this->extension = strtolower(pathinfo(name, PATHINFO_EXTENSION));
            } else {
                let this->imageType = imageType;
                if imageType == IMAGETYPE_JPEG {
                    let this->extension = "jpg";
                } else {
                    let this->extension = image_type_to_extension(imageType, false);
                }
            }
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

    public function getImageType() -> long
    {
        return this->imageType;
    }

    public function getExtension() -> string
    {
        return this->extension;
    }

}
