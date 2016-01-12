namespace Nc\Image;

class Text extends ImageAbstract
{
    public text;

    public font     = ImageBackendAbstract::DEFAULT_FONT;
    public fontSize = ImageBackendAbstract::DEFAULT_TEXT_FONT_SIZE;
    public color    = ImageBackendAbstract::DEFAULT_TEXT_COLOR;
    public shadow   = ImageBackendAbstract::DEFAULT_TEXT_SHADOW;
    public opacity  = ImageBackendAbstract::DEFAULT_TEXT_OPACITY;
    public padding  = ImageBackendAbstract::DEFAULT_TEXT_PADDING;

    public function setOptions(array options) -> void
    {
        var mergedOptions, opt, m = null;
        string s;
        long l;
        double d;

        let mergedOptions = array_merge(this->backend->getDefaultOptions(), options);

        if fetch opt, mergedOptions["font"] {
            let s = (string) opt;
            if s->length() > 0 {
                let this->font = s;
            }
        }

        if fetch opt, mergedOptions["textFontSize"] {
            let l = (long) opt;
            if l > 7 {
                let this->fontSize = l;
            }
        }

        if fetch opt, mergedOptions["textColor"] {
            let s = (string) opt;
            if s->length() > 0 && preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/", s, m) {
                let this->color = s->upper();
            }
        }

        if fetch opt, mergedOptions["textShadow"] {
            let s = (string) opt;
            if s->length() > 0 && preg_match("/^#([0-9a-fA-F]{2})([0-9a-fA-F]{2})([0-9a-fA-F]{2})$/", s, m) {
                let this->shadow = s->upper();
            }
        }

        if fetch opt, mergedOptions["textOpacity"] {
            let d = (double) opt;
            if d >= 0 && d <= 1 {
                let this->opacity = d;
            }
        }

        if fetch opt, mergedOptions["textPadding"] {
            let l = (long) opt;
            if l >= 0 {
                let this->padding = l;
            }
        }
    }

}
