namespace Nc\Di;

class Creators extends CreatorAbstract implements \ArrayAccess
{
    protected creators;

    public function __construct(array creators = []) -> void
    {
        var name, creator;

        for name, creator in creators {
            this->offsetSet(name, creator);
        }
    }

    public function offsetSet(string name, var creator) -> void
    {
        if unlikely typeof creator != "object" || ! (creator instanceof CreatorAbstract) {
            throw new Exception("Invalid creator: " . name);
        }

        let this->creators[name] = creator;
    }

    public function offsetGet(string name) -> <CreatorAbstract>
    {
        var creator;

        if unlikely ! fetch creator, this->creators[name] {
            throw new Exception("Undefined creator: " . name);
        }

        return creator;
    }

    public function offsetExists(string name) -> boolean
    {
        return isset this->creators[name];
    }

    public function offsetUnset(string name) -> void
    {
        unset this->creators[name];
    }

    public function getValidClassName(string name) -> string
    {
        var creator, className;

        if count(this->creators) > 0 {
            for creator in this->creators {
                let className = (string) creator->getValidClassName(name);
                if className !== "" {
                    return className;
                }
            }
        }

        return "";
    }
}
