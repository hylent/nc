namespace Nc\Image;

abstract class ImageAbstract implements ImageInterface
{
    protected defaults;

    public function setDefaults(array options) -> void
    {
        var k, v;

        for k, v in options {
            let this->defaults[k] = v;
        }
    }

    public function setDefault(string name, var value) -> void
    {
        let this->defaults[name] = value;
    }

    protected function validTextOptions(array options) -> array
    {
        var valid = [], merged, v, m = null;
        string s;
        long l;
        double d;

        if typeof this->defaults == "array" {
            let merged = array_merge(this->defaults, options);
        } else {
            let merged = options;
        }

        let valid["font"] = ImageInterface::DEFAULT_FONT;
        let valid["fontSize"] = ImageInterface::DEFAULT_FONT_SIZE;
        let valid["color"] = ImageInterface::DEFAULT_COLOR;
        let valid["red"] = ImageInterface::DEFAULT_RED;
        let valid["green"] = ImageInterface::DEFAULT_GREEN;
        let valid["blue"] = ImageInterface::DEFAULT_BLUE;
        let valid["opacity"] = ImageInterface::DEFAULT_OPACITY;
        let valid["padding"] = ImageInterface::DEFAULT_PADDING;

        if fetch v, merged["font"] {
            let s = (string) v;
            if s {
                let valid["font"] = s;
            }
        }
        if fetch v, merged["fontSize"] {
            let l = (long) v;
            if l > 7 {
                let valid["fontSize"] = l;
            }
        }
        if fetch v, merged["color"] {
            let s = (string) v;
            if s && preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})/", s, m) {
                let valid["color"] = s;
                let valid["red"] = (long) hexdec(m[1]);
                let valid["green"] = (long) hexdec(m[2]);
                let valid["blue"] = (long) hexdec(m[3]);
            }
        }
        if fetch v, merged["opacity"] {
            let d = (double) v;
            if d >= 0 && d <= 1 {
                let valid["opacity"] = d;
            }
        }
        if fetch v, merged["padding"] {
            let l = (long) v;
            if l >= 0 {
                let valid["padding"] = l;
            }
        }

        return valid;
    }

    protected function validCaptchaOptions(array options) -> array
    {
        var valid = [], merged, v;
        string s;
        double d;

        if typeof this->defaults == "array" {
            let merged = array_merge(this->defaults, options);
        } else {
            let merged = options;
        }

        let valid["font"] = ImageInterface::DEFAULT_FONT;
        let valid["rPadding"] = ImageInterface::DEFAULT_R_PADDING;
        let valid["rOverlap"] = ImageInterface::DEFAULT_R_OVERLAP;

        if fetch v, merged["font"] {
            let s = (string) v;
            if s {
                let valid["font"] = s;
            }
        }
        if fetch v, merged["rPadding"] {
            let d = (double) v;
            if d > 0 && d < 1 {
                let valid["rPadding"] = d;
            }
        }
        if fetch v, merged["rOverlap"] {
            let d = (double) v;
            if d > 0 && d < 1 {
                let valid["rOverlap"] = d;
            }
        }

        return valid;
    }
}
