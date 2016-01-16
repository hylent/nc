namespace Nc\Renderer;

use Nc\Http\Response;

class Redirect extends RendererAbstract
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
        string u, q;

        let u = (string) this->redirectUrl;
        let q = (string) http_build_query(this->getData());

        if q->length() > 0 {
            if u->index("?") === false {
                let u .= "?" . q;
            } else {
                let u .= "&" . q;
            }
        }

        response->header("Location", u);
    }

    public function render() -> void
    {
        return;
    }

}
