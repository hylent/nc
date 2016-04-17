namespace Nc\Image;

class Image extends ImageAbstract
{
    public handler;
    public extension = "jpg";

    public function largest(long width, long height) -> <Image>
    {
        return this->backend->largest(this, width, height);
    }

    public function resize(long width, long height = 0) -> <Image>
    {
        return this->backend->resize(this, width, height);
    }

    public function crop(long x, long y, long w, long h = 0) -> <Image>
    {
        return this->backend->crop(this, x, y, w, h);
    }

    public function thumbnail(long width, long height = 0, boolean cropped = false) -> <Image>
    {
        return this->backend->thumbnail(this, width, height, cropped);
    }

    public function draw(<ImageAbstract> srcItem, long x = 0, long y = 0) -> <Image>
    {
        return this->backend->draw(this, srcItem, x, y);
    }

    public function drawAt(<ImageAbstract> srcItem, long position) -> <Image>
    {
        long x, y, w, h, srcW, srcH;

        let w = (long) this->width;
        let h = (long) this->height;
        let srcW = (long) srcItem->width;
        let srcH = (long) srcItem->height;

        switch position {
            case ImageBackendAbstract::LEFT_BOTTOM:
                let x = 0;
                let y = h - srcH;
                break;
            case ImageBackendAbstract::BOTTOM:
                let x = (w - srcW) / 2;
                let y = h - srcH;
                break;
            case ImageBackendAbstract::RIGHT_BOTTOM:
                let x = w - srcW;
                let y = h - srcH;
                break;
            case ImageBackendAbstract::LEFT:
                let x = 0;
                let y = (h - srcH) / 2;
                break;
            case ImageBackendAbstract::CENTER:
                let x = (w - srcW) / 2;
                let y = (h - srcH) / 2;
                break;
            case ImageBackendAbstract::RIGHT:
                let x = w - srcW;
                let y = (h - srcH) / 2;
                break;
            case ImageBackendAbstract::LEFT_TOP:
                let x = 0;
                let y = 0;
                break;
            case ImageBackendAbstract::TOP:
                let x = (w - srcW) / 2;
                let y = 0;
                break;
            case ImageBackendAbstract::RIGHT_TOP:
                let x = w - srcW;
                let y = 0;
                break;

            default:
                throw new Exception(sprintf("Invalid position '%d'", position));
        }

        return this->backend->draw(this, srcItem, x, y);
    }

    public function mimeType() -> string
    {
        return this->backend->mimeType(this);
    }

    public function save(string destPath) -> void
    {
        this->backend->save(this, destPath);
    }

    public function __toString() -> string
    {
        ob_start();
        ob_implicit_flush(false);

        try {
            this->backend->save(this, "");
            return ob_get_clean();
        } catch \Exception {
            ob_end_clean();
        }

        return "";
    }

}
