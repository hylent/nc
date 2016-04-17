namespace Nc\Logger;

class File extends LoggerAbstract
{
    const EOL = "\n";

    protected logs;
    protected path;
    protected chunkSize;

    public function __construct(string path, long chunkSize = 0) -> void
    {
        let this->path = path;
        let this->chunkSize = chunkSize;
    }

    public function getPath() -> string
    {
        return this->path;
    }

    public function setChunkSize(long chunkSize) -> void
    {
        let this->chunkSize = chunkSize;
    }

    public function getChunkSize() -> long
    {
        return this->chunkSize;
    }

    public function log(string level, string message, array context = []) -> void
    {
        let this->logs[] = LoggerAbstract::stringifyLog(level, message, context) . self::EOL;

        if this->chunkSize > 0 && count(this->logs) >= this->chunkSize {
            this->flush();
        }
    }

    public function flush() -> void
    {
        if count(this->logs) < 1 {
            return;
        }

        if unlikely ! file_put_contents(this->path, implode("", this->logs), LOCK_EX | FILE_APPEND) {
            throw new Exception("Cannot append logs to file: " . this->path);
        }

        let this->logs = null;
    }

    public function __destruct() -> void
    {
        if this->chunkSize < 0 {
            return;
        }

        try {
            this->flush();
        }

        return;
    }

}
