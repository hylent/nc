namespace Nc\Container;

class Containers extends ContainerAbstract implements \ArrayAccess
{
    const DEFAULT_PRIORITY = 0;

    protected containers;
    protected priorities;

    public function set(string index, <ContainerInterface> container, long priority = self::DEFAULT_PRIORITY) -> void
    {
        container->setSuper(this);

        let this->containers[index] = container;
        let this->priorities[index] = priority;

        asort(this->priorities, SORT_NUMERIC);
    }

    public function offsetSet(string index, var container) -> void
    {
        this->set(index, container);
    }

    public function offsetGet(string index) -> <ContainerInterface>
    {
        var container;

        if fetch container, this->containers[index] {
            return container;
        }

        throw new Exception(sprintf(
            "Cannot find container at index '%s'",
            index
        ));
    }

    public function offsetExists(string index) -> boolean
    {
        return isset this->containers[index];
    }

    public function offsetUnset(string index) -> void
    {
        unset this->containers[index];
        unset this->priorities[index];
    }

    public function __isset(string name) -> boolean
    {
        var index, container;

        if count(this->priorities) > 0 {
            for index, _ in this->priorities {
                if fetch container, this->containers[index] && container->__isset(name) {
                    return true;
                }
            }
        }

        return false;
    }

    public function get(string name, boolean shared = false)
    {
        var index, container;

        if count(this->priorities) > 0 {
            for index, _ in this->priorities {
                if fetch container, this->containers[index] && container->__isset(name) {
                    return container->get(name, shared);
                }
            }
        }

        throw new Exception(sprintf(
            "Cannot fetch object '%s'",
            name
        ));
    }

}
