namespace Nc\Log;

interface LogAwareInterface
{
    public function setLog(<LogInterface> log) -> void;
    public function getLog() -> <LogInterface>;
}
