namespace Nc\Logger;

class Wrapper extends LoggerAbstract
{
    protected wrapped;

    public function __construct(var wrapped) -> void
    {
        let this->wrapped = wrapped;
    }

    public function log(string level, string message, array context = []) -> void
    {
        call_user_func(this->wrapped, level, message, context);
    }

}
