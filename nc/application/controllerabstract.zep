namespace Nc\Application;

use Nc\Std;
use Nc\Factory\FactoryInterface;

abstract class ControllerAbstract
{
    protected di;

    public static function dispatch(<FactoryInterface> controllerFactory, array params) -> void
    {
        string controller, controllerName;
        var controllerVar;

        if count(params) > 0 {
            let controller = (string) array_shift(params);
        } else {
            let controller = "index";
        }

        let controllerName = (string) Std::camelCase(controller);
        if unlikely ! controllerFactory->__isset(controllerName) {
            throw new NotFoundException("Controller not found: " . controller);
        }

        let controllerVar = controllerFactory->__get(controllerName);
        if unlikely ! is_callable(controllerVar) {
            throw new Exception("Invalid controller: " . controller);
        }

        call_user_func(controllerVar, params);
    }

    public function __construct(<FactoryInterface> di) -> void
    {
        let this->di = di;
    }

    public function __invoke(array params) -> void
    {
        string action;
        var actionVar;

        if count(params) > 0 {
            let action = (string) array_shift(params);
        } else {
            let action = "index";
        }

        let actionVar = [];
        let actionVar[] = this;
        let actionVar[] = Std::camelCase(action) . "Action";

        if unlikely ! is_callable(actionVar) {
            throw new NotFoundException("Controller action not found: " . action);
        }

        call_user_func_array(actionVar, params);
    }

    protected function getServer(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _SERVER[name] {
            return value;
        }

        return defaultValue;
    }

}
