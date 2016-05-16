namespace Nc\Loader;

class Loaders extends LoaderAbstract implements \ArrayAccess
{
    const DEFAULT_ORDER = 0;

    protected loaders;
    protected orders;
    protected unsorted = false;

    public function set(string index, <LoaderInterface> loader, long order = self::DEFAULT_ORDER) -> void
    {
        let this->loaders[index] = loader;
        let this->orders[index] = order;

        let this->unsorted = true;
    }

    public function setOrder(string index, long order) -> void
    {
        let this->orders[index] = order;

        let this->unsorted = true;
    }

    public function offsetSet(string index, var loader) -> void
    {
        this->set(index, loader);
    }

    public function offsetGet(string index)
    {
        var loader;

        if fetch loader, this->loaders[index] {
            return loader;
        }

        throw new Exception("Undefined index: " . index);
    }

    public function offsetExists(string index) -> boolean
    {
        return isset this->loaders[index];
    }

    public function offsetUnset(string index) -> void
    {
        unset this->loaders[index];
        unset this->orders[index];
    }

    public function findPath(string name) -> string
    {
        var loader, index, path;

        if count(this->orders) > 0 {
            if this->unsorted {
                asort(this->orders, SORT_NUMERIC);
            }

            for index, _ in this->orders {
                if fetch loader, this->loaders[index] {
                    let path = loader->findPath(name);
                    if strlen(path) > 0 {
                        return path;
                    }
                }
            }
        }

        return "";
    }

}
