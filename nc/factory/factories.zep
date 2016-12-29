namespace Nc\Factory;

class Factories extends FactoryAbstract implements \ArrayAccess
{
    protected factories;

    public function offsetSet(string name, var factory) -> void
    {
        if unlikely typeof factory != "object" || ! (factory instanceof FactoryInterface) {
            throw new Exception("Invalid factory: " . name);
        }

        let this->factories[name] = factory;
    }

    public function offsetGet(string name) -> <FactoryInterface>
    {
        var factory;

        if unlikely ! fetch factory, this->factories[name] {
            throw new Exception("Undefined factory: " . name);
        }

        return factory;
    }

    public function offsetExists(string name) -> boolean
    {
        return isset this->factories[name];
    }

    public function offsetUnset(string name) -> void
    {
        unset this->factories[name];
    }

    public function __isset(string name) -> boolean
    {
        var factory;

        if count(this->factories) > 0 {
            for factory in this->factories {
                if factory->__isset(name) {
                    return true;
                }
            }
        }

        return false;
    }

    public function __get(string name)
    {
        var factory;

        if count(this->factories) > 0 {
            for factory in this->factories {
                if factory->__isset(name) {
                    return factory->__get(name);
                }
            }
        }

        throw new Exception(sprintf(
            "Cannot fetch object '%s'",
            name
        ));
    }

}
