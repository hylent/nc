namespace Nc\Mvc;

class ContextHttp extends ContextAbstract
{
    protected queries;
    protected posts;
    protected cookies;
    protected files;

    protected defaultCookieOptions;

    public function __construct() -> void
    {
        let this->serverVars = _SERVER;

        let this->queries = _GET;
        let this->posts = _POST;
        let this->cookies = _COOKIE;
        let this->files = _FILES;

        this->initArgVectorFromRequestUri();
    }

    public function getRoutingNames() -> array
    {
        return [
            "http"
        ];
    }

    public function getRawInput() -> string
    {
        return file_get_contents("php://input");
    }

    public function getParamMap() -> array
    {
        return array_replace(this->queries, this->posts);
    }

    public function getParam(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->queries[name] {
            return value;
        }

        if fetch value, this->posts[name] {
            return value;
        }

        return defaultValue;
    }

    public function getQuery(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->queries[name] {
            return value;
        }

        return defaultValue;
    }

    public function getPost(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->posts[name] {
            return value;
        }

        return defaultValue;
    }

    public function getCookie(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->cookies[name] {
            return value;
        }

        return defaultValue;
    }

    public function newUploadedFile(var error, var size, var name, var tmpName) -> <UploadedFile>
    {
        return new UploadedFile(error, size, name, tmpName);
    }

    public function hasUploadedFile(string index) -> boolean
    {
        var error;

        return fetch error, this->files[index]["error"] && is_numeric(error);
    }

    public function getUploadedFile(string index) -> <UploadedFile>
    {
        var a, error, size, name, tmpName;

        loop {
            if unlikely ! fetch a, this->files[index] || typeof a != "array" {
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

        throw new Exception(sprintf("Invalid uploaded file '%s'", index));
    }

    public function getUploadedFiles(string index) -> array
    {
        var files = [], a, errors, i, error, size, name, tmpName;

        if unlikely ! fetch a, this->files[index] && typeof a != "array" {
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

    public function getRequestMethod() -> string
    {
        return (string) this->getServerVar("REQUEST_METHOD", "UNKNOWN");
    }

    public function getRemoteAddr() -> string
    {
        return (string) this->getServerVar("REMOTE_ADDR", "0.0.0.0");
    }

    public function isXhr() -> boolean
    {
        return this->getServerVar("HTTP_X_REQUESTED_WITH") === "XMLHttpRequest";
    }

    public function getHttpHost() -> string
    {
        return (string) this->getServerVar("HTTP_HOST");
    }

    public function getHttpUserAgent() -> string
    {
        return (string) this->getServerVar("HTTP_USER_AGENT");
    }

    public function getHttpReferer() -> string
    {
        return (string) this->getServerVar("HTTP_REFERER");
    }

    public function setDefaultCookieOptions(array options) -> void
    {
        let this->defaultCookieOptions = array_merge(this->getDefaultCookieOptions(), options);
    }

    public function getDefaultCookieOptions() -> array
    {
        if this->defaultCookieOptions === null {
            let this->defaultCookieOptions = [
                "expire"    : 0,
                "path"      : "/",
                "domain"    : "",
                "secure"    : false,
                "httpOnly"  : false
            ];
        }

        return this->defaultCookieOptions;
    }

    public function status(long status) -> void
    {
        http_response_code(status);
    }

    public function cookie(string name, string value, array options = []) -> void
    {
        var a;

        let a = array_merge(this->getDefaultCookieOptions(), options);
        setcookie(name, value, a["expire"], a["path"], a["domain"], a["secure"], a["httpOnly"]);
    }

    public function header(string name, string value) -> void
    {
        header(name . ": " . value);
    }

    public function redirect(string url) -> void
    {
        this->header("Location", url);
    }

    public function sendFile(string path) -> void
    {
        readfile(path);
    }

    protected function initArgVectorFromRequestUri() -> void
    {
        var uri, pos;

        let uri = (string) this->getServerVar("REQUEST_URI");
        let pos = strpos(uri, "?");
        if pos !== false {
            let uri = (string) substr(uri, 0, pos);
        }

        let this->argVector = preg_split("#/+#", uri, null, PREG_SPLIT_NO_EMPTY);
    }

}
