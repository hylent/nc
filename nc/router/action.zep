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

    public function route() -> void
    {
        var source, actionVar;
        string action, actionName;

        let source = (array) this->getSource();

        if count(source) < 1 {
            let action = (string) this->defaultAction;
        } else {
            let action = (string) array_shift(source);
        }

        let this->id = action;

        let actionName = (string) Std::camelCase(action);

        if unlikely ! this->actionFactory->__isset(actionName) {
            throw new NotFoundException("Action not found: " . action);
        }

        let actionVar = this->actionFactory->__get(actionName);
        if unlikely ! is_callable(actionVar) {
            throw new NotFoundException("Invalid action: " . action);
        }

        call_user_func_array(actionVar, source);
    }

}
