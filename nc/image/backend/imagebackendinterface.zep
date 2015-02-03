namespace Nc\Image\Backend;

use Nc\Image\Item;
use Nc\Image\Text;
use Nc\Image\Image;

interface ImageBackendInterface
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

    public function text(string text, array options = []) -> <Text>;
    public function captcha(string code, long width, long height, array options = []) -> <Image>;
    public function fromImage(<Image> im) -> <Image>;
    public function fromSize(long width, long height = 0, string extension = "") -> <Image>;
    public function fromPath(string path, string extension = "") -> <Image>;
    public function fromString(string data, string extension = "") -> <Image>;

    public function resize(<Image> im, long width, long height) -> <Image>;
    public function crop(<Image> im, long x, long y, long w, long h) -> <Image>;
    public function thumbnail(<Image> im, long width, long height, boolean cropped) -> <Image>;
    public function draw(<Image> destIm, <Item> srcIm, long x, long y) -> <Image>;

    public function save(<Image> im, var destPath) -> void;
    public function destroy(<Item> im) -> void;
}
