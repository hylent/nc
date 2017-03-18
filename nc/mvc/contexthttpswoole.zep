namespace Nc\Mvc;

class ContextHttpSwoole extends ContextHttp
{
    protected swooleRequest;
    protected swooleResponse;

    public function __construct(<\Swoole_Http_Request> swooleRequest, <\Swoole_Http_Response> swooleResponse) -> void
    {
        var a, k, v;

        if unlikely ! extension_loaded("swoole") {
            throw new Exception("ExtensionMissing swoole");
        }

        let this->swooleRequest = swooleRequest;
        let this->swooleResponse = swooleResponse;

        let this->serverVars = _SERVER;
        let this->serverVars["SWOOLE_FD"] = swooleRequest->fd;

        if fetch a, swooleRequest->server && typeof a == "array" {
            for k, v in a {
                let this->serverVars[strtoupper(k)] = v;
            }
        }
        if fetch a, swooleRequest->header && typeof a == "array" {
            for k, v in a {
                let this->serverVars["HTTP_" . strtoupper(strtr(k, "-", "_"))] = v;
            }
        }

        if fetch a, swooleRequest->get && typeof a == "array" {
            let this->queries = a;
        } else {
            let this->queries = [];
        }
        if fetch a, swooleRequest->post && typeof a == "array" {
            let this->posts = a;
        } else {
            let this->posts = [];
        }
        if fetch a, swooleRequest->cookie && typeof a == "array" {
            let this->cookies = a;
        } else {
            let this->cookies = [];
        }
        if fetch a, swooleRequest->files && typeof a == "array" {
            let this->files = a;
        } else {
            let this->files = [];
        }

        this->initArgVectorFromRequestUri();
    }

    public function getRoutingNames() -> array
    {
        return [
            "http.swoole",
            "http"
        ];
    }

    public function getSwooleRequest() -> <\Swoole_Http_Request>
    {
        return this->swooleRequest;
    }

    public function getSwooleResponse() -> <\Swoole_Http_Response>
    {
        return this->swooleResponse;
    }

    public function getRawInput() -> string
    {
        return this->swooleRequest->rawContent();
    }

    public function status(long status) -> void
    {
        this->swooleResponse->status(status);
    }

    public function cookie(string name, string value, array options = []) -> void
    {
        var a;

        let a = array_merge(this->getDefaultCookieOptions(), options);
        this->swooleResponse->cookie(name, value, a["expire"], a["path"], a["domain"], a["secure"], a["httpOnly"]);
    }

    public function header(string name, string value) -> void
    {
        this->swooleResponse->header(name, value);
    }

    public function sendFile(string path) -> void
    {
        this->swooleResponse->sendFile(path);
    }

    public function output(string content) -> void
    {
        this->swooleResponse->write(content);
    }

}
