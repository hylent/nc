namespace Nc\Renderer;

use Nc\Http\Response;

class Redirect implements RendererInterface
{
    protected redirectUrl;

    public function __construct(string redirectUrl) -> void
    {
        let this->redirectUrl = redirectUrl;
    }

    public function getRedirectUrl() -> string
    {
        return this->redirectUrl;
    }

    public function withResponse(<Response> response) -> void
    {
        response->header("Location", this->redirectUrl);
    }

    public function render() -> void
    {
        return;
    }

}
