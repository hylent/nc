namespace Nc\Loader;

use Nc\Container\Sorted;

class Loaders extends LoaderAbstract implements \ArrayAccess
{
    protected loaders;

    public function __construct() -> void
    {
        let this->loaders = new Sorted();
    }

    public function set(string name, <LoaderInterface> loader, long order = Sorted::DEFAULT_ORDER) -> void
    {
        this->loaders->set(name, loader, order);
    }

    public function offsetSet(string name, var loader) -> void
    {
        this->set(name, loader);
    }

    public function offsetGet(string name) -> <ContainerInterface>
    {
        return this->loaders->__get(name);
    }

    public function offsetExists(string name) -> boolean
    {
        return this->loaders->__isset(name);
    }

    public function offsetUnset(string name) -> void
    {
        this->loaders->__unset(name);
    }

    public function findPath(string name) -> string
    {
        var loaders, path;

        let loaders = this->loaders;

        loaders->rewind();
        while loaders->valid() {
            let path = loaders->current()->findPath(name);
            if strlen(path) > 0 {
                return path;
            }
            loaders->next();
        }

        return "";
    }

}
