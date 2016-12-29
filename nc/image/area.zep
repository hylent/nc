namespace Nc\Image;

class Area
{
    public x;
    public y;
    public w;
    public h;

    public function __construct(long x, long y, long w, long h) -> void
    {
        let this->x = x;
        let this->y = y;
        let this->w = w;
        let this->h = h;
    }
}
