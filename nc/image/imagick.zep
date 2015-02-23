namespace Nc\Image;

class Imagick extends ImageAbstract
{
    public function __construct(array defaults = null) -> void
    {
        if unlikely ! extension_loaded("imagick") {
            throw new Exception("Missing extension: imagick");
        }

        if count(defaults) {
            this->setDefaults(defaults);
        }
    }

    public function text(string text, array options = []) -> <Item\Text>
    {
        var imProperties, imagick, imgickDraw, m;
        long padding2;

        let imProperties = this->validTextOptions(options);

        let imagick = new \Imagick();
        let imgickDraw = new \ImagickDraw();
        imgickDraw->setFont(imProperties["font"]);
        imgickDraw->setFontSize(imProperties["fontSize"]);
        let m = imagick->queryFontMetrics(imgickDraw, text);

        let padding2 = 2 * (long) imProperties["padding"];

        let imProperties["text"] = text;
        let imProperties["width"] = m["textWidth"] + padding2;
        let imProperties["height"] = m["textHeight"] + padding2;

        return new Item\Text(this, imProperties);
    }

    public function captcha(string code, long width, long height, array options = []) -> <Item\Image>
    {
        var validOptions, im, imagick, imagickDraw, shadow;
        double rPadding, rOverlap;
        string font, ch;
        long codeLen, fontSize, padding, r, g, b, dr, dg, db, i, j, x, y, x2, y2, angle;

        // options
        let validOptions = this->validCaptchaOptions(options);
        let font = (string) validOptions["font"];
        let rPadding = (double) validOptions["rPadding"];
        let rOverlap = (double) validOptions["rOverlap"];

        // sizes
        let codeLen = (long) mb_strlen(code, "utf-8");
        let fontSize = (long) (1.0 * width / (rPadding * 2 + codeLen));
        if fontSize > height {
            let fontSize = height;
        }
        let padding = (long) (fontSize * rPadding);

        // im
        let im = this->fromSize(width, height, "png");
        let imagick = im->{"imagick"};
        let imagickDraw = new \ImagickDraw();

        // background
        let r = (long) mt_rand(200, 255);
        let g = (long) mt_rand(200, 255);
        let b = (long) mt_rand(200, 255);
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
        while i < codeLen {
            let x2 = width - padding * 2 - ((1.0 - rOverlap) * (codeLen - i) + rOverlap) * fontSize;
            if x2 > x {
                let x = (long) mt_rand(x, x2);
            }
            let y = (long) mt_rand(fontSize, height);
            let angle = (long) mt_rand(-15, 15);
            let ch = (string) mb_substr(code, i, 1, "utf-8");
            let r = (long) mt_rand(0, 255);
            let g = (long) mt_rand(0, 255);
            let b = (long) mt_rand(0, 255);
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
        while i < codeLen {
            let r = (long) mt_rand(0, 255);
            let g = (long) mt_rand(0, 255);
            let b = (long) mt_rand(0, 255);
            imagickDraw->setFillColor(new \ImagickPixel("rgb(".r.",".g.",".b.")"));
            let x = (long) mt_rand(0, width);
            let y = (long) mt_rand(0, height);
            let x2 = (long) mt_rand(0, width);
            let y2 = (long) mt_rand(0, height);
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

    public function fromImage(<Item\Image> im) -> <Item\Image>
    {
        var imProperties = [], imagick;

        let imagick = new \Imagick();
        imagick->readImageBlob(im->{"imagick"}->getImageBlob());

        let imProperties["extension"] = im->{"extension"};
        let imProperties["width"] = im->{"width"};
        let imProperties["height"] = im->{"height"};
        let imProperties["imagick"] = imagick;

        return new Item\Image(this, imProperties);
    }

    public function fromSize(long width, long height = 0, string extension = "") -> <Item\Image>
    {
        var imProperties = [], imagick;
        string ext;

        if width < 1 {
            throw new Exception("Argument width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        if extension {
            let ext = extension->lower();
        } else {
            let ext = "jpg";
        }

        let imagick = new \Imagick();
        imagick->newImage(width, height, new \ImagickPixel("rgba(255,255,255,127)"), ext);

        let imProperties["extension"] = ext;
        let imProperties["width"] = width;
        let imProperties["height"] = height;
        let imProperties["imagick"] = imagick;

        return new Item\Image(this, imProperties);
    }

    public function fromPath(string path, string extension = "") -> <Item\Image>
    {
        var imProperties = [], imagick;
        string ext;

        if extension {
            let ext = extension->lower();
        } else {
            let ext = (string) strtolower(pathinfo(path, PATHINFO_EXTENSION));
        }

        let imagick = new \Imagick();
        imagick->readImage(realpath(path));

        let imProperties["extension"] = ext;
        let imProperties["width"] = imagick->getImageWidth();
        let imProperties["height"] = imagick->getImageHeight();
        let imProperties["imagick"] = imagick;

        return new Item\Image(this, imProperties);
    }

    public function fromString(string data, string extension = "") -> <Item\Image>
    {
        var imProperties = [], imagick;
        string ext;

        if extension {
            let ext = extension->lower();
        } else {
            let ext = "jpg";
        }

        let imagick = new \Imagick();
        imagick->readImageBlob(data);

        let imProperties["extension"] = ext;
        let imProperties["width"] = imagick->getImageWidth();
        let imProperties["height"] = imagick->getImageHeight();
        let imProperties["imagick"] = imagick;

        return new Item\Image(this, imProperties);
    }

    public function resize(<Item\Image> im, long width, long height) -> <Item\Image>
    {
        var destIm, imagick;

        if unlikely width < 1 {
            throw new Exception("Argument width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        let destIm = this->fromImage(im);
        let imagick = destIm->{"imagick"};

        imagick->thumbnailImage(width, height, true);

        let destIm->{"width"} = imagick->getImageWidth();
        let destIm->{"height"} = imagick->getImageHeight();

        return destIm;
    }

    public function crop(<Item\Image> im, long x, long y, long w, long h) -> <Item\Image>
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

        if unlikely x + w > im->{"width"} || y + h > im->{"height"} {
            throw new Exception("Cropping out of area");
        }

        let destIm = this->fromImage(im);
        destIm->{"imagick"}->cropImage(w, h, x, y);

        let destIm->{"width"} = w;
        let destIm->{"height"} = h;

        return destIm;
    }

    public function thumbnail(<Item\Image> im, long width, long height, boolean cropped) -> <Item\Image>
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
            destIm->{"imagick"}->cropThumbnailImage(width, height);
        } else {
            destIm->{"imagick"}->thumbnailImage(width, height, true, true);
        }

        let destIm->{"width"} = width;
        let destIm->{"height"} = height;

        return destIm;
    }

    public function draw(<Item\Image> destIm, <Item\ImageItemAbstract> srcIm, long x, long y) -> <Item\Image>
    {
        var resultIm, imagickDraw;

        let resultIm = this->fromImage(destIm);

        if srcIm instanceof Item\Image {
            resultIm->{"imagick"}->compositeImage(srcIm->{"imagick"}, \Imagick::COMPOSITE_OVER, x, y);
            return resultIm;
        }

        if srcIm instanceof Item\Text {
            let imagickDraw = new \ImagickDraw();
            imagickDraw->setFont(srcIm->{"font"});
            imagickDraw->setFontSize(srcIm->{"fontSize"});
            imagickDraw->setFillColor(srcIm->{"color"});
            imagickDraw->setFillOpacity(srcIm->{"opacity"});
            let x += srcIm->{"padding"};
            let y += srcIm->{"height"} - srcIm->{"padding"};
            resultIm->{"imagick"}->annotateImage(imagickDraw, x, y, 0, srcIm->{"text"});
            return resultIm;
        }

        throw new Exception("Invalid item type: " . get_class(srcIm));
    }

    public function save(<Item\Image> im, var destPath) -> void
    {
        if destPath === null {
            echo im->{"imagick"}->getImageBlob();
            return;
        }

        im->{"imagick"}->writeImage(destPath);
    }

    public function destroy(<Item\ImageItemAbstract> im) -> void
    {
        if im instanceof Item\Image {
            im->{"imagick"}->clear();
        }
    }
}
