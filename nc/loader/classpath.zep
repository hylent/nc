namespace Nc\Loader;

class ClassPath extends LoaderAbstract
{
    protected classPaths;

    public function __construct(array classPaths = null) -> void
    {
        let this->classPaths = classPaths;
    }

    public function __invoke(string className) -> boolean
    {
        var path;

        if ! fetch path, this->classPaths[className->lower()] {
            return false;
        }

        if unlikely typeof path != "string" {
            throw new Exception("Invalid class path option: " . className);
        }

        if ! file_exists(path) {
            return false;
        }

        require path;

        if unlikely ! class_exists(className, false) {
            throw new Exception("Cannot find class: " . className . ", in path: " . path);
        }

        return true;
    }

    public function set(string className, string path) -> void
    {
        let this->classPaths[className->lower()] = path;
    }
}
