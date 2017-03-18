namespace Nc\Mvc;

class UploadedFile
{
    protected error;
    protected size;
    protected name;
    protected tmpName;

    protected extension = "";
    protected imageType = 0;

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
                if imageType == IMAGETYPE_JPEG {
                    let this->extension = "jpg";
                } else {
                    let this->extension = image_type_to_extension(imageType, false);
                }
                let this->imageType = imageType;
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

    public function getExtension() -> string
    {
        return this->extension;
    }

    public function getImageType() -> long
    {
        return this->imageType;
    }

    public function isImage() -> boolean
    {
        return this->imageType > 0;
    }

}
