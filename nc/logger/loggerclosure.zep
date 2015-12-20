namespace Nc\Logger;

class LoggerClosure extends LoggerAbstract
{
    protected loggerClosure;

    public function __construct(<\Closure> loggerClosure) -> void
    {
        let this->loggerClosure = loggerClosure;
    }

    public function log(string level, string message, array context = []) -> void
    {
        call_user_func(this->loggerClosure, level, message, context);
    }

}
