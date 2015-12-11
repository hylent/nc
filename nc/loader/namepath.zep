namespace Nc\Loader;

class NamePath extends LoaderAbstract
{
    protected namePaths;

    public function __construct(bool registerSelf = false, array namePaths = []) -> void
    {
        parent::__construct(registerSelf);

        let this->namePaths = namePaths;
    }

    public function __invoke(string name) -> bool
    {
        var path;

        if ! fetch path, this->namePaths[name->lower()] {
            return false;
        }

        if unlikely typeof path != "string" {
            throw new Exception("Invalid autoload path option: " . name);
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
