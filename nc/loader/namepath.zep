namespace Nc\Loader;

class NamePath extends LoaderAbstract
{
    protected namePaths;

    public function __construct(bool registerSelf = false, array namePaths = []) -> void
    {
        var n, p;

        parent::__construct(registerSelf);

        for n, p in namePaths {
            let this->namePaths[strtolower(n)] = (string) p;
        }
    }

    public function __invoke(string name) -> bool
    {
        var path;

        if ! fetch path, this->namePaths[name->lower()] {
            return false;
        }

        if ! file_exists(path) {
            return false;
        }

        require path;

        if unlikely ! LoaderAbstract::isLoaded(name) {
            throw new Exception("Cannot load: " . name . ", in path: " . path);
        }

        return true;
    }

    public function set(string name, string path) -> void
    {
        let this->namePaths[name->lower()] = path;
    }

}
