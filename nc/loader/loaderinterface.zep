namespace Nc\Loader;

interface LoaderInterface
{
    public function register() -> boolean;
    public function unregister() -> boolean;
    public function __invoke(string className) -> boolean;
}
