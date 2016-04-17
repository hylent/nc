namespace Nc\Logger;

class Loggers extends LoggerAbstract
{
    protected commonLoggers;
    protected levelLoggers;

    public function addLogger(<LoggerInterface> logger, string level = "") -> void
    {
        var h, lev;

        let h = spl_object_hash(logger);

        if level->length() < 1 {
            let this->commonLoggers[h] = logger;
        } else {
            for lev in preg_split("@[,/\\|]+@", level, PREG_SPLIT_NO_EMPTY) {
                let this->levelLoggers[lev][h] = logger;
            }
        }
    }

    public function getLoggers(string level = "") -> array
    {
        var loggers;

        if level->length() < 1 {
            let loggers = this->commonLoggers;
            if typeof loggers == "array" {
                return loggers;
            }
        } else {
            if fetch loggers, this->levelLoggers[level] && typeof loggers == "array" {
                return loggers;
            }
        }

        return [];
    }

    public function log(string level, string message, array context = []) -> void
    {
        var loggers, logger;

        let loggers = this->commonLoggers;
        if typeof loggers == "array" {
            for logger in loggers {
                logger->log(level, message, context);
            }
        }

        if fetch loggers, this->levelLoggers[level] && typeof loggers == "array" {
            for logger in loggers {
                logger->log(level, message, context);
            }
        }
    }

}
