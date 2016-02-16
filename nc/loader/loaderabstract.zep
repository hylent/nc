namespace Nc\Loader;

abstract class LoaderAbstract
{
    abstract public function findPath(string name) -> string;

    public function __invoke(string name) -> bool
    {
        var x = false;
        string path;

        let path = (string) this->findPath(name);

        if path->length() < 1 || ! file_exists(path) {
            return x;
        }

        require path;

        if unlikely ! class_exists(name, x) && ! interface_exists(name, x) && ! trait_exists(name, x) {
            throw new Exception(sprintf("Cannot load %s in path: %s", name, path));
        }

        return true;
    }

    public function register(bool prepend = false) -> bool
    {
        return spl_autoload_register(this, false, prepend);
    }

    public function unregister() -> bool
    {
        return spl_autoload_unregister(this);
    }

}
