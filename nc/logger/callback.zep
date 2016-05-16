namespace Nc\Logger;

class Callback extends LoggerAbstract
{
    protected callback;

    public function __construct(var callback) -> void
    {
        let this->callback = callback;
    }

    public function log(string level, string message, array context = []) -> void
    {
        call_user_func(this->callback, level, message, context);
    }

}
