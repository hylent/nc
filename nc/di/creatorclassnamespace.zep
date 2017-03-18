namespace Nc\Di;

class CreatorClassNamespace extends CreatorClassPrefix
{
    public function __construct(string classNamespace) -> void
    {
        parent::__construct(classNamespace . "\\");
    }
}
