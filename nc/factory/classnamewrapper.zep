namespace Nc\Factory;

class ClassNameWrapper extends ClassNameAbstract
{
    protected wrapped;

    public function __construct(<\Closure> wrapped) -> void
    {
        let this->wrapped = wrapped;
    }

    public function getClassName(string name) -> string
    {
        return call_user_func(this->wrapped, name);
    }

}
