namespace Nc\Container;

class Containers extends ContainerAbstract implements \ArrayAccess
{
    protected containers;

    public function __construct() -> void
    {
        let this->containers = new Sorted();
    }

    public function set(string name, <ContainerInterface> container, long order = Sorted::DEFAULT_ORDER) -> void
    {
        this->containers->set(name, container, order);
        container->setSuper(this);
    }

    public function offsetSet(string name, var container) -> void
    {
        this->set(name, container);
    }

    public function offsetGet(string name) -> <ContainerInterface>
    {
        return this->containers->__get(name);
    }

    public function offsetExists(string name) -> boolean
    {
        return this->containers->__isset(name);
    }

    public function offsetUnset(string name) -> void
    {
        this->containers->__unset(name);
    }

    public function __isset(string name) -> boolean
    {
        var containers, container;

        let containers = this->containers;

        containers->rewind();
        while containers->valid() {
            let container = containers->current();
            if container->__isset(name) {
                return true;
            }
            containers->next();
        }

        return false;
    }

    public function __get(string name)
    {
        var containers, container;

        let containers = this->containers;

        containers->rewind();
        while containers->valid() {
            let container = containers->current();
            if container->__isset(name) {
                return container->__get(name);
            }
            containers->next();
        }

        throw new Exception(sprintf(
            "Cannot fetch object '%s'",
            name
        ));
    }

}
