namespace Nc\Router;

abstract class RouterAbstract implements RouterInterface
{
    protected controller;
    protected action;
    protected params;

    public function getController() -> string
    {
        return this->controller;
    }

    public function getAction() -> string
    {
        return this->action;
    }

    public function getParams() -> array
    {
        return this->params;
    }
}
