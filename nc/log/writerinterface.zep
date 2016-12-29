namespace Nc\Log;

interface WriterInterface
{
    public function appendLog(string log) -> void;

}
