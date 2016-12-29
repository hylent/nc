namespace Nc\Log;

class Nil implements WriterInterface
{
    public function appendLog(string log) -> void
    {
        return;
    }

}
