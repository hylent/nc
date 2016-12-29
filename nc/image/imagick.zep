namespace Nc\Image;

class Imagick extends ImageAbstract
{
    protected handler;

    public function __construct() -> void
    {
        if unlikely ! extension_loaded("imagick") {
            throw new Exception(__FUNCTION__);
        }
    }

    public function bySize(long w, long h = 0, string extension = "png") -> <ImageInterface>
    {
        var handler;

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let handler = new \Imagick();

        if unlikely ! handler->newImage(w, h, new \ImagickPixel("rgba(255,255,255,127)"), extension) {
            throw new Exception(__FUNCTION__);
        }

        return this->newImage(handler, extension);
    }

    public function byString(string data, string extension = "png") -> <ImageInterface>
    {
        var handler;

        if unlikely data->length() < 1 {
            throw new Exception(__FUNCTION__);
        }

        let handler = new \Imagick();

        if unlikely ! handler->readImageBlob(data) {
            throw new Exception(__FUNCTION__);
        }

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

        let handler = new \Imagick();

        if unlikely ! handler->readImage(path) {
            throw new Exception(__FUNCTION__);
        }

        switch eit {
            case IMAGETYPE_JPEG:
                let extension = "jpg";
                break;
            case IMAGETYPE_PNG:
                let extension = "png";
                break;
            case IMAGETYPE_GIF:
                let extension = "gif";
                break;

            default:
                let extension = handler->getImageFormat();
                break;
        }

        return this->newImage(handler, extension);
    }

    public function copy() -> <ImageInterface>
    {
        var dstHandler;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        let dstHandler = new \Imagick();
        dstHandler->addImage(this->handler);

        return this->newImage(dstHandler, this->extension);
    }

    public function largest(long w, long h) -> <ImageInterface>
    {
        var dstHandler;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let dstHandler = new \Imagick();
        dstHandler->addImage(this->handler);
        dstHandler->thumbnailImage(w, h);

        return this->newImage(dstHandler, this->extension);
    }

    public function resize(long w, long h = 0) -> <ImageInterface>
    {
        var dstHandler;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let dstHandler = new \Imagick();
        dstHandler->addImage(this->handler);
        dstHandler->thumbnailImage(w, h, true);

        return this->newImage(dstHandler, this->extension);
    }

    public function thumbnail(long w, long h = 0) -> <ImageInterface>
    {
        var dstHandler;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let dstHandler = new \Imagick();
        dstHandler->addImage(this->handler);
        dstHandler->thumbnailImage(w, h, true, true);

        return this->newImage(dstHandler, this->extension);
    }

    public function cropThumbnail(long w, long h = 0) -> <ImageInterface>
    {
        var dstHandler;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely w < 1 {
            throw new Exception(__FUNCTION__);
        }

        if h < 1 {
            let h = w;
        }

        let dstHandler = new \Imagick();
        dstHandler->addImage(this->handler);
        dstHandler->cropThumbnailImage(w, h);

        return this->newImage(dstHandler, this->extension);
    }

    public function crop(long x, long y, long w, long h = 0) -> <ImageInterface>
    {
        var oriW, oriH, dstHandler;

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

        let dstHandler = new \Imagick();
        dstHandler->addImage(this->handler);
        dstHandler->cropImage(w, h, x, y);

        return this->newImage(dstHandler, this->extension);
    }

    public function paste(<ImageInterface> im, long x, long y = -2147483647) -> <ImageInterface>
    {
        var srcIm, dstIm, paintingArea;

        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if im instanceof Imagick {
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

        if unlikely ! dstIm->handler->compositeImage(srcIm->handler, \Imagick::COMPOSITE_OVER, x, y) {
            throw new Exception(__FUNCTION__);
        }

        return dstIm;
    }

    public function annotate(string text, array options, long x, long y = -2147483647) -> <ImageInterface>
    {
        var dstIm, dstHandler, mo, textArea, paintingArea, imagickDraw;

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

        let imagickDraw = new \ImagickDraw();
        imagickDraw->setResolution(96, 96);
        imagickDraw->setFont(realpath(mo["font"]));
        imagickDraw->setFontSize(mo["fontSize"]);
        imagickDraw->setFillOpacity(mo["opacity"]);

        if preg_match("/^#[0-9a-fA-F]{6}$/", mo["shadowColor"]) {
            imagickDraw->setFillColor(mo["shadowColor"]);
            if unlikely ! dstHandler->annotateImage(imagickDraw, x + 1, y + 1, 0, text) {
                throw new Exception(__FUNCTION__);
            }
        }

        if ! preg_match("/^#[0-9a-fA-F]{6}$/", mo["color"]) {
            let mo["color"] = "#000000";
        }

        imagickDraw->setFillColor(mo["color"]);
        if unlikely ! dstHandler->annotateImage(imagickDraw, x, y, 0, text) {
            throw new Exception(__FUNCTION__);
        }

        return dstIm;
    }

    public function queryTextArea(string text, string font, long fontSize, long padding = 0) -> <Area>
    {
        var testF, testW, testH, imagickDraw, imagick, page, x, y, w, h;

        let testF = fontSize * 2;
        let testW = testF * (mb_strlen(text, "UTF-8") + 2);
        let testH = testF * 2;

        let imagickDraw = new \ImagickDraw();
        imagickDraw->setResolution(96, 96);
        imagickDraw->setFont(realpath(font));
        imagickDraw->setFontSize(fontSize);

        let imagick = new \Imagick();
        imagick->newImage(testW, testH, "transparent", "png");
        imagick->annotateImage(imagickDraw, testF, testF, 0, text);
        imagick->trimImage(0);
        let page = imagick->getImagePage();

        let x = (long) (padding + testF - page["x"]);
        let y = (long) (padding + testF - page["y"]);
        let w = (long) (padding * 2 + imagick->getImageWidth());
        let h = (long) (padding * 2 + imagick->getImageHeight());

        imagick->clear();

        return new Area(x, y, w, h);
    }

    public function save(string path) -> void
    {
        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        if unlikely ! this->handler->writeImage(path) {
            throw new Exception(__FUNCTION__);
        }
    }

    public function toString() -> string
    {
        if unlikely ! this->handler {
            throw new Exception(__FUNCTION__);
        }

        return (string) this->handler->getImageBlob();
    }

    public function __destruct() -> void
    {
        try {
            if this->handler {
                this->handler->clear();
            }
        }

        return;
    }

    protected function newImage(<\Imagick> handler, extension) -> <Imagick>
    {
        var im;

        if unlikely ! handler->setImageFormat(extension) {
            throw new Exception(__FUNCTION__);
        }

        let im = this->newInstance();

        let im->handler     = handler;
        let im->width       = handler->getImageWidth();
        let im->height      = handler->getImageHeight();
        let im->extension   = extension;
        let im->mimeType    = handler->getImageMimeType();

        return im;
    }

}
