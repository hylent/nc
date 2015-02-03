namespace Nc\Loader;

class NamespaceDirectory extends LoaderAdapter
{
    protected namespaceDirectories;

    public function __construct(array namespaceDirectories = []) -> void
    {
        var n, a;

        for n, a in namespaceDirectories {
            if typeof a == "array" {
                let this->namespaceDirectories[strtolower(n)] = a;
            } else {
                let this->namespaceDirectories[strtolower(n)] = [a, true];
            }
        }
    }

    public function __invoke(string className) -> boolean
    {
        var match, pos, arr;
        boolean found = false;
        string path;

        let match = className->lower();
        loop {
            let pos = strrpos(match, "\\");
            if pos === false || pos < 1 {
                break;
            }
            let match = substr(match, 0, pos);
            if fetch arr, this->namespaceDirectories[match] {
                let found = true;
                break;
            }
        }

        if ! found {
            return false;
        }

        if unlikely typeof arr != "array" || count(arr) != 2 {
            throw new Exception("Invalid namespace directory options");
        }

        let path = (string) substr(className, pos + 1);
        if arr[1] {
            let path = path->lower();
        }
        let path = arr[0] . "/" . str_replace("\\", "/", path) . ".php";

        if ! file_exists(path) {
            return false;
        }

        require path;

        if unlikely ! class_exists(className, false) {
            throw new Exception("Cannot find class `" . className . "` in path `" . path . "`");
        }

        return true;
    }

    public function set(string ns, string dir, boolean lcase = true) -> void
    {
        let this->namespaceDirectories[ns->lower()] = [dir, lcase];
    }
}
