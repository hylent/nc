namespace Nc\Loader;

abstract class LoaderAdapter implements LoaderInterface
{
    public function register() -> boolean
    {
        return spl_autoload_register(this);
    }

    public function unregister() -> boolean
    {
        return spl_autoload_unregister(this);
    }
}
