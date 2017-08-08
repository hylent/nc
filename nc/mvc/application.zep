namespace Nc\Mvc;

use Nc\Di\Injector;

class Application
{
    protected autoloads;
    protected routingRules;

    public static function autoloadCompareFunction(string a, string b) -> long
    {
        return strlen(b) - strlen(a);
    }

    public function __construct(array autoloads, array routingRules) -> void
    {
        var a, k, v;

        let a = [];
        for k, v in autoloads {
            let a[strtolower(k) . "\\"] = v;
        }
        if count(a) > 1 {
            uksort(a, __CLASS__ . "::autoloadCompareFunction");
        }
        let this->autoloads = a;

        spl_autoload_register([this, "autoload"], false, true);

        let a = [];
        for k, v in routingRules {
            let a[substr_count(k, "/")][k] = v;
        }
        if count(a) > 1 {
            krsort(a, SORT_NUMERIC);
        }
        let this->routingRules = a;
    }

    public function __destruct() -> void
    {
        spl_autoload_unregister([this, "autoload"]);
    }

    public function autoload(string name) -> boolean
    {
        var lcName, p, d, path;

        if count(this->autoloads) > 0 {
            let lcName = name->lower();

            for p, d in this->autoloads {
                if strpos(lcName, p) === 0 {
                    let path = d . "/" . strtr(substr(name, strlen(p)), "\\", "/") . ".php";

                    if file_exists(path) {
                        require path;
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public function __invoke(<ContextAbstract> context = null) -> void
    {
        var injector, controllerClass;

        // Fix context
        if context === null {
            if PHP_SAPI == "cli" {
                let context = new ContextCli();
            } else {
                let context = new ContextHttp();
            }
        }

        // Route context
        let controllerClass = this->route(context);
        if strlen(controllerClass) < 1 {
            throw new Exception(__FUNCTION__, 404);
        }

        // Init injector
        let injector = new Injector();

        // Invoke controller
        injector->__invoke(controllerClass, ControllerInterface::TYPE)->__invoke(injector, context);
    }

    public function onSwooleRequest(<\Swoole_Http_Request> req, <\Swoole_Http_Response> resp) -> void
    {
        var ex = null;

        try {
            this->__invoke(new ContextHttpSwoole(req, resp));
        } catch \Exception, ex {
            file_put_contents("php://stderr", ex . PHP_EOL);
        }

        resp->end();

        if session_status() == PHP_SESSION_ACTIVE {
            session_write_close();
        }
    }

    protected function route(<ContextAbstract> context) -> string
    {
        var args, numArgs, routingNames, n, rules, uri, routingName, controllerClass;

        let args = context->getArgVector();
        let numArgs = count(args);

        if count(this->routingRules) > 0 {
            let routingNames = context->getRoutingNames();
            for n, rules in this->routingRules {
                if n > numArgs {
                    continue;
                }
                if n > 0 {
                    let uri = "/" . implode("/", array_slice(args, 0, n));
                } else {
                    let uri = "";
                }
                for routingName in routingNames {
                    if fetch controllerClass, rules[routingName . uri] {
                        context->setNumUsedArgs(n);
                        return controllerClass;
                    }
                }
            }
        }

        return "";
    }
}
