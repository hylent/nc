namespace Nc\Std;

interface QueueInterface
{
    public function pushQueue(string identifier, string data) -> void;
    public function popQueue(string identifier) -> string;

}
