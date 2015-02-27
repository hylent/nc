namespace Nc\Log;

interface LogInterface
{
    const EMERGENCY = "emergency";
    const ALERT     = "alert";
    const CRITICAL  = "critical";
    const ERROR     = "error";
    const WARNING   = "warning";
    const NOTICE    = "notice";
    const INFO      = "info";
    const DEBUG     = "debug";

    public function emergency(string message, array context = null) -> void;
    public function alert(string message, array context = null) -> void;
    public function critical(string message, array context = null) -> void;
    public function error(string message, array context = null) -> void;
    public function warning(string message, array context = null) -> void;
    public function notice(string message, array context = null) -> void;
    public function info(string message, array context = null) -> void;
    public function debug(string message, array context = null) -> void;

    public function log(string level, string message, array context = null) -> void;
    public function flush() -> void;
}
