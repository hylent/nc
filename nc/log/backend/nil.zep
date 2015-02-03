namespace Nc\Log\Backend;

class Nil implements LogBackendInterface
{
    public function processLogs(array logs) -> void
    {
        return;
    }
}
