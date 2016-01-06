namespace Nc\Image;

class Captcha extends Image
{
    public text     = "";

    public font     = ImageBackendAbstract::DEFAULT_FONT;
    public rPadding = ImageBackendAbstract::DEFAULT_R_PADDING;
    public rOverlap = ImageBackendAbstract::DEFAULT_R_OVERLAP;

    public function setOptions(array options) -> void
    {
        var mergedOptions, opt;
        string s;
        double d;

        let mergedOptions = array_merge(this->backend->getDefaultOptions(), options);

        if fetch opt, mergedOptions["font"] {
            let s = (string) opt;
            if s->length() > 0 {
                let this->font = s;
            }
        }

        if fetch opt, mergedOptions["rPadding"] {
            let d = (double) opt;
            if d > 0 && d < 1 {
                let this->rPadding = d;
            }
        }

        if fetch opt, mergedOptions["rOverlap"] {
            let d = (double) opt;
            if d > 0 && d < 1 {
                let this->rOverlap = d;
            }
        }
    }

}
