namespace Nc\Router;

abstract class RouterAbstract
{
    protected id = "";

    public function getId() -> string
    {
        return this->id;
    }

    abstract public function route(array params) -> void;

}
