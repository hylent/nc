namespace Nc\Loader;

interface LoaderInterface
{
    public function findPath(string name) -> string;
    public function __invoke(string name) -> boolean;

    public function register(boolean prepend = false) -> boolean;
    public function unregister() -> boolean;

}
