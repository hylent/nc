namespace Nc\Factory;

class ClassNameClosure extends ClassNameAbstract
{
    protected classNameClosure;

    public function __construct(<\Closure> classNameClosure) -> void
    {
        let this->classNameClosure = classNameClosure;
    }

    public function getClassName(string name) -> string
    {
        return call_user_func(this->classNameClosure, name);
    }

}
