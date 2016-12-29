namespace Nc\Factory;

class Prefixed extends ClassNameAbstract
{
    protected prefix;

    public function __construct(string prefix) -> void
    {
        let this->prefix = prefix;
    }

    public function getClassName(string name) -> string
    {
        return this->prefix . ucfirst(name);
    }

}
