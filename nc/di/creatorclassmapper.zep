namespace Nc\Di;

class CreatorClassMapper extends CreatorAbstract
{
    protected classMapper;

    public function __construct(array classMapper) -> void
    {
        let this->classMapper = classMapper;
    }

    public function getValidClassName(string name) -> string
    {
        var className;

        if fetch className, this->classMapper[name] {
            return (string) className;
        }

        if class_exists(className) {
            return className;
        }

        return "";
    }
}
