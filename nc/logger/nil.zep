namespace Nc\Logger;

class Nil extends LoggerAbstract
{
    public function log(string level, string message, array context = []) -> void
    {
        return;
    }

}
