namespace Nc\Logger;

use Nc\Std;

class File extends LoggerAbstract
{
    protected logs;
    protected path;
    protected chunkSize = -1;

    public function __construct(string path) -> void
    {
        let this->path = path;
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
        let this->logs[] = sprintf(
            "[%s] [%s] %s\n",
            date("c"),
            level,
            Std::tr(message, context)
        );

        if this->chunkSize > -1 && count(this->logs) > this->chunkSize {
            this->flush();
        }
    }

    public function flush() -> void
    {
        if ! this->logs {
            return;
        }

        if unlikely ! file_put_contents(this->path, implode("", this->logs), LOCK_EX | FILE_APPEND) {
            throw new Exception("Cannot append logs to file: " . this->path);
        }

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
