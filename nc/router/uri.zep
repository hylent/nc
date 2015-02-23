namespace Nc\Router;

class Uri extends RouterAbstract
{
    protected baseUri;

    public function __construct(string uri, string baseUri) -> void
    {
        long len;
        var m = null, params;

        let len = baseUri->length();
        if len > 0 {
            if unlikely strpos(uri, baseUri) !== 0 {
                throw new Exception("Invalid base uri: " . baseUri);
            }
            let uri = (string) substr(uri, len);
        }

        let this->baseUri = baseUri;

        if preg_match("/^([^\\.\\?]+)/", uri, m) {
            let params = preg_split("#/+#", (string) m[1], null, PREG_SPLIT_NO_EMPTY);
        } else {
            let params = [];
        }

        switch count(params) {
            case 0:
                let this->controller = RouterInterface::DEFAULT_CONTROLLER;
                let this->action = RouterInterface::DEFAULT_ACTION;
                break;
            case 1:
                let this->controller = array_shift(params);
                let this->action = RouterInterface::DEFAULT_ACTION;
                break;
            default:
                let this->controller = array_shift(params);
                let this->action = array_shift(params);
                break;
        }

        let this->params = params;
    }

    public function getBaseUri() -> string
    {
        return this->baseUri;
    }

    public function __invoke() -> string
    {
        var args, controller, action;

        let args = func_get_args();

        if count(args) == 0 {
            return this->baseUri;
        }

        if fetch controller, args[0] && controller === null {
            let args[0] = this->controller;
        }
        if fetch action, args[1] && action === null {
            let args[1] = this->action;
        }

        return this->baseUri . join("/", args);
    }
}
