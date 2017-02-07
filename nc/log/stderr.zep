namespace Nc\Log;

class StdErr implements WriterInterface
{
    protected fp;

    public function __construct() -> void
    {
        let this->fp = fopen("php://stderr", "w");
    }

    public function appendLog(string log) -> void
    {
        if unlikely fwrite(this->fp, log . PHP_EOL) === false {
            throw new Exception(__FUNCTION__);
        }
    }

}
