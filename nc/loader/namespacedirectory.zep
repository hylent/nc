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

    public function set(string ns, string dir) -> void
    {
        let this->namespaceDirectories[ns->lower()] = dir;
    }

    public function findPath(string name) -> string
    {
        var match, pos, dir;
        bool found = false;

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

        if found {
            return dir . "/" . strtr(substr(name, pos + 1), "\\", "/") . ".php";
        }

        return "";
    }

}
