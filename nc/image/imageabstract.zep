namespace Nc\Image;

abstract class ImageAbstract implements ImageInterface
{
    protected width;
    protected height;
    protected extension;
    protected mimeType;

    public function byImage(<ImageInterface> im) -> <ImageInterface>
    {
        return this->byString(im->toString(), im->getExtension());
    }

    public function copy() -> <ImageInterface>
    {
        return this->byImage(this);
    }

    public function getWidth() -> long
    {
        return this->width;
    }

    public function getHeight() -> long
    {
        return this->height;
    }

    public function getExtension() -> string
    {
        return this->extension;
    }

    public function getMimeType() -> string
    {
        return this->mimeType;
    }

    public function __toString() -> string
    {
        try {
            return (string) this->toString();
        }

        return "";
    }

    protected function newInstance() -> <ImageInterface>
    {
        return (new \ReflectionClass(get_called_class()))->newInstanceWithoutConstructor();
    }

    protected function getPaintingAreaByPosition(long w, long h, long position) -> <Area>
    {
        var oriW, oriH, x, y;

        let oriW = (long) this->width;
        let oriH = (long) this->height;

        switch position {
            case ImageInterface::LEFT_BOTTOM:
                let x = 0;
                let y = oriH - h;
                break;
            case ImageInterface::BOTTOM:
                let x = (oriW - w) / 2;
                let y = oriH - h;
                break;
            case ImageInterface::RIGHT_BOTTOM:
                let x = oriW - w;
                let y = oriH - h;
                break;
            case ImageInterface::LEFT:
                let x = 0;
                let y = (oriH - h) / 2;
                break;
            case ImageInterface::CENTER:
                let x = (oriW - w) / 2;
                let y = (oriH - h) / 2;
                break;
            case ImageInterface::RIGHT:
                let x = oriW - w;
                let y = (oriH - h) / 2;
                break;
            case ImageInterface::LEFT_TOP:
                let x = 0;
                let y = 0;
                break;
            case ImageInterface::TOP:
                let x = (oriW - w) / 2;
                let y = 0;
                break;
            case ImageInterface::RIGHT_TOP:
                let x = oriW - w;
                let y = 0;
                break;

            default:
                throw new Exception(__FUNCTION__);
        }

        return new Area(x, y, w, h);
    }

}
