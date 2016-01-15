namespace Nc\Http;

use Nc\Renderer\RendererInterface;
use Nc\Renderer\Nil;

class Response
{
    protected status = 200;

    protected cookieOptions;
    protected cookies;
    protected headers;
    protected renderer;

    public function status(long status) -> void
    {
        let this->status = status;
    }

    public function getStatus() -> long
    {
        return this->status;
    }

    public function setCookieOptions(array cookieOptions) -> void
    {
        let this->cookieOptions = array_merge(this->getCookieOptions(), cookieOptions);
    }

    public function getCookieOptions() -> array
    {
        if count(this->cookieOptions) < 1 {
            let this->cookieOptions = [
                "expire"    : 0,
                "path"      : "/",
                "domain"    : "",
                "secure"    : false,
                "httpOnly"  : false
            ];
        }

        return this->cookieOptions;
    }

    public function cookie(string name, string value, array options = []) -> void
    {
        let options["name"] = name;
        let options["value"] = value;

        let this->cookies[name] = options;
    }

    public function hasCookie(string name) -> bool
    {
        return isset this->cookies[name];
    }

    public function removeCookie(string name) -> void
    {
        unset this->cookies[name];
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
        if count(this->cookies) > 0 {
            return this->cookies;
        }

        return [];
    }

    public function clearCookies() -> void
    {
        let this->cookies = null;
    }

    public function header(string name, string value) -> void
    {
        let this->headers[name->lower()] = name . ": " . value;
    }

    public function headers(array headers) -> void
    {
        var name, value;

        for name, value in headers {
            let this->headers[strtolower(name)] = name . ": " . value;
        }
    }

    public function addHeader(string name, string value) -> void
    {
        var newHeaders;

        let newHeaders = [];
        let newHeaders[name->lower()] = name . ": " . value;

        let this->headers = array_merge_recursive(this->getHeaders(), newHeaders);
    }

    public function hasHeader(string name) -> bool
    {
        return isset this->headers[name];
    }

    public function removeHeader(string name) -> void
    {
        unset this->headers[name];
    }

    public function getHeaders() -> array
    {
        if count(this->headers) > 0 {
            return this->headers;
        }

        return [];
    }

    public function clearHeaders() -> void
    {
        let this->headers = null;
    }

    public function renderer(<RendererInterface> renderer) -> void
    {
        let this->renderer = renderer;
    }

    public function getRenderer() -> <RendererInterface>
    {
        if this->renderer === null {
            let this->renderer = new Nil();
        }

        return this->renderer;
    }

    public function __invoke() -> void
    {
        var renderer, cookieOptions, cookie, headerGroup, header;
        long status;

        let renderer = this->getRenderer();
        renderer->withResponse(this);

        let status = (long) this->status;
        if status != 200 {
            http_response_code(status);
        }

        let cookieOptions = this->getCookieOptions();
        for cookie in this->getCookies() {
            let cookie = array_merge(cookieOptions, cookie);
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

        for headerGroup in this->getHeaders() {
            if typeof headerGroup == "array" {
                for header in headerGroup {
                    header(header);
                }
            } else {
                let header = (string) headerGroup;
                header(header);
            }
        }

        renderer->render();
    }

}
