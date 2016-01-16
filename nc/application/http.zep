namespace Nc\Application;

use Nc\Renderer\RendererInterface;

class Http extends ApplicationAbstract
{
    protected cookieOptions;

    protected responseStatus = 200;
    protected responseCookies;
    protected responseHeaders;

    protected renderer;

    public function getArgs() -> array
    {
        var uri, pos;

        let uri = (string) this->getServerVar("REQUEST_URI");
        let pos = strpos(uri, "?");
        if pos !== false {
            let uri = (string) substr(uri, 0, pos);
        }

        return preg_split("#/+#", uri, null, PREG_SPLIT_NO_EMPTY);
    }

    public function getParams() -> array
    {
        return _GET;
    }

    public function getParam(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _GET[name] {
            return value;
        }

        return defaultValue;
    }

    public function getPost(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _POST[name] {
            return value;
        }

        return defaultValue;
    }

    public function getRequest(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _REQUEST[name] {
            return value;
        }

        return defaultValue;
    }

    public function getCookie(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _COOKIE[name] {
            return value;
        }

        return defaultValue;
    }

    public function getInput() -> string
    {
        return (string) file_get_contents("php://input");
    }

    public function getScheme() -> string
    {
        return (string) this->getServerVar("REQUEST_SCHEME", "unknown");
    }

    public function isHttp() -> bool
    {
        return this->getServerVar("REQUEST_SCHEME") === "http";
    }

    public function isHttps() -> bool
    {
        return this->getServerVar("REQUEST_SCHEME") === "https";
    }

    public function getMethod() -> string
    {
        return (string) this->getServerVar("REQUEST_METHOD", "UNKNOWN");
    }

    public function isGet() -> bool
    {
        return this->getServerVar("REQUEST_METHOD") === "GET";
    }

    public function isPost() -> bool
    {
        return this->getServerVar("REQUEST_METHOD") === "POST";
    }

    public function isXhr() -> bool
    {
        return this->getServerVar("HTTP_X_REQUESTED_WITH") === "XMLHttpRequest";
    }

    public function getIp(string index = "REMOTE_ADDR") -> string
    {
        return (string) this->getServerVar(index, "0.0.0.0");
    }

    public function hasUploadedFile(string index) -> bool
    {
        var error;

        return fetch error, _FILES[index]["error"] && is_numeric(error);
    }

    public function getUploadedFile(string index) -> <UploadedFile>
    {
        var a, error, size, name, tmpName;

        loop {
            if unlikely ! fetch a, _FILES[index] || typeof a != "array" {
                break;
            }

            if unlikely ! fetch error, a["error"] || typeof error != "int" {
                break;
            }
            if unlikely ! fetch size, a["size"] || typeof size != "int" {
                break;
            }
            if unlikely ! fetch name, a["name"] || typeof name != "string" {
                break;
            }
            if unlikely ! fetch tmpName, a["tmp_name"] || typeof tmpName != "string" {
                break;
            }

            return this->newUploadedFile(error, size, name, tmpName);
        }

        throw new Exception("Invalid uploaded file: " . index);
    }

    public function getUploadedFiles(string index) -> array
    {
        var files = [], a, errors, i, error, size, name, tmpName;

        if unlikely ! fetch a, _FILES[index] && typeof a != "array" {
            return files;
        }

        if unlikely ! fetch errors, a["error"] && typeof errors != "array" {
            return files;
        }

        for i, error in errors {
            if unlikely ! fetch size, a["size"][i] || typeof size != "int" {
                continue;
            }
            if unlikely ! fetch name, a["name"][i] || typeof name != "string" {
                continue;
            }
            if unlikely ! fetch tmpName, a["tmp_name"][i] || typeof tmpName != "string" {
                continue;
            }

            let files[i] = this->newUploadedFile(error, size, name, tmpName);
        }

        return files;
    }

    public function cookieOptions() -> array
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

    public function setCookieOptions(array cookieOptions) -> void
    {
        let this->cookieOptions = array_merge(this->cookieOptions(), cookieOptions);
    }

    public function responseStatus() -> long
    {
        return this->responseStatus;
    }

    public function setResponseStatus(long responseStatus) -> void
    {
        let this->responseStatus = responseStatus;
    }

    public function sendResponseStatus() -> void
    {
        long responseStatus;

        let responseStatus = (long) this->responseStatus;
        if responseStatus != 200 {
            http_response_code(responseStatus);
        }
    }

    public function responseCookie(string name)
    {
        var cookie;

        if fetch cookie, this->responseCookies[name] {
            return cookie;
        }
    }

    public function responseCookies() -> array
    {
        if count(this->responseCookies) > 0 {
            return this->responseCookies;
        }

        return [];
    }

    public function setResponseCookie(string name, string value, array options = []) -> void
    {
        let options["name"] = name;
        let options["value"] = value;

        let this->responseCookies[name] = options;
    }

    public function hasResponseCookie(string name) -> bool
    {
        return isset this->responseCookies[name];
    }

    public function removeResponseCookie(string name) -> void
    {
        unset this->responseCookies[name];
    }

    public function clearResponseCookies() -> void
    {
        let this->responseCookies = null;
    }

    public function sendResponseCookies() -> void
    {
        var cookieOptions, cookie;

        let cookieOptions = this->cookieOptions();

        for cookie in this->responseCookies() {
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

        this->clearResponseCookies();
    }

    public function responseHeaders() -> array
    {
        if count(this->responseHeaders) > 0 {
            return this->responseHeaders;
        }

        return [];
    }

    public function setResponseHeader(string name, string value) -> void
    {
        let this->responseHeaders[name->lower()] = name . ": " . value;
    }

    public function setResponseHeaders(array responseHeaders) -> void
    {
        var name, value;

        for name, value in responseHeaders {
            let this->responseHeaders[strtolower(name)] = name . ": " . value;
        }
    }

    public function addResponseHeader(string name, string value) -> void
    {
        var newHeaders;

        let newHeaders = [];
        let newHeaders[name->lower()] = name . ": " . value;

        let this->responseHeaders = array_merge_recursive(this->responseHeaders(), newHeaders);
    }

    public function hasResponseHeader(string name) -> bool
    {
        return isset this->responseHeaders[name];
    }

    public function removeResponseHeader(string name) -> void
    {
        unset this->responseHeaders[name];
    }

    public function clearResponseHeaders() -> void
    {
        let this->responseHeaders = null;
    }

    public function sendResponseHeaders() -> void
    {
        var headerGroup, header;

        for headerGroup in this->responseHeaders() {
            if typeof headerGroup == "array" {
                for header in headerGroup {
                    header(header);
                }
            } else {
                header(headerGroup);
            }
        }

        this->clearResponseHeaders();
    }

    public function __invoke() -> void
    {
        var renderer;

        let renderer = this->renderer();
        renderer->withHttp(this);

        this->sendResponseStatus();
        this->sendResponseCookies();
        this->sendResponseHeaders();

        renderer->render();
    }

}
