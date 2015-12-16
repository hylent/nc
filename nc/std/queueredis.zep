namespace Nc\Std;

class QueueRedis implements QueueInterface
{
    const DEFAULT_PREFIX = "queue:";

    protected redis;
    protected prefix;

    public function __construct(var redis, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->redis = redis;
        let this->prefix = prefix;
    }

    public function pushQueue(string identifier, string data) -> void
    {
        if unlikely ! this->redis->lpush(this->prefix . identifier, data) {
            throw new Exception("Cannot lpush data to queue: " . identifier);
        }
    }

    public function popQueue(string identifier) -> string
    {
        var data;

        let data = this->redis->rpop(this->prefix . identifier);
        if data === false {
            return;
        }

        return (string) data;
    }

}
