namespace Nc\Loader;

abstract class LoaderAbstract
{
    public static function isLoaded(string name) -> bool
    {
        bool x = false;

        if class_exists(name, x) {
            return true;
        }

        if interface_exists(name, x) {
            return true;
        }

        if trait_exists(name, x) {
            return true;
        }

        return x;
    }

    public function __construct(bool registerSelf = false) -> void
    {
        if unlikely registerSelf && ! this->register() {
            throw new Exception("Cannot register loader");
        }
    }

    public function register() -> bool
    {
        return spl_autoload_register(this);
    }

    public function unregister() -> bool
    {
        return spl_autoload_unregister(this);
    }

    abstract public function __invoke(string name) -> bool;

}
