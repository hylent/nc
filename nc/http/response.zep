namespace Nc\Http;

use Nc\Renderer\RendererInterface;

class Response
{
    protected defaultCookieOptions  = [
        "expire"    : 0,
        "path"      : "/",
        "domain"    : "",
        "secure"    : false,
        "httpOnly"  : false
    ];

    protected redirect  = "";
    protected status    = 200;
    protected cookies   = [];
    protected renderer  = null;
    protected headers   = [];
    protected content   = "";

    public function setDefaultCookieOptions(array defaultCookieOptions) -> void
    {
        let this->defaultCookieOptions = array_merge(this->defaultCookieOptions, defaultCookieOptions);
    }

    public function getDefaultCookieOptions() -> array
    {
        return this->defaultCookieOptions;
    }

    public function redirect(string redirect) -> void
    {
        let this->redirect = redirect;
    }

    public function getRedirect() -> string
    {
        return this->redirect;
    }

    public function status(long status) -> void
    {
        let this->status = status;
    }

    public function getStatus() -> long
    {
        return this->status;
    }

    public function cookie(string name, string value, array options = []) -> void
    {
        let options["name"] = name;
        let options["value"] = value;

        let this->cookies[name] = options;
    }

    public function getCookie(string name)
    {
        var cookie;

        if fetch cookie, this->cookies[name] {
            return cookie;
        }
    }

    public function getCookies() -> array
    {
        return this->cookies;
    }

    public function clearCookies() -> void
    {
        let this->cookies = [];
    }

    public function renderer(<RendererInterface> renderer = null) -> void
    {
        let this->renderer = renderer;
    }

    public function getRenderer() -> <RendererInterface>
    {
        return this->renderer;
    }

    public function header(string header, string exclusionName = "") -> void
    {
        if exclusionName->length() > 0 {
            let this->headers[exclusionName] = header;
        } else {
            let this->headers[] = header;
        }
    }

    public function addHeaders(array headers) -> void
    {
        let this->headers = array_merge(this->headers, headers);
    }

    public function getHeaders() -> array
    {
        return this->headers;
    }

    public function clearHeaders() -> void
    {
        let this->headers = [];
    }

    public function content(string content) -> void
    {
        let this->content = content;
    }

    public function addContent(string content) -> void
    {
        let this->content = this->content . content;
    }

    public function getContent() -> string
    {
        return this->content;
    }

    public function __invoke() -> void
    {
        string redirect;
        long status;
        var cookie, renderer, headers, header;

        let redirect = (string) this->redirect;
        if redirect->length() > 0 {
            header("Location: " . redirect);
            return;
        }

        let status = (long) this->status;
        if status != 200 {
            http_response_code(status);
        }

        for cookie in this->cookies {
            let cookie = array_merge(this->defaultCookieOptions, cookie);
            setcookie(
                cookie["name"],
                cookie["value"],
                cookie["expire"],
                cookie["path"],
                cookie["domain"],
                cookie["secure"],
                cookie["httpOnly"]
            );
        }

        let renderer = this->renderer;
        if typeof renderer == "object" && (renderer instanceof RendererInterface) {
            let headers = array_merge(this->headers, renderer->getExtraHeaders());
            for header in headers {
                header(header);
            }
            renderer->render();
            return;
        }

        for header in this->headers {
            header(header);
        }

        echo this->content;
    }

}
