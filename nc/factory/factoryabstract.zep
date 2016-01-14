namespace Nc\Factory;

abstract class FactoryAbstract implements FactoryInterface
{
    protected super;
    protected onCreation;

    protected creations;

    public function super() -> <FactoryAbstract>
    {
        return this->super;
    }

    public function onCreation(<\Closure> onCreation = null) -> <FactoryAbstract>
    {
        let this->onCreation = onCreation;
        return this;
    }

    public function __isset(string name) -> bool
    {
        return isset this->creations[name];
    }

    public function __get(string name)
    {
        var obj;

        if fetch obj, this->creations[name] {
            return obj;
        }

        let obj = this->create(name);
        let this->creations[name] = obj;

        return obj;
    }

    public function create(string name)
    {
        var obj, onCreation;

        let obj = this->createInternally(name);
        if typeof obj == "object" && (obj instanceof FactoryAbstract) {
            let obj->super = this;
        }

        let onCreation = this->onCreation;
        if onCreation {
            call_user_func(onCreation, obj, this);
        }

        return obj;
    }

    abstract protected function createInternally(string name);

}
