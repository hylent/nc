namespace Nc\Image;

class Imagick extends ImageBackendAbstract
{
    public function __construct(array defaultOptions = []) -> void
    {
        if unlikely ! extension_loaded("imagick") {
            throw new Exception("Missing extension: imagick");
        }

        parent::__construct(defaultOptions);
    }

    public function text(string text, array options = []) -> <Text>
    {
        var im, imagick, imgickDraw, m;
        long padding2;

        let im = this->newText();
        let im->text = text;
        im->setOptions(options);

        let imagick = new \Imagick();
        let imgickDraw = new \ImagickDraw();
        imgickDraw->setFont(im->font);
        imgickDraw->setFontSize(im->fontSize);
        let m = imagick->queryFontMetrics(imgickDraw, text);

        let padding2 = (long) im->padding * 2;
        let im->width = m["textWidth"] + padding2;
        let im->height = m["textHeight"] + padding2;

        return im;
    }

    public function fromImage(<Image> im) -> <Image>
    {
        var copyIm, imagick;

        let imagick = new \Imagick();
        imagick->readImageBlob(im->handler->getImageBlob());

        let copyIm = this->newImage();
        let copyIm->handler = imagick;
        let copyIm->width = im->width;
        let copyIm->height = im->height;
        let copyIm->extension = im->extension;

        return copyIm;
    }

    public function fromSize(long width, long height = 0, string extension = "") -> <Image>
    {
        var im, imagick;

        if width < 1 {
            throw new Exception("Argument width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        let im = this->newImage();
        let im->width = width;
        let im->height = height;
        if extension {
            let im->extension = extension->lower();
        }

        let imagick = new \Imagick();
        imagick->newImage(width, height, new \ImagickPixel("rgba(255,255,255,127)"), im->extension);
        let im->handler = imagick;

        return im;
    }

    public function fromPath(string path, string extension = "") -> <Image>
    {
        var im, imagick;

        let imagick = new \Imagick();
        imagick->readImage(realpath(path));

        let im = this->newImage();
        let im->handler = imagick;
        let im->width = imagick->getImageWidth();
        let im->height = imagick->getImageHeight();
        if extension {
            let im->extension = extension->lower();
        } else {
            let im->extension = (string) strtolower(pathinfo(path, PATHINFO_EXTENSION));
        }

        return im;
    }

    public function fromString(string data, string extension = "") -> <Image>
    {
        var im, imagick;

        let imagick = new \Imagick();
        imagick->readImageBlob(data);

        let im = this->newImage();
        let im->handler = imagick;
        let im->width = imagick->getImageWidth();
        let im->height = imagick->getImageHeight();
        if extension {
            let im->extension = extension->lower();
        }

        return im;
    }

    public function captcha(string text, long width, long height, array options = []) -> <Captcha>
    {
        var im, imagick, imagickDraw, shadow;
        double rPadding, rOverlap;
        string font, ch;
        long textLen, fontSize, padding, r, g, b, dr, dg, db, i, j, x, y, x2, y2, angle;

        if width < 1 {
            throw new Exception("Argument width must be positive");
        }
        if height < 1 {
            let height = width;
        }

        // im
        let im = this->newCaptcha();
        let im->width = width;
        let im->height = height;
        let im->text = text;
        im->setOptions(options);
        let imagick = new \Imagick();
        imagick->newImage(width, height, new \ImagickPixel("rgba(255,255,255,127)"), im->extension);
        let im->handler = imagick;

        // options
        let font = (string) im->font;
        let rPadding = (double) im->rPadding;
        let rOverlap = (double) im->rOverlap;

        // sizes
        let textLen = (long) mb_strlen(text, "utf-8");
        let fontSize = (long) (1.0 * width / (rPadding * 2 + textLen));
        if fontSize > height {
            let fontSize = height;
        }
        let padding = (long) (fontSize * rPadding);

        let imagickDraw = new \ImagickDraw();

        // background
        let r = mt_rand(200, 255);
        let g = mt_rand(200, 255);
        let b = mt_rand(200, 255);
        let dr = (r - mt_rand(100, 150)) / width;
        let dg = (g - mt_rand(100, 150)) / width;
        let db = (b - mt_rand(100, 150)) / width;
        let i = 0;
        while i < width {
            imagickDraw->setFillColor(new \ImagickPixel("rgb(".r.",".g.",".b.")"));
            imagickDraw->line(i, 0, i, height);
            let r -= dr;
            let g -= dg;
            let b -= db;
            let i++;
        }
        imagick->drawImage(imagickDraw);
        imagickDraw->clear();

        // shadow
        let shadow = new \ImagickPixel("#000000");

        // text
        imagickDraw->setFont(font);
        imagickDraw->setFontSize(fontSize);
        let x = padding;
        let i = 0;
        while i < textLen {
            let x2 = width - padding * 2 - ((1.0 - rOverlap) * (textLen - i) + rOverlap) * fontSize;
            if x2 > x {
                let x = mt_rand(x, x2);
            }
            let y = mt_rand(fontSize, height);
            let angle = mt_rand(-15, 15);
            let ch = (string) mb_substr(text, i, 1, "utf-8");
            let r = mt_rand(0, 255);
            let g = mt_rand(0, 255);
            let b = mt_rand(0, 255);
            imagickDraw->setFillColor(shadow);
            imagick->annotateImage(imagickDraw, x + 1, y + 1, angle, ch);
            imagickDraw->setFillColor(new \ImagickPixel("rgb(".r.",".g.",".b.")"));
            imagick->annotateImage(imagickDraw, x, y, angle, ch);
            let x = x + (1.0 - rOverlap) * fontSize;
            let i++;
        }
        imagickDraw->clear();

        // adulterate
        let i = 0;
        while i < textLen {
            let r = mt_rand(0, 255);
            let g = mt_rand(0, 255);
            let b = mt_rand(0, 255);
            imagickDraw->setFillColor(new \ImagickPixel("rgb(".r.",".g.",".b.")"));
            let x = mt_rand(0, width);
            let y = mt_rand(0, height);
            let x2 = mt_rand(0, width);
            let y2 = mt_rand(0, height);
            let j = 0;
            while j <= padding {
                imagickDraw->line(x + j, y, x2 + j, y2);
                let j++;
            }
            imagickDraw->setFillColor(shadow);
            imagickDraw->line(x + j, y, x2 + j, y2);
            let i++;
        }
        imagick->drawImage(imagickDraw);
        imagickDraw->clear();

        return im;
    }

    public function largest(<Image> im, long width, long height) -> <Image>
    {
        var destIm, imagick;

        if width < 1 {
            let width = (long) im->width;
        }

        if height < 1 {
            let height = (long) im->height;
        }

        let destIm = this->fromImage(im);
        let imagick = destIm->handler;

        imagick->thumbnailImage(width, height);

        let destIm->width = imagick->getImageWidth();
        let destIm->height = imagick->getImageHeight();

        return destIm;
    }

    public function resize(<Image> im, long width, long height) -> <Image>
    {
        var destIm, imagick;

        if unlikely width < 1 {
            throw new Exception("Argument width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        let destIm = this->fromImage(im);
        let imagick = destIm->handler;

        imagick->thumbnailImage(width, height, true);

        let destIm->width = imagick->getImageWidth();
        let destIm->height = imagick->getImageHeight();

        return destIm;
    }

    public function crop(<Image> im, long x, long y, long w, long h) -> <Image>
    {
        var destIm;

        if unlikely x < 0 || y < 0 {
            throw new Exception("Arguments x and y must not be negative");
        }

        if unlikely w < 1 {
            throw new Exception("Argument w must be positive");
        }

        if h < 1 {
            let h = w;
        }

        if unlikely x + w > im->width || y + h > im->height {
            throw new Exception("Cropping out of area");
        }

        let destIm = this->fromImage(im);
        destIm->handler->cropImage(w, h, x, y);

        let destIm->width = w;
        let destIm->height = h;

        return destIm;
    }

    public function thumbnail(<Image> im, long width, long height, bool cropped) -> <Image>
    {
        var destIm;

        if unlikely width < 1 {
            throw new Exception("Argument width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        let destIm = this->fromImage(im);

        if cropped {
            destIm->handler->cropThumbnailImage(width, height);
        } else {
            destIm->handler->thumbnailImage(width, height, true, true);
        }

        let destIm->width = width;
        let destIm->height = height;

        return destIm;
    }

    public function draw(<Image> destIm, <ImageAbstract> srcIm, long x, long y) -> <Image>
    {
        var resultIm, imagickDraw;

        let resultIm = this->fromImage(destIm);

        if srcIm instanceof Image {
            resultIm->handler->compositeImage(srcIm->{"handler"}, \Imagick::COMPOSITE_OVER, x, y);
            return resultIm;
        }

        if srcIm instanceof Text {
            let imagickDraw = new \ImagickDraw();
            imagickDraw->setFont(srcIm->{"font"});
            imagickDraw->setFontSize(srcIm->{"fontSize"});
            imagickDraw->setFillColor(srcIm->{"color"});
            imagickDraw->setFillOpacity(srcIm->{"opacity"});
            let x += srcIm->{"padding"};
            let y += srcIm->height - srcIm->{"padding"};
            resultIm->handler->annotateImage(imagickDraw, x, y, 0, srcIm->{"text"});
            return resultIm;
        }

        throw new Exception("Invalid item type: " . get_class(srcIm));
    }

    public function save(<Image> im, string destPath) -> void
    {
        if destPath {
            im->handler->writeImage(destPath);
        } else {
            echo im->handler->getImageBlob();
        }
    }

    public function destroy(<ImageAbstract> im) -> void
    {
        if im instanceof Image {
            im->{"handler"}->clear();
        }
    }
}
