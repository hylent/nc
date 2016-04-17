namespace Nc\Loader;

abstract class LoaderAbstract implements LoaderInterface
{
    protected static loadedPaths;

    public static function getLoadedPaths() -> array
    {
        var loadedPaths;

        let loadedPaths = self::loadedPaths;
        if count(loadedPaths) > 0 {
            return loadedPaths;
        }

        return [];
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

        let self::loadedPaths[name] = path;
        return true;
    }

    public function register(boolean prepend = false) -> boolean
    {
        return spl_autoload_register(this, false, prepend);
    }

    public function unregister() -> boolean
    {
        return spl_autoload_unregister(this);
    }

}
