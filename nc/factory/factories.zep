namespace Nc\Factory;

class Factories implements FactoryInterface, \ArrayAccess
{
    const DEFAULT_PRIORITY = 0;

    protected factories;
    protected priorities;

    public function set(string index, <FactoryInterface> factory, long priority = self::DEFAULT_PRIORITY) -> void
    {
        let this->factories[index] = factory;
        let this->priorities[index] = priority;

        asort(this->priorities, SORT_NUMERIC);
    }

    public function offsetSet(string index, var factory) -> void
    {
        this->set(index, factory);
    }

    public function offsetGet(string index) -> <FactoryInterface>
    {
        var factory;

        if fetch factory, this->factories[index] {
            return factory;
        }

        throw new Exception("Invalid index: " . index);
    }

    public function offsetExists(string index) -> bool
    {
        return isset this->factories[index];
    }

    public function offsetUnset(string index) -> void
    {
        unset this->factories[index];
        unset this->priorities[index];
    }

    public function __isset(string name) -> bool
    {
        var index, factory;

        if count(this->priorities) > 0 {
            for index, _ in this->priorities {
                let factory = <FactoryInterface> this->factories[index];
                if factory->__isset(name) {
                    return true;
                }
            }
        }

        return false;
    }

    public function __get(string name)
    {
        var index, factory;

        if count(this->priorities) > 0 {
            for index, _ in this->priorities {
                let factory = <FactoryInterface> this->factories[index];
                if factory->__isset(name) {
                    return factory->__get(name);
                }
            }
        }

        throw new Exception("Invalid production: " . name);
    }

    public function newProduction(string name)
    {
        var index, factory;

        if count(this->priorities) > 0 {
            for index, _ in this->priorities {
                let factory = <FactoryInterface> this->factories[index];
                if factory->__isset(name) {
                    return factory->newProduction(name);
                }
            }
        }

        throw new Exception("Invalid production: " . name);
    }

}
