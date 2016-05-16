namespace Nc\Container;

class Callbacks extends CreatorAbstract
{
    protected callbacks;

    public function __invoke(string name, <\Closure> callback) -> void
    {
        let this->callbacks[name] = callback;
    }

    public function __set(string name, var obj) -> void
    {
        if typeof obj == "object" && (obj instanceof ContainerInterface) {
            obj->setSuper(this);
        }

        let this->creations[name] = obj;
    }

    public function __unset(string name) -> void
    {
        unset this->creations[name];
        unset this->callbacks[name];
    }

    public function __isset(string name) -> boolean
    {
        return parent::__isset(name) || isset this->callbacks[name];
    }

    protected function create(string name)
    {
        var callback;

        if unlikely ! fetch callback, this->callbacks[name] {
            throw new Exception(sprintf(
                "No callback for object '%s'",
                name
            ));
        }

        if unlikely typeof callback != "object" || ! (callback instanceof \Closure) {
            throw new Exception(sprintf(
                "Invalid callback when fetching object '%s'",
                name
            ));
        }

        return call_user_func(callback, this);
    }

}
