namespace Nc\Log\Backend;

interface LogBackendInterface
{
    public function processLogs(array logs) -> void;
}
