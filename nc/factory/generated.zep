namespace Nc\Factory;

class Generated extends ClassNameAbstract
{
    protected classNameGenerator;

    public function __construct(<\Closure> classNameGenerator) -> void
    {
        let this->classNameGenerator = classNameGenerator;
    }

    public function getClassName(string name) -> string
    {
        return call_user_func(this->classNameGenerator, name);
    }

}
