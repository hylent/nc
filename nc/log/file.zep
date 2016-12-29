namespace Nc\Log;

class File extends WriterBufferedAbstract
{
    const SUFFIX_NONE   = 0;
    const SUFFIX_DAILY  = 1;
    const SUFFIX_HOURLY = 2;

    const EOL   = "\n";

    protected basePath;
    protected suffixType;

    public function __construct(string basePath, long suffixType = self::SUFFIX_NONE) -> void
    {
        let this->basePath = basePath;
        let this->suffixType = suffixType;
    }

    public function getBasePath() -> string
    {
        return this->basePath;
    }

    public function getSuffixType() -> long
    {
        return this->suffixType;
    }

    protected function writeLogs(array logs) -> void
    {
        var res;

        if count(logs) < 1 {
            return;
        }

        let res = file_put_contents(
            this->getPath(),
            implode(self::EOL, logs) . self::EOL,
            FILE_APPEND | LOCK_EX
        );

        if unlikely ! res {
            throw new Exception("Failed to write to log file");
        }
    }

    protected function getPath() -> string
    {
        var path;

        let path = this->basePath;

        switch this->suffixType {
            case self::SUFFIX_DAILY:
                let path .= date(".Ymd");
                break;

            case self::SUFFIX_HOURLY:
                let path .= date(".YmdH");
                break;
        }

        return path;
    }

}
