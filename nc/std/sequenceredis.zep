namespace Nc\Std;

class SequenceRedis implements SequenceInterface
{
    const DEFAULT_PREFIX = "sequence:";

    protected redis;
    protected prefix;

    public function __construct(var redis, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->redis = redis;
        let this->prefix = prefix;
    }

    public function getNextSequence(string identifier) -> long
    {
        var s;

        let s = this->redis->incr(this->prefix . identifier, 1);
        if unlikely s === false {
            throw new Exception("Cannot get next sequence of: " . identifier);
        }

        return (long) s;
    }

    public function restoreSequence(string identifier, long sequence) -> void
    {
        this->redis->set(this->prefix . identifier, sequence);
    }

}
