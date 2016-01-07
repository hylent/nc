namespace Nc\Image;

abstract class ImageBackendAbstract
{
    const LEFT_TOP      = 7;
    const TOP           = 8;
    const RIGHT_TOP     = 9;
    const LEFT          = 4;
    const CENTER        = 5;
    const RIGHT         = 6;
    const LEFT_BOTTOM   = 1;
    const BOTTOM        = 2;
    const RIGHT_BOTTOM  = 3;

    const DEFAULT_FONT      = "simhei.ttf";
    const DEFAULT_FONTSIZE  = 24;
    const DEFAULT_COLOR     = "#000000";
    const DEFAULT_OPACITY   = 0.5;
    const DEFAULT_PADDING   = 5;
    const DEFAULT_R_PADDING = 0.2;
    const DEFAULT_R_OVERLAP = 0.2;

    protected defaultOptions;

    public function setDefaultOptions(array options) -> void
    {
        var k, v;

        for k, v in options {
            let this->defaultOptions[k] = v;
        }
    }

    public function getDefaultOptions() -> array
    {
        return (array) this->defaultOptions;
    }

    public function newText() -> <Text>
    {
        return new Text(this);
    }

    public function newImage() -> <Image>
    {
        return new Image(this);
    }

    public function newCaptcha() -> <Captcha>
    {
        return new Captcha(this);
    }

    abstract public function text(string text, array options = []) -> <Text>;
    abstract public function fromImage(<Image> im) -> <Image>;
    abstract public function fromSize(long width, long height = 0, string extension = "") -> <Image>;
    abstract public function fromPath(string path, string extension = "") -> <Image>;
    abstract public function fromString(string data, string extension = "") -> <Image>;
    abstract public function captcha(string text, long width, long height, array options = []) -> <Captcha>;

    abstract public function largest(<Image> im, long width, long height) -> <Image>;
    abstract public function resize(<Image> im, long width, long height) -> <Image>;
    abstract public function crop(<Image> im, long x, long y, long w, long h) -> <Image>;
    abstract public function thumbnail(<Image> im, long width, long height, bool cropped) -> <Image>;
    abstract public function draw(<Image> destIm, <ImageAbstract> srcIm, long x, long y) -> <Image>;

    abstract public function save(<Image> im, string destPath) -> void;
    abstract public function destroy(<ImageAbstract> im) -> void;

}
