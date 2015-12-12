namespace Nc\Logger;

class LogClosure extends LoggerAbstract
{
    protected logClosure;

    public function __construct(<\Closure> logClosure) -> void
    {
        let this->logClosure = logClosure;
    }

    public function log(string level, string message, array context = []) -> void
    {
        call_user_func(this->logClosure, level, message, context);
    }

}
