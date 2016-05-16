namespace Nc\Loader;

class Callback extends LoaderAbstract
{
    protected callback;

    public function __construct(var callback) -> void
    {
        let this->callback = callback;
    }

    public function findPath(string name) -> string
    {
        return (string) call_user_func(this->callback, name);
    }

}
