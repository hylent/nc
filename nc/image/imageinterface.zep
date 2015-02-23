namespace Nc\Image;

interface ImageInterface
{
    const DEFAULT_FONT = "nc.ttf";
    const DEFAULT_FONT_SIZE = 24;
    const DEFAULT_COLOR = "#000000";
    const DEFAULT_RED = 0;
    const DEFAULT_GREEN = 0;
    const DEFAULT_BLUE = 0;
    const DEFAULT_OPACITY = 0.5;
    const DEFAULT_PADDING = 5;
    const DEFAULT_R_PADDING = 0.2;
    const DEFAULT_R_OVERLAP = 0.2;

    const LEFT_TOP = 7;
    const TOP = 8;
    const RIGHT_TOP = 9;
    const LEFT = 4;
    const CENTER = 5;
    const RIGHT = 6;
    const LEFT_BOTTOM = 1;
    const BOTTOM = 2;
    const RIGHT_BOTTOM = 3;

    public function text(string text, array options = []) -> <Item\Text>;
    public function captcha(string code, long width, long height, array options = []) -> <Item\Image>;
    public function fromImage(<Item\Image> im) -> <Item\Image>;
    public function fromSize(long width, long height = 0, string extension = "") -> <Item\Image>;
    public function fromPath(string path, string extension = "") -> <Item\Image>;
    public function fromString(string data, string extension = "") -> <Item\Image>;

    public function resize(<Item\Image> im, long width, long height) -> <Item\Image>;
    public function crop(<Item\Image> im, long x, long y, long w, long h) -> <Item\Image>;
    public function thumbnail(<Item\Image> im, long width, long height, boolean cropped) -> <Item\Image>;
    public function draw(<Item\Image> destIm, <Item\ImageItemAbstract> srcIm, long x, long y) -> <Item\Image>;

    public function save(<Item\Image> im, var destPath) -> void;
    public function destroy(<Item\ImageItemAbstract> im) -> void;
}
