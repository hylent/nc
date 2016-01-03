namespace Nc\Application;

use Nc\Renderer\RendererInterface;

class Http extends ApplicationAbstract
{
    protected redirect  = "";
    protected status    = 200;
    protected headers   = [];
    protected renderer;

    public function __construct() -> void
    {
        string uri;
        var pos;

        let this->params = _REQUEST;

        let uri = (string) this->serverVar("REQUEST_URI", "/");
        let pos = strpos(uri, "?");
        if pos !== false {
            let uri = (string) substr(uri, 0, pos);
        }

        let this->routingParams = preg_split("#/+#", uri, null, PREG_SPLIT_NO_EMPTY);
    }

    public function requestMethod() -> string
    {
        return (string) this->serverVar("REQUEST_METHOD", "UNKNOWN");
    }

    public function ip(string index = "REMOTE_ADDR") -> string
    {
        return (string) this->serverVar(index, "0.0.0.0");
    }

    public function isXhr() -> bool
    {
        return this->serverVar("HTTP_X_REQUESTED_WITH") === "XMLHttpRequest";
    }

    public function query(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _GET[name] {
            return value;
        }

        return defaultValue;
    }

    public function post(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _POST[name] {
            return value;
        }

        return defaultValue;
    }

    public function cookie(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _COOKIE[name] {
            return value;
        }

        return defaultValue;
    }

    public function hasUploadedFile(string index) -> bool
    {
        return isset _FILES[index];
    }

    public function uploadedFile(string index) -> <UploadedFile>
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

    public function uploadedFiles(string index) -> array
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

    public function setRedirect(string redirect) -> void
    {
        let this->redirect = redirect;
    }

    public function getRedirect() -> string
    {
        return this->redirect;
    }

    public function setStatus(long status) -> void
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

    public function setRenderer(<RendererInterface> renderer = null) -> void
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
