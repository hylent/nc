namespace Nc\Log;

abstract class WriterBufferedAbstract implements WriterInterface
{
    const DEFAULT_BUFFER_SIZE = 0;

    protected bufferSize = self::DEFAULT_BUFFER_SIZE;
    protected logs;

    public function setBufferSize(long bufferSize) -> void
    {
        let this->bufferSize = bufferSize;
    }

    public function getBufferSize() -> long
    {
        return this->bufferSize;
    }

    public function appendLog(string log) -> void
    {
        let this->logs[] = log;

        if this->bufferSize < 1 || count(this->logs) >= this->bufferSize {
            this->flush();
        }
    }

    public function flush() -> void
    {
        if count(this->logs) < 1 {
            return;
        }

        this->writeLogs(this->logs);

        let this->logs = null;
    }

    public function __destruct() -> void
    {
        try {
            this->flush();
        }

        return;
    }

    abstract protected function writeLogs(array logs) -> void;

}
