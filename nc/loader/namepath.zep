namespace Nc\Loader;

class NamePath extends LoaderAbstract
{
    protected namePaths;

    public function __construct(array namePaths = []) -> void
    {
        if count(namePaths) > 0 {
            this->setNamePaths(namePaths);
        }
    }

    public function setNamePaths(array namePaths) -> void
    {
        var n, p;

        for n, p in namePaths {
            let this->namePaths[strtolower(n)] = (string) p;
        }
    }

    public function setNamePath(string name, string path) -> void
    {
        let this->namePaths[name->lower()] = path;
    }

    public function hasName(string name) -> boolean
    {
        return isset this->namePaths[name->lower()];
    }

    public function findPath(string name) -> string
    {
        var path;

        if fetch path, this->namePaths[name->lower()] {
            return path;
        }

        return "";
    }

}
