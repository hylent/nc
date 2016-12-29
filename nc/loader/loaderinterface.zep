namespace Nc\Loader;

interface LoaderInterface
{
    public function register(boolean prepend = false) -> boolean;
    public function unregister() -> boolean;

    public function __invoke(string name) -> boolean;
    public function findPath(string name) -> string;

    public function getLoadedNamePaths() -> array;

}
