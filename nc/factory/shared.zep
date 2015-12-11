namespace Nc\Factory;

class Shared implements FactoryInterface
{
    protected factory;
    protected productions;

    public function __construct(<FactoryInterface> factory) -> void
    {
        let this->factory = factory;
    }

    public function getFactory() -> <FactoryInterface>
    {
        return this->factory;
    }

    public function __isset(string name) -> bool
    {
        if isset this->productions[name] {
            return true;
        }

        return this->factory->__isset(name);
    }

    public function __get(string name)
    {
        var production;

        if fetch production, this->productions[name] {
            return production;
        }

        let production = this->factory->__get(name);
        let this->productions[name] = production;

        return production;
    }

}
