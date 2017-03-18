namespace Nc\Mvc;

use Nc\Di\Injector;

class ControllerCliSwoole implements ControllerInterface
{
    public function __invoke(<Injector> injector, <ContextAbstract> context) -> void
    {
        var dbg, obj, opts, serv;

        if unlikely ! extension_loaded("swoole") {
            throw new Exception("ExtensionMissing swoole");
        }

        let dbg = debug_backtrace(DEBUG_BACKTRACE_IGNORE_ARGS | DEBUG_BACKTRACE_PROVIDE_OBJECT, 2);
        if unlikely ! fetch obj, dbg[1]["object"] || typeof obj != "object" || ! (obj instanceof Application) {
            throw new Exception(__FUNCTION__);
        }

        let opts = array_merge(
            [
                "host"          : "127.0.0.1",
                "port"          : 9527,
                "daemonize"     : 1,
                "max_request"   : 32
            ],
            context->getParamMap()
        );

        let serv = new \Swoole_Http_Server(opts["host"], opts["port"]);

        serv->set(opts);
        serv->on("request", [obj, "onSwooleRequest"]);

        serv->start();
    }
}
