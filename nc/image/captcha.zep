namespace Nc\Image;

class Captcha extends Image
{
    public text;

    public font         = ImageBackendAbstract::DEFAULT_FONT;
    public paddingRatio = ImageBackendAbstract::DEFAULT_CAPTCHA_PADDING_RATIO;
    public overlapRatio = ImageBackendAbstract::DEFAULT_CAPTCHA_OVERLAP_RATIO;

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

        if fetch opt, mergedOptions["captchaPaddingRatio"] {
            let d = (double) opt;
            if d > 0 && d < 1 {
                let this->paddingRatio = d;
            }
        }

        if fetch opt, mergedOptions["captchaOverlapRatio"] {
            let d = (double) opt;
            if d > 0 && d < 1 {
                let this->overlapRatio = d;
            }
        }
    }

}
