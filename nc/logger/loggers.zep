namespace Nc\Logger;

class Loggers extends LoggerAbstract
{
    protected globalLoggers;
    protected loggers;

    public function addLogger(<LoggerInterface> logger, string level = "") -> void
    {
        string h;
        var lev;

        let h = (string) spl_object_hash(logger);

        if level->length() < 1 {
            let this->globalLoggers[h] = logger;
            return;
        }

        for lev in preg_split("@[,/\\|]+@", level, PREG_SPLIT_NO_EMPTY) {
            let this->loggers[lev][h] = logger;
        }
    }


    public function log(string level, string message, array context = []) -> void
    {
        var loggers, logger;

        let loggers = this->globalLoggers;
        if typeof loggers == "array" {
            for logger in loggers {
                logger->log(level, message, context);
            }
        }

        if fetch loggers, this->loggers[level] && typeof loggers == "array" {
            for logger in loggers {
                logger->log(level, message, context);
            }
        }
    }

}
