namespace Nc\Loader;

class Wrapper extends LoaderAbstract
{
    protected wrapped;

    public function __construct(var wrapped) -> void
    {
        let this->wrapped = wrapped;
    }

    public function findPath(string name) -> string
    {
        return (string) call_user_func(this->wrapped, name);
    }

}
