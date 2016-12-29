namespace Nc\Queue;

interface QueueInterface
{
    public function put(string id, long delay = 0) -> void;
    public function reserve(long ttr) -> string;
    public function delete(string id) -> void;

}
