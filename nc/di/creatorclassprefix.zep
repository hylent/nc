namespace Nc\Di;

class CreatorClassPrefix extends CreatorAbstract
{
    protected classPrefix;

    public function __construct(string classPrefix) -> void
    {
        let this->classPrefix = classPrefix;
    }

    public function getValidClassName(string name) -> string
    {
        var className;

        let className = this->classPrefix . ucfirst(name);
        if class_exists(className) {
            return className;
        }

        return "";
    }
}
