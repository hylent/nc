namespace Nc\Renderer;

use Nc\Image\Image;

class Image extends RendererAbstract
{
    protected imageContent;

    public function __construct(<Image> image) -> void
    {
        string imageContent;

        let imageContent = (string) image->__toString();
        let this->imageContent = imageContent;

        let this->extraHeaders["content-type"] = "Content-Type: " . image->mimeType();
        let this->extraHeaders["content-length"] = "Content-Length: " . strlen(imageContent);
    }

    public function render() -> void
    {
        echo this->imageContent;
    }

}
