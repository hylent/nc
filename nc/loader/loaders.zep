namespace Nc\Loader;

class Loaders extends LoaderAbstract implements \ArrayAccess
{
    protected loaders;

    public function offsetSet(string name, var loader) -> void
    {
        if unlikely typeof loader != "object" || ! (loader instanceof LoaderInterface) {
            throw new Exception("Invalid loader: " . name);
        }

        let this->loaders[name] = loader;
    }

    public function offsetGet(string name) -> <LoaderInterface>
    {
        var loader;

        if unlikely ! fetch loader, this->loaders[name] {
            throw new Exception("Undefined loader: " . name);
        }

        return loader;
    }

    public function offsetExists(string name) -> boolean
    {
        return isset this->loaders[name];
    }

    public function offsetUnset(string name) -> void
    {
        unset this->loaders[name];
    }

    public function findPath(string name) -> string
    {
        var loader, path;

        if count(this->loaders) > 0 {
            for loader in this->loaders {
                let path = loader->findPath(name);
                if strlen(path) > 0 {
                    return path;
                }
            }
        }

        return "";
    }

}
