namespace Nc\Loader;

class NamespaceDirectory extends LoaderAbstract
{
    protected namespaceDirectories;

    public function __construct(array namespaceDirectories = []) -> void
    {
        var n, d;

        for n, d in namespaceDirectories {
            let this->namespaceDirectories[strtolower(n)] = d;
        }
    }

    public function __invoke(string name) -> bool
    {
        var match, pos, dir;
        bool found = false;
        string path;

        let match = name->lower();
        loop {
            let pos = strrpos(match, "\\");
            if pos === false || pos < 1 {
                break;
            }
            let match = substr(match, 0, pos);
            if fetch dir, this->namespaceDirectories[match] {
                let found = true;
                break;
            }
        }

        if ! found {
            return false;
        }

        let path = (string) substr(name, pos + 1);
        let path = dir . "/" . str_replace("\\", "/", path) . ".php";

        if ! file_exists(path) {
            return false;
        }

        require path;

        if unlikely ! LoaderAbstract::isLoaded(name) {
            throw new Exception("Cannot load: " . name . ", in path: " . path);
        }

        return true;
    }

    public function set(string ns, string dir) -> void
    {
        let this->namespaceDirectories[ns->lower()] = dir;
    }

}
