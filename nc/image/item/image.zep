namespace Nc\Image\Item;

use Nc\Image\ImageInterface;

class Image extends ImageItemAbstract
{
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

    public function draw(<ImageItemAbstract> srcItem, long x = 0, long y = 0) -> <Image>
    {
        return this->backend->draw(this, srcItem, x, y);
    }

    public function drawTo(<ImageItemAbstract> srcItem, long position) -> <Image>
    {
        long x, y, w, h, srcW, srcH;

        let w = (long) this->{"width"};
        let h = (long) this->{"height"};
        let srcW = (long) srcItem->{"width"};
        let srcH = (long) srcItem->{"height"};

        switch position {
            case ImageInterface::LEFT_BOTTOM:
                let x = 0;
                let y = h - srcH;
                break;
            case ImageInterface::BOTTOM:
                let x = (w - srcW) / 2;
                let y = h - srcH;
                break;
            case ImageInterface::RIGHT_BOTTOM:
                let x = w - srcW;
                let y = h - srcH;
                break;
            case ImageInterface::LEFT:
                let x = 0;
                let y = (h - srcH) / 2;
                break;
            case ImageInterface::CENTER:
                let x = (w - srcW) / 2;
                let y = (h - srcH) / 2;
                break;
            case ImageInterface::RIGHT:
                let x = w - srcW;
                let y = (h - srcH) / 2;
                break;
            case ImageInterface::LEFT_TOP:
                let x = 0;
                let y = 0;
                break;
            case ImageInterface::TOP:
                let x = (w - srcW) / 2;
                let y = 0;
                break;
            case ImageInterface::RIGHT_TOP:
                let x = w - srcW;
                let y = 0;
                break;

            default:
                throw new Exception("Invalid position: " . position);
        }

        return this->backend->draw(this, srcItem, x, y);
    }

    public function save(var destPath) -> void
    {
        this->backend->save(this, destPath);
    }

    public function __toString() -> string
    {
        ob_start();
        ob_implicit_flush(false);

        try {
            this->save(null);
            return ob_get_clean();
        } catch \Exception {
            ob_end_clean();
        }

        return "";
    }
}
