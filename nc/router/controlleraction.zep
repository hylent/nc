namespace Nc\Router;

use Nc\Factory\FactoryInterface;
use Nc\Std;

class ControllerAction extends RouterAbstract
{
    const DEFAULT_CONTROLLER    = "index";
    const DEFAULT_ACTION        = "index";
    const DEFAULT_ACTION_SUFFIX = "Action";

    protected controllerFactory;
    protected defaultController = self::DEFAULT_CONTROLLER;
    protected defaultAction     = self::DEFAULT_ACTION;
    protected actionSuffix      = self::DEFAULT_ACTION_SUFFIX;

    public function __construct(<FactoryInterface> controllerFactory) -> void
    {
        let this->controllerFactory = controllerFactory;
    }

    public function getControllerFactory() -> <FactoryInterface>
    {
        return this->controllerFactory;
    }

    public function setDefaultController(string defaultController) -> void
    {
        let this->defaultController = defaultController;
    }

    public function getDefaultController() -> string
    {
        return this->defaultController;
    }

    public function setDefaultAction(string defaultAction) -> void
    {
        let this->defaultAction = defaultAction;
    }

    public function getDefaultAction() -> string
    {
        return this->defaultAction;
    }

    public function setActionSuffix(string actionSuffix) -> void
    {
        let this->actionSuffix = actionSuffix;
    }

    public function getActionSuffix() -> string
    {
        return this->actionSuffix;
    }

    public function route() -> void
    {
        var source, actionVar;
        string controller, action, controllerName, actionName;

        let source = (array) this->getSource();

        switch count(source) {
            case 0:
                let controller = (string) this->defaultController;
                let action = (string) this->defaultAction;
                break;
            case 1:
                let controller = (string) array_shift(source);
                let action = (string) this->defaultAction;
                break;
            default:
                let controller = (string) array_shift(source);
                let action = (string) array_shift(source);
                break;
        }

        let this->id = controller . "/" . action;

        let controllerName = (string) Std::camelCase(controller);
        let actionName = (string) Std::camelCase(action);

        if unlikely ! this->controllerFactory->__isset(actionName) {
            throw new NotFoundException("Controller not found: " . controller);
        }

        let actionVar = [];
        let actionVar[] = this->controllerFactory->__get(controllerName);
        let actionVar[] = actionName . this->actionSuffix;

        if unlikely ! is_callable(actionVar) {
            throw new NotFoundException("Invalid action: " . this->id);
        }

        call_user_func_array(actionVar, source);
    }

}
