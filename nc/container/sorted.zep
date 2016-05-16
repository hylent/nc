namespace Nc\Container;

class Sorted extends ContainerAbstract implements \Iterator
{
    const DEFAULT_ORDER = 0;

    protected values;
    protected orders;
    protected isSorted = true;

    protected iterNames;
    protected iterIndex = -1;

    public function __construct(string type = "")
    {
        let this->type = type;
    }

    public function set(string name, var value, long order = self::DEFAULT_ORDER) -> void
    {
        if typeof value == "object" && (value instanceof ContainerInterface) {
            value->setSuper(this);
        }

        let this->values[name] = value;
        let this->orders[name] = order;
        let this->isSorted = false;
    }

    public function setOrder(string name, long order) -> void
    {
        if unlikely ! isset this->orders[name] {
            throw new Exception("Undefined name: " . name);
        }

        let this->orders[name] = order;
        let this->isSorted = false;
    }

    public function getOrder(string name) -> long
    {
        var order;

        if unlikely ! fetch order, this->orders[name] {
            throw new Exception("Undefined name: " . name);
        }

        return (long) order;
    }

    public function __set(string name, var value)
    {
        this->set(name, value);
    }

    public function __get(string name)
    {
        var value;

        if unlikely ! fetch value, this->values[name] {
            throw new Exception("Undefined name: " . name);
        }

        return value;
    }

    public function __isset(string name) -> boolean
    {
        return isset this->values[name];
    }

    public function __unset(string name) -> void
    {
        unset this->values[name];
        unset this->orders[name];
        let this->isSorted = false;
    }

    public function rewind() -> void
    {
        if ! this->isSorted {
            let this->isSorted = true;
            if count(this->orders) > 0 {
                asort(this->orders, SORT_NUMERIC);
                let this->iterNames = array_keys(this->orders);
            } else {
                let this->iterNames = null;
            }
        }

        let this->iterIndex = 0;
    }

    public function valid() -> boolean
    {
        return isset this->iterNames[this->iterIndex];
    }

    public function key() -> string
    {
        var name;

        if unlikely ! fetch name, this->iterNames[this->iterIndex] {
            throw new Exception("Invalid iter index: " . this->iterIndex);
        }

        return name;
    }

    public function current()
    {
        var name, value;

        if unlikely ! fetch name, this->iterNames[this->iterIndex] {
            throw new Exception("Invalid iter index: " . this->iterIndex);
        }

        if unlikely ! fetch value, this->values[name] {
            throw new Exception("Invalid name: " . name);
        }

        return value;
    }

    public function next() -> void
    {
        let this->iterIndex++;
    }

    public function each(var cb, var stopWhen = false) -> void
    {
        var orders, names, index, name, value;

        let orders = this->orders;
        if count(orders) < 1 {
            return;
        }

        if ! this->isSorted {
            asort(orders, SORT_NUMERIC);
            let names = array_keys(orders);
        } else {
            let names = this->iterNames;
        }

        for index, name in names {
            if unlikely ! fetch value, this->values[name] {
                throw new Exception("Invalid name: " . name);
            }
            if call_user_func(cb, value, name, index) === stopWhen {
                break;
            }
        }
    }

}
