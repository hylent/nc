namespace Nc\Image;

class Gd extends ImageAbstract
{
    protected handler;

    public function __construct() -> void
    {
        if unlikely ! extension_loaded("gd") {
            throw new Exception(__FUNCTION__);
        }
    }

    public function bySize(long w, long h = 0, string extension = "png") -> <ImageInterface>
    {
        var handler, bgColor;

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let handler = imagecreatetruecolor(w, h);

        if unlikely ! handler {
            throw new Exception(__FUNCTION__);
        }

        imagealphablending(handler, true);
        imagesavealpha(handler, true);

        let bgColor = imagecolorallocatealpha(handler, 255, 255, 255, 127);
        imagecolortransparent(handler, bgColor);
        imagefill(handler, 0, 0, bgColor);

        return this->newImage(handler, extension);
    }

    public function byString(string data, string extension = "png") -> <ImageInterface>
    {
        var handler;

        if unlikely data->length() < 1 {
            throw new Exception(__FUNCTION__);
        }

        let handler = imagecreatefromstring(data);
        if unlikely ! handler {
            throw new Exception(__FUNCTION__);
        }

        imagealphablending(handler, true);
        imagesavealpha(handler, true);

        return this->newImage(handler, extension);
    }

    public function byPath(string path) -> <ImageInterface>
    {
        var eit, handler, extension;

        if unlikely ! file_exists(path) {
            throw new Exception(__FUNCTION__);
        }

        let eit = exif_imagetype(path);

        if unlikely eit === false {
            throw new Exception(__FUNCTION__);
        }

        switch eit {
            case IMAGETYPE_JPEG:
                let handler     = imagecreatefromjpeg(path);
                let extension   = "jpg";
                break;
            case IMAGETYPE_PNG:
                let handler     = imagecreatefrompng(path);
                let extension   = "png";
                break;
            case IMAGETYPE_GIF:
                let handler     = imagecreatefromgif(path);
                let extension   = "gif";
                break;

            default:
                throw new Exception(__FUNCTION__);
        }

        if unlikely ! handler {
            throw new Exception(__FUNCTION__);
        }

        imagealphablending(handler, true);
        imagesavealpha(handler, true);

        return this->newImage(handler, extension);
    }

    public function copy() -> <ImageInterface>
    {
        var dstIm;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        let dstIm = this->bySize(this->width, this->height, this->extension);

        if unlikely ! imagecopy(
            dstIm->handler,
            this->handler,
            0,
            0,
            0,
            0,
            this->width,
            this->height
        ) {
            throw new Exception(__FUNCTION__);
        }

        return dstIm;
    }

    public function resample(long w, long h, <Area> dstArea, <Area> srcArea) -> <ImageInterface>
    {
        var dstIm;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        let dstIm = this->bySize(w, h, this->extension);

        if unlikely ! imagecopyresampled(
            dstIm->handler,
            this->handler,
            dstArea->x,
            dstArea->y,
            srcArea->x,
            srcArea->y,
            dstArea->w,
            dstArea->h,
            srcArea->w,
            srcArea->h
        ) {
            throw new Exception(__FUNCTION__);
        }

        return dstIm;
    }

    public function largest(long w, long h) -> <ImageInterface>
    {
        var oriW, oriH, dstW, dstH;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        let oriW = (long) this->width;
        let oriH = (long) this->height;

        let dstW = oriW;
        let dstH = oriH;

        if w > 0 && dstW > w {
            let dstH = (long) (1.0 * dstH * w / dstW);
            let dstW = w;
        }

        if h > 0 && dstH > h {
            let dstW = (long) (1.0 * dstW * h / dstH);
            let dstH = h;
        }

        return this->resample(
            dstW,
            dstH,
            new Area(0, 0, dstW, dstH),
            new Area(0, 0, oriW, oriH)
        );
    }

    public function resize(long w, long h = 0) -> <ImageInterface>
    {
        var oriW, oriH, dstW, dstH;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let oriW = (long) this->width;
        let oriH = (long) this->height;

        if oriW * h > oriH * w {
            let dstW = w;
            let dstH = (long) (1.0 * oriH * w / oriW);
        } else {
            let dstW = (long) (1.0 * oriW * h / oriH);
            let dstH = h;
        }

        return this->resample(
            dstW,
            dstH,
            new Area(0, 0, dstW, dstH),
            new Area(0, 0, oriW, oriH)
        );
    }

    public function thumbnail(long w, long h = 0) -> <ImageInterface>
    {
        var oriW, oriH, dstX, dstY, dstW, dstH;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let oriW = (long) this->width;
        let oriH = (long) this->height;

        if oriW * h > oriH * w {
            let dstW = w;
            let dstH = (long) (1.0 * oriH * w / oriW);
        } else {
            let dstW = (long) (1.0 * oriW * h / oriH);
            let dstH = h;
        }

        let dstX = (long) (0.5 * (w - dstW));
        let dstY = (long) (0.5 * (h - dstH));

        return this->resample(
            w,
            h,
            new Area(dstX, dstY, dstW, dstH),
            new Area(0, 0, oriW, oriH)
        );
    }

    public function cropThumbnail(long w, long h = 0) -> <ImageInterface>
    {
        var oriW, oriH, srcX, srcY, srcW, srcH;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let oriW = (long) this->width;
        let oriH = (long) this->height;

        if oriW * h < oriH * w {
            let srcW = oriW;
            let srcH = (long) (1.0 * h * oriW / w);
        } else {
            let srcW = (long) (1.0 * w * oriH / h);
            let srcH = oriH;
        }

        let srcX = (long) (0.5 * (oriW - srcW));
        let srcY = (long) (0.5 * (oriH - srcH));

        return this->resample(
            w,
            h,
            new Area(0, 0, w, h),
            new Area(srcX, srcY, srcW, srcH)
        );
    }

    public function crop(long x, long y, long w, long h = 0) -> <ImageInterface>
    {
        var oriW, oriH;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely x < 0 || y < 0 {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let oriW = (long) this->width;
        let oriH = (long) this->height;

        if unlikely x + w > oriW || y + h > oriH {
            throw new Exception(__FUNCTION__);
        }

        return this->resample(
            w,
            h,
            new Area(0, 0, w, h),
            new Area(x, y, w, h)
        );
    }

    public function paste(<ImageInterface> im, long x, long y = -2147483647) -> <ImageInterface>
    {
        var srcIm, dstIm, paintingArea;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if im instanceof Gd {
            let srcIm = im;
        } else {
            let srcIm = this->byImage(im);
        }

        if unlikely ! srcIm->handler {
            throw new Exception(__FUNCTION__);
        }

        let dstIm = this->copy();

        if y === -2147483647 {
            let paintingArea = this->getPaintingAreaByPosition(im->getWidth(), im->getHeight(), x);
            let x = paintingArea->x;
            let y = paintingArea->y;
        }

        if unlikely ! imagecopy(
            dstIm->handler,
            srcIm->handler,
            x,
            y,
            0,
            0,
            srcIm->width,
            srcIm->height
        ) {
            throw new Exception(__FUNCTION__);
        }

        return dstIm;
    }

    public function annotate(string text, array options, long x, long y = -2147483647) -> <ImageInterface>
    {
        var dstIm, dstHandler, mo, textArea, paintingArea, alpha, m, r, g, b, colorResource;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        let dstIm = this->copy();
        let dstHandler = dstIm->handler;

        let mo = options + [
            "font"          : "simsun.ttf",
            "fontSize"      : 28,
            "padding"       : 2,
            "opacity"       : 1.0,
            "color"         : "#000000",
            "shadowColor"   : ""
        ];

        let textArea = this->queryTextArea(text, mo["font"], mo["fontSize"], mo["padding"]);

        if y === -2147483647 {
            let paintingArea = this->getPaintingAreaByPosition(textArea->w, textArea->h, x);
            let x = paintingArea->x + textArea->x;
            let y = paintingArea->y + textArea->y;
        } else {
            let x += textArea->x;
            let y += textArea->y;
        }

        let alpha = (long) ((1.0 - mo["opacity"]) * 127.0);

        let m = null;
        if preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/", mo["shadowColor"], m) {
            let r = (long) hexdec(m[1]);
            let g = (long) hexdec(m[2]);
            let b = (long) hexdec(m[3]);

            let colorResource = imagecolorallocatealpha(dstHandler, r, g, b, alpha);

            if unlikely ! imagettftext(
                dstHandler,
                mo["fontSize"],
                0,
                x + 1,
                y + 1,
                colorResource,
                mo["font"],
                text
            ) {
                throw new Exception(__FUNCTION__);
            }
        }

        let m = null;
        let r = 0;
        let g = 0;
        let b = 0;
        if preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/", mo["color"], m) {
            let r = (long) hexdec(m[1]);
            let g = (long) hexdec(m[2]);
            let b = (long) hexdec(m[3]);
        }

        let colorResource = imagecolorallocatealpha(dstHandler, r, g, b, alpha);

        if unlikely ! imagettftext(
            dstHandler,
            mo["fontSize"],
            0,
            x,
            y,
            colorResource,
            mo["font"],
            text
        ) {
            throw new Exception(__FUNCTION__);
        }

        return dstIm;
    }

    public function queryTextArea(string text, string font, long fontSize, long padding = 0) -> <Area>
    {
        var box, x, y, w, h;

        let box = imagettfbbox(fontSize, 0, font, text);
        if unlikely ! box {
            throw new Exception(__FUNCTION__);
        }

        let x = (long) (padding - 1 - box[6]);
        let y = (long) (padding - 1 - box[7]);
        let w = (long) (padding * 2 + box[2] - box[6]);
        let h = (long) (padding * 2 + box[3] - box[7]);

        return new Area(x, y, w, h);
    }

    public function save(string path) -> void
    {
        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        switch this->extension {
            case "jpg":
            case "jpeg":
                if imagejpeg(this->handler, path, 100) {
                    return;
                }
                break;

            case "png":
                if imagepng(this->handler, path) {
                    return;
                }
                break;

            case "gif":
                if imagegif(this->handler, path) {
                    return;
                }
                break;

            default:
                throw new Exception(__FUNCTION__);
        }

        throw new Exception(__FUNCTION__);
    }

    public function toString() -> string
    {
        var success = null, result;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        ob_start();

        switch this->extension {
            case "jpg":
            case "jpeg":
                let success = imagejpeg(this->handler, null, 100);
                break;

            case "png":
                let success = imagepng(this->handler);
                break;

            case "gif":
                let success = imagegif(this->handler);
                break;
        }

        let result = (string) ob_get_clean();

        if success === null {
            throw new Exception(__FUNCTION__);
        }

        if success === false {
            throw new Exception(__FUNCTION__);
        }

        return result;
    }

    public function __destruct() -> void
    {
        try {
            if this->handler {
                imagedestroy(this->handler);
            }
        }

        return;
    }

    protected function newImage(var handler, string extension) -> <Gd>
    {
        var mimeType, im;

        switch extension {
            case "jpg":
            case "jpeg":
                let mimeType = "image/jpeg";
                break;

            case "png":
                let mimeType = "image/png";
                break;

            case "gif":
                let mimeType = "image/gif";
                break;

            default:
                throw new Exception(__FUNCTION__);
        }

        let im = this->newInstance();

        let im->handler     = handler;
        let im->width       = imagesx(handler);
        let im->height      = imagesy(handler);
        let im->extension   = extension;
        let im->mimeType    = mimeType;

        return im;
    }
}
