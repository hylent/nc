namespace Nc\Log;

use Nc\Log\Backend\LogBackendInterface;
use Nc\Log\Backend\LogBackendAwareInterface;

class Logger implements LogBackendAwareInterface
{
    const EMERGENCY = "emergency";
    const ALERT     = "alert";
    const CRITICAL  = "critical";
    const ERROR     = "error";
    const WARNING   = "warning";
    const NOTICE    = "notice";
    const INFO      = "info";
    const DEBUG     = "debug";

    protected logBackend;
    protected logs;

    public function setLogBackend(<LogBackendInterface> logBackend) -> void
    {
        let this->logBackend = logBackend;
    }

    public function getLogBackend() -> <LogBackendInterface>
    {
        return this->logBackend;
    }

    public function flush() -> void
    {
        if ! this->logs {
            return;
        }

        this->logBackend->processLogs(this->logs);
        let this->logs = null;
    }

    public function __destruct() -> void
    {
        try {
            this->flush();
        }

        return;
    }

    public function emergency(string message, array context = null) -> void
    {
        this->log(self::EMERGENCY, message, context);
    }

    public function alert(string message, array context = null) -> void
    {
        this->log(self::ALERT, message, context);
    }

    public function critical(string message, array context = null) -> void
    {
        this->log(self::CRITICAL, message, context);
    }

    public function error(string message, array context = null) -> void
    {
        this->log(self::ERROR, message, context);
    }

    public function warning(string message, array context = null) -> void
    {
        this->log(self::WARNING, message, context);
    }

    public function notice(string message, array context = null) -> void
    {
        this->log(self::NOTICE, message, context);
    }

    public function info(string message, array context = null) -> void
    {
        this->log(self::INFO, message, context);
    }

    public function debug(string message, array context = null) -> void
    {
        this->log(self::DEBUG, message, context);
    }

    public function log(string level, string message, array context = null) -> void
    {
        let this->logs[level][] = ["message": message, "context": context];
    }

    public function __call(string level, array args) -> void
    {
        var message, context;

        if fetch message, args[0] && typeof message == "string" {
            if ! fetch context, args[1] || typeof context != "array" {
                let context = null;
            }

            this->log(level, message, context);
        }
    }
}
