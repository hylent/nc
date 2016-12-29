namespace Nc\Factory;

abstract class FactoryAbstract implements FactoryInterface
{
    protected onCreated;
    protected objects;

    public function onCreated(var onCreated = null) -> void
    {
        let this->onCreated = onCreated;
    }

    public function __isset(string name) -> boolean
    {
        return isset this->objects[name];
    }

    public function __get(string name)
    {
        return this->create(name, true);
    }

    public function create(string name, boolean shared = false)
    {
        var obj, onCreated;

        if shared && fetch obj, this->objects[name] {
            return obj;
        }

        let obj = this->createInternally(name);

        let onCreated = this->onCreated;
        if is_callable(onCreated) {
            call_user_func(onCreated, name, obj, this);
        }

        if shared {
            let this->objects[name] = obj;
        }

        return obj;
    }

    abstract protected function createInternally(string name);

}
