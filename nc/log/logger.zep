namespace Nc\Log;

class Logger implements \ArrayAccess
{
    const EMERGENCY = "emergency";
    const ALERT     = "alert";
    const CRITICAL  = "critical";
    const ERROR     = "error";
    const WARNING   = "warning";
    const NOTICE    = "notice";
    const INFO      = "info";
    const DEBUG     = "debug";

    const MAIN      = "main";

    protected logId;

    protected fallbackWriter;
    protected writers;

    protected mainLogs;

    public static function generateLogId() -> string
    {
        double mt;
        long mt0;

        let mt = (double) microtime(true);
        let mt0 = (long) mt;

        return sprintf(
            "%010d%06d%04d",
            mt0,
            1000000.0 * (mt - mt0),
            mt_rand(0, 9999)
        );
    }

    public function __construct(string logId = "") -> void
    {
        if logId->length() > 0 {
            let this->logId = logId;
        } else {
            let this->logId = self::generateLogId();
        }
    }

    public function getLogId() -> string
    {
        return this->logId;
    }

    public function setFallbackWriter(<WriterInterface> writer = null) -> void
    {
        let this->fallbackWriter = writer;
    }

    public function getFallbackWriter() -> <WriterInterface>
    {
        return this->fallbackWriter;
    }

    public function offsetSet(string level, var writer) -> void
    {
        if unlikely typeof writer != "object" || ! (writer instanceof WriterInterface) {
            throw new Exception("Invalid writer: " . level);
        }

        let this->writers[level] = writer;
    }

    public function offsetGet(string level) -> <WriterInterface>
    {
        var writer;

        if fetch writer, this->writers[level] {
            return writer;
        }

        return this->fallbackWriter;
    }

    public function offsetExists(string level) -> boolean
    {
        return isset this->writers[level];
    }

    public function offsetUnset(string level) -> void
    {
        unset this->writers[level];
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
        var writer;

        if ! fetch writer, this->writers[level] {
            let writer = this->fallbackWriter;
        }

        if writer === null {
            return;
        }

        writer->appendLog(
            this->stringifyLog(level, message, context)
        );
    }

    public function main(string key, var value, boolean duplicate = false) -> void
    {
        var mainLog;

        let mainLog = key . "[" . json_encode(value, JSON_UNESCAPED_UNICODE) . "]";

        if duplicate {
            let this->mainLogs[] = mainLog;
        } else {
            let this->mainLogs[key] = mainLog;
        }
    }

    public function __destruct() -> void
    {
        if count(this->mainLogs) < 1 {
            return;
        }

        try {
            this->log(self::MAIN, implode(" ", this->mainLogs));
        }

        return;
    }

    protected function stringifyLog(string level, string message, array context = null) -> string
    {
        var m, k, v, r;

        if count(context) > 0 {
            let r = [];
            for k, v in context {
                let r["{" . k . "}"] = (string) v;
            }
            let m = strtr(message, r);
        } else {
            let m = message;
        }

        return sprintf(
            "[%s] [%s] [%s] %s",
            date("c"),
            this->logId,
            level,
            m
        );
    }

}
