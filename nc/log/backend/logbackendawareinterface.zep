namespace Nc\Log\Backend;

interface LogBackendAwareInterface
{
    public function setLogBackend(<LogBackendInterface> logBackend) -> void;
    public function getLogBackend() -> <LogBackendInterface>;
}
