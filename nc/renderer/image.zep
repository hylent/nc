namespace Nc\Renderer;

use Nc\Image\Image;
use Nc\Http\Response;

class Image implements RendererInterface
{
    protected image;

    public function __construct(<Image> image) -> void
    {
        let this->image = image;
    }

    public function withResponse(<Response> response) -> void
    {
        var image, headers = [];
        string imageContent;

        let image = this->image;
        let imageContent = (string) image->__toString();
        let this->image = imageContent;

        let headers["Content-Type"] = image->mimeType();
        let headers["Content-Length"] = strlen(imageContent);

        response->headers(headers);
    }

    public function render() -> void
    {
        echo (string) this->image;
    }

}
