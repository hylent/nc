namespace Nc\Application;

use Nc\Renderer\RendererInterface;

class ResponseHttp extends ResponseAbstract
{
    protected redirect  = "";
    protected status    = 200;
    protected headers   = [];
    protected renderer;

    public function setStatus(long status = 200) -> void
    {
        let this->status = status;
    }

    public function getStatus() -> long
    {
        return this->status;
    }

    public function addHeader(string header) -> void
    {
        let this->headers[] = header;
    }

    public function addHeaders(array headers) -> void
    {
        var header;

        for header in headers {
            let this-> headers[] = (string) header;
        }
    }

    public function getHeaders() -> array
    {
        return this->headers;
    }

    public function clearHeaders() -> void
    {
        let this->headers = [];
    }

    public function setRedirect(string redirect) -> void
    {
        let this->redirect = redirect;
    }

    public function getRedirect() -> string
    {
        return this->redirect;
    }

    public function setRenderer(<RendererInterface> renderer) -> void
    {
        let this->renderer = renderer;
    }

    public function getRenderer() -> <RendererInterface>
    {
        return this->renderer;
    }

    public function __invoke() -> void
    {
        string redirect;
        long status;
        var header, renderer;

        let redirect = (string) this->redirect;
        if redirect->length() > 0 {
            header("Location: " . redirect);
            return;
        }

        let status = (long) this->status;
        if status != 200 {
            http_response_code(status);
        }

        for header in this->headers {
            header(header);
        }

        let renderer = this->renderer;
        if typeof renderer == "object" && (renderer instanceof RendererInterface) {
            for header in renderer->getExtraHeaders() {
                header(header);
            }
            renderer->render();
            return;
        }

        parent::__invoke();
    }

}
