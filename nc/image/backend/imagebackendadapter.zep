namespace Nc\Image\Backend;

abstract class ImageBackendAdapter implements ImageBackendInterface
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

        let valid["font"] = ImageBackendInterface::DEFAULT_FONT;
        let valid["fontSize"] = ImageBackendInterface::DEFAULT_FONT_SIZE;
        let valid["color"] = ImageBackendInterface::DEFAULT_COLOR;
        let valid["red"] = ImageBackendInterface::DEFAULT_RED;
        let valid["green"] = ImageBackendInterface::DEFAULT_GREEN;
        let valid["blue"] = ImageBackendInterface::DEFAULT_BLUE;
        let valid["opacity"] = ImageBackendInterface::DEFAULT_OPACITY;
        let valid["padding"] = ImageBackendInterface::DEFAULT_PADDING;

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

        let valid["font"] = ImageBackendInterface::DEFAULT_FONT;
        let valid["rPadding"] = ImageBackendInterface::DEFAULT_R_PADDING;
        let valid["rOverlap"] = ImageBackendInterface::DEFAULT_R_OVERLAP;

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
