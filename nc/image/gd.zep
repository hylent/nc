namespace Nc\Image;

class Gd extends ImageAbstract
{
    public function __construct(array defaults = null) -> void
    {
        if unlikely ! extension_loaded("gd") {
            throw new Exception("Missing extension: gd");
        }

        if count(defaults) {
            this->setDefaults(defaults);
        }
    }

    public function text(string text, array options = []) -> <Item\Text>
    {
        var imProperties, box;
        long padding2;

        let imProperties = this->validTextOptions(options);

        let box = imagettfbbox(imProperties["fontSize"], 0, imProperties["font"], text);
        if unlikely ! box {
            throw new Exception("imagettfbbox");
        }

        let padding2 = 2 * (long) imProperties["padding"];

        let imProperties["text"] = text;
        let imProperties["width"] = box[2] - box[6] + padding2;
        let imProperties["height"] = box[3] - box[7] + padding2;

        return new Item\Text(this, imProperties);
    }

    public function captcha(string code, long width, long height, array options = []) -> <Item\Image>
    {
        var validOptions, im, handler, color, shadow;
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
        let handler = im->{"handler"};

        // background
        let r = (long) mt_rand(200, 255);
        let g = (long) mt_rand(200, 255);
        let b = (long) mt_rand(200, 255);
        let dr = (r - mt_rand(100, 150)) / width;
        let dg = (g - mt_rand(100, 150)) / width;
        let db = (b - mt_rand(100, 150)) / width;
        let i = 0;
        while i < width {
            let color = imagecolorallocate(handler, r, g, b);
            imageline(handler, i, 0, i, height, color);
            let r -= dr;
            let g -= dg;
            let b -= db;
            let i++;
        }

        // text
        let shadow = imagecolorallocate(handler, 0, 0, 0);
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
            let color = imagecolorallocate(handler, mt_rand(0, 255), mt_rand(0, 255), mt_rand(0, 255));
            imagettftext(handler, fontSize, angle, x + 1, y + 1, shadow, font, ch);
            imagettftext(handler, fontSize, angle, x, y, color, font, ch);
            let x = x + (1.0 - rOverlap) * fontSize;
            let i++;
        }

        // adulterate
        let i = 0;
        while i < codeLen {
            let color = imagecolorallocate(handler, mt_rand(0, 255), mt_rand(0, 255), mt_rand(0, 255));
            let x = (long) mt_rand(0, width);
            let y = (long) mt_rand(0, height);
            let x2 = (long) mt_rand(0, width);
            let y2 = (long) mt_rand(0, height);
            let j = 0;
            while j <= padding {
                imageline(handler, x + j, y, x2 + j, y2, color);
                let j++;
            }
            imageline(handler, x + j, y, x2 + j, y2, shadow);
            let i++;
        }

        return im;
    }

    public function fromImage(<Item\Image> im) -> <Item\Image>
    {
        var copyIm;

        let copyIm = this->fromSize(im->{"width"}, im->{"height"}, im->{"extension"});
        this->copy(copyIm, im, 0, 0);

        return copyIm;
    }

    public function fromSize(long width, long height = 0, string extension = "") -> <Item\Image>
    {
        var imProperties = [], handler, background;

        if width < 1 {
            throw new Exception("Argument width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        let handler = imagecreatetruecolor(width, height);
        if unlikely ! handler {
            throw new Exception("Cannot create image");
        }

        imagealphablending(handler, true);
        imagesavealpha(handler, true);

        let background = imagecolorallocatealpha(handler, 255, 255, 255, 127);
        imagecolortransparent(handler, background);
        imagefill(handler, 0, 0, background);

        let imProperties["extension"] = extension ? extension : "jpg";
        let imProperties["width"] = width;
        let imProperties["height"] = height;
        let imProperties["handler"] = handler;

        return new Item\Image(this, imProperties);
    }

    public function fromPath(string path, string extension = "") -> <Item\Image>
    {
        var imProperties = [], handler;
        string ext;

        if extension {
            let ext = extension->lower();
        } else {
            let ext = (string) strtolower(pathinfo(path, PATHINFO_EXTENSION));
        }

        switch ext {
            case "png":
                let handler = imagecreatefrompng(path);
                break;
            case "gif":
                let handler = imagecreatefromgif(path);
                break;
            case "jpg":
            case "jpeg":
                let handler = imagecreatefromjpeg(path);
                break;
            default:
                throw new Exception("Unsupported extension: " . ext);
        }

        if unlikely ! handler {
            throw new Exception("Cannot create image");
        }

        imagealphablending(handler, true);
        imagesavealpha(handler, true);

        let imProperties["extension"] = ext;
        let imProperties["width"] = imagesx(handler);
        let imProperties["height"] = imagesy(handler);
        let imProperties["handler"] = handler;

        return new Item\Image(this, imProperties);
    }

    public function fromString(string data, string extension = "") -> <Item\Image>
    {
        var imProperties = [], handler;
        string ext;

        if extension {
            let ext = extension->lower();
        } else {
            let ext = "jpg";
        }

        let handler = imagecreatefromstring(data);
        if unlikely ! handler {
            throw new Exception("Cannot create image");
        }

        imagealphablending(handler, true);
        imagesavealpha(handler, true);

        let imProperties["extension"] = ext;
        let imProperties["width"] = imagesx(handler);
        let imProperties["height"] = imagesy(handler);
        let imProperties["handler"] = handler;

        return new Item\Image(this, imProperties);
    }

    public function resize(<Item\Image> im, long width, long height) -> <Item\Image>
    {
        var destIm;
        long srcW, srcH, w, h;

        if unlikely width < 1 {
            throw new Exception("Argument width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        let srcW = (long) im->{"width"};
        let srcH = (long) im->{"height"};

        let w = srcW;
        let h = srcH;

        if w * height > h * width {
            let w = width;
            let h = (long) (1.0 * srcH * w / srcW);
        } else {
            let h = height;
            let w = (long) (1.0 * srcW * h / srcH);
        }

        let destIm = this->fromSize(w, h, im->{"extension"});
        this->copyResampled(destIm, im, 0, 0, w, h, 0, 0, srcW, srcH);

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

        let destIm = this->fromSize(w, h, im->{"extension"});
        this->copyResampled(destIm, im, 0, 0, w, h, x, y, w, h);

        return destIm;
    }

    public function thumbnail(<Item\Image> im, long width, long height, boolean cropped) -> <Item\Image>
    {
        var destIm;
        long srcW, srcH, w, h, x, y;

        if unlikely width < 1 {
            throw new Exception("Width must be positive");
        }

        if height < 1 {
            let height = width;
        }

        let srcW = (long) im->{"width"};
        let srcH = (long) im->{"height"};

        let destIm = this->fromSize(width, height, im->{"extension"});

        if cropped {
            if width * srcH > height * srcW {
                let w = srcW;
                let h = (long) (1.0 * height * w / width);
            } else {
                let h = srcH;
                let w = (long) (1.0 * width * h / height);
            }
            let x = (long) (0.5 * (srcW - w));
            let y = (long) (0.5 * (srcH - h));
            this->copyResampled(destIm, im, 0, 0, width, height, x, y, w, h);
        } else {
            if width * srcH < height * srcW {
                let w = width;
                let h = (long) (1.0 * srcH * w / srcW);
            } else {
                let h = height;
                let w = (long) (1.0 * srcW * h / srcH);
            }
            let x = (long) (0.5 * (width - w));
            let y = (long) (0.5 * (height - h));
            this->copyResampled(destIm, im, x, y, w, h, 0, 0, srcW, srcH);
        }

        return destIm;
    }

    public function draw(<Item\Image> destIm, <Item\ImageItemAbstract> srcIm, long x, long y) -> <Item\Image>
    {
        var resultIm;

        let resultIm = this->fromImage(destIm);

        do {
            if srcIm instanceof Item\Image {
                this->copy(resultIm, srcIm, x, y);
                break;
            }

            if srcIm instanceof Item\Text {
                this->drawText(resultIm, srcIm, x, y);
                break;
            }

            throw new Exception("Invalid item type: " . get_class(srcIm));
        } while false;

        return resultIm;
    }

    public function save(<Item\Image> im, var destPath) -> void
    {
        switch im->{"extension"} {
            case "png":
                if imagepng(im->{"handler"}, destPath) {
                    return;
                }
                break;

            case "gif":
                if imagegif(im->{"handler"}, destPath) {
                    return;
                }
                break;

            case "jpg":
            case "jpeg":
                if imagejpeg(im->{"handler"}, destPath, 100) {
                    return;
                }
                break;

            default:
                throw new Exception("Unsupported extension");
        }

        throw new Exception("Cannot save image");
    }

    public function destroy(<Item\ImageItemAbstract> im) -> void
    {
        if im instanceof Item\Image {
            imagedestroy(im->{"handler"});
        }
    }

    protected function drawText(<Item\Image> dest, <Item\Text> src, long x, long y) -> void
    {
        var handler, color;
        long alpha;

        let x += src->{"padding"};
        let y += src->{"height"} - src->{"padding"};

        let handler = dest->{"handler"};
        let alpha = (long) ((1.0 - src->{"opacity"}) * 127.0);

        let color = imagecolorallocatealpha(handler, src->{"red"}, src->{"green"}, src->{"blue"}, alpha);

        if unlikely ! imagettftext(handler, src->{"fontSize"}, 0, x, y, color, src->{"font"}, src->{"text"}) {
            throw new Exception("imagettftext");
        }
    }

    protected function copy(<Item\Image> dest, <Item\Image> src, long x = 0, long y = 0) -> void
    {
        if unlikely ! imagecopy(dest->{"handler"}, src->{"handler"}, x, y, 0, 0, src->{"width"}, src->{"height"}) {
            throw new Exception("imagecopy");
        }
    }

    protected function copyResampled(<Item\Image> dest, <Item\Image> src,
        long x, long y, long w, long h,
        long srcX, long srcY, long srcW, long srcH) -> void
    {
        if unlikely ! imagecopyresampled(dest->{"handler"}, src->{"handler"}, x, y, srcX, srcY, w, h, srcW, srcH) {
            throw new Exception("imagecopyresampled");
        }
    }
}
