namespace Nc\Loader;

abstract class LoaderAbstract implements LoaderInterface
{
    protected loadedNamePaths;

    public function register(boolean prepend = false) -> boolean
    {
        return spl_autoload_register(this, false, prepend);
    }

    public function unregister() -> boolean
    {
        return spl_autoload_unregister(this);
    }

    public function __invoke(string name) -> boolean
    {
        var x = false, path;

        let path = this->findPath(name);

        if strlen(path) < 1 || ! file_exists(path) {
            return x;
        }

        require path;

        if unlikely ! class_exists(name, x) && ! interface_exists(name, x) && ! trait_exists(name, x) {
            throw new Exception(sprintf("Cannot load '%s' in path '%s'", name, path));
        }

        let this->loadedNamePaths[name] = path;
        return true;
    }

    public function getLoadedNamePaths() -> array
    {
        var loadedNamePaths;

        let loadedNamePaths = this->loadedNamePaths;
        if count(loadedNamePaths) > 0 {
            return loadedNamePaths;
        }

        return [];
    }

}
