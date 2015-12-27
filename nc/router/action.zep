namespace Nc\Router;

use Nc\Factory\FactoryInterface;
use Nc\Std;

class Action extends RouterAbstract
{
    const DEFAULT_ACTION = "index";

    protected actionFactory;
    protected defaultAction = self::DEFAULT_ACTION;

    public function __construct(<FactoryInterface> actionFactory) -> void
    {
        let this->actionFactory = actionFactory;
    }

    public function getActionFactory() -> <FactoryInterface>
    {
        return this->actionFactory;
    }

    public function setDefaultAction(string defaultAction) -> void
    {
        let this->defaultAction = defaultAction;
    }

    public function getDefaultAction() -> string
    {
        return this->defaultAction;
    }

    public function route(array params) -> void
    {
        string action, actionName;
        var actionVar;

        if count(params) < 1 {
            let action = (string) this->defaultAction;
        } else {
            let action = (string) array_shift(params);
        }

        let this->id = action;

        let actionName = (string) Std::camelCase(action);
        if unlikely ! this->actionFactory->__isset(actionName) {
            throw new NotFoundException("Action not found: " . action);
        }

        let actionVar = this->actionFactory->__get(actionName);
        if unlikely ! is_callable(actionVar) {
            throw new Exception("Invalid action: " . action);
        }

        call_user_func_array(actionVar, params);
    }

}
