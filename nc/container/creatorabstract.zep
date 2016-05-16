namespace Nc\Container;

abstract class CreatorAbstract extends ContainerAbstract
{
    protected onCreated;
    protected creations;

    public function onCreated(<\Closure> onCreated = null) -> <CreatorAbstract>
    {
        let this->onCreated = onCreated;
        return this;
    }

    public function __isset(string name) -> boolean
    {
        return isset this->creations[name];
    }

    public function __get(string name)
    {
        return this->get(name, true);
    }

    public function get(string name, boolean shared = false)
    {
        var obj, onCreated;

        if shared && fetch obj, this->creations[name] {
            return obj;
        }

        let obj = this->create(name);

        if typeof obj == "object" && (obj instanceof ContainerInterface) {
            obj->setSuper(this);
        }

        let onCreated = this->onCreated;
        if typeof onCreated == "object" && (onCreated instanceof \Closure) {
            call_user_func(onCreated, obj, this);
        }

        if shared {
            let this->creations[name] = obj;
        }

        return obj;
    }

    abstract protected function create(string name);

}
