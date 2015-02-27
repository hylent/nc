namespace Nc\Log;

use Nc\Log\Backend\LogBackendInterface;
use Nc\Log\Backend\LogBackendAwareInterface;

class Logger implements LogInterface, LogBackendAwareInterface
{
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

    public function emergency(string message, array context = null) -> void
    {
        this->log(LogInterface::EMERGENCY, message, context);
    }

    public function alert(string message, array context = null) -> void
    {
        this->log(LogInterface::ALERT, message, context);
    }

    public function critical(string message, array context = null) -> void
    {
        this->log(LogInterface::CRITICAL, message, context);
    }

    public function error(string message, array context = null) -> void
    {
        this->log(LogInterface::ERROR, message, context);
    }

    public function warning(string message, array context = null) -> void
    {
        this->log(LogInterface::WARNING, message, context);
    }

    public function notice(string message, array context = null) -> void
    {
        this->log(LogInterface::NOTICE, message, context);
    }

    public function info(string message, array context = null) -> void
    {
        this->log(LogInterface::INFO, message, context);
    }

    public function debug(string message, array context = null) -> void
    {
        this->log(LogInterface::DEBUG, message, context);
    }

    public function log(string level, string message, array context = null) -> void
    {
        let this->logs[level][] = ["message": message, "context": context];
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
}
