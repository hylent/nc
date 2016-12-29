namespace Nc\Image;

interface ImageInterface
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

    public function bySize(long w, long h = 0, string extension = "png") -> <ImageInterface>;
    public function byString(string data, string extension = "png") -> <ImageInterface>;
    public function byPath(string path) -> <ImageInterface>;
    public function byImage(<ImageInterface> im) -> <ImageInterface>;

    public function copy() -> <ImageInterface>;

    public function getWidth() -> long;
    public function getHeight() -> long;
    public function getExtension() -> string;
    public function getMimeType() -> string;

    public function largest(long w, long h) -> <ImageInterface>;
    public function resize(long w, long h = 0) -> <ImageInterface>;
    public function thumbnail(long w, long h = 0) -> <ImageInterface>;
    public function cropThumbnail(long w, long h = 0) -> <ImageInterface>;
    public function crop(long x, long y, long w, long h = 0) -> <ImageInterface>;

    public function paste(<ImageInterface> im, long x, long y = -2147483647) -> <ImageInterface>;
    public function annotate(string text, array options, long x, long y = -2147483647) -> <ImageInterface>;
    public function queryTextArea(string text, string font, long fontSize, long padding = 0) -> <Area>;

    public function save(string path) -> void;
    public function toString() -> string;
    public function __toString() -> string;

}
