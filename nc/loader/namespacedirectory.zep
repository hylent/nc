namespace Nc\Loader;

class NamespaceDirectory extends LoaderAbstract
{
    const DEFAULT_DELIMITER = "\\";

    protected namespaceDirectories;
    protected delimiter;

    public function __construct(array namespaceDirectories = [], string delimiter = self::DEFAULT_DELIMITER) -> void
    {
        if count(namespaceDirectories) > 0 {
            this->setNamespaceDirectories(namespaceDirectories);
        }

        let this->delimiter = delimiter;
    }

    public function setNamespaceDirectories(array namespaceDirectories) -> void
    {
        var n, d;

        for n, d in namespaceDirectories {
            let this->namespaceDirectories[strtolower(n)] = d;
        }
    }

    public function setNamespaceDirectory(string ns, string dir) -> void
    {
        let this->namespaceDirectories[ns->lower()] = dir;
    }

    public function hasNamespace(string ns) -> boolean
    {
        return isset this->namespaceDirectories[ns->lower()];
    }

    public function findPath(string name) -> string
    {
        var match, pos, dir;
        boolean found = false;

        let match = name->lower();
        loop {
            let pos = strrpos(match, this->delimiter);
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
            return dir . "/" . strtr(substr(name, pos + 1), this->delimiter, "/") . ".php";
        }

        return "";
    }

}
