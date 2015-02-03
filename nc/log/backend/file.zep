namespace Nc\Log\Backend;

class File implements LogBackendInterface
{
    protected path;
    protected logLevels;

    public function __construct(string path, array logLevels = null) -> void
    {
        let this->path = path;
        let this->logLevels = logLevels;
    }

    public function processLogs(array logs) -> void
    {
        var level, logItems, log, content = "";

        for level, logItems in logs {
            if this->logLevels && ! in_array(level, this->logLevels) {
                continue;
            }

            for log in logItems {
                let content .= sprintf("[%s] %s\n", date("c"), level, log["message"]);
            }
        }

        if unlikely ! file_put_contents(this->path, content, LOCK_EX | FILE_APPEND) {
            throw new Exception("Cannot append logs to file");
        }
    }
}
