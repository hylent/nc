namespace Nc\Container;

class ClassNameCallback extends ClassNameAbstract
{
    protected callback;

    public function __construct(<\Closure> callback) -> void
    {
        let this->callback = callback;
    }

    public function getClassName(string name) -> string
    {
        return (string) call_user_func(this->callback, name);
    }

}
