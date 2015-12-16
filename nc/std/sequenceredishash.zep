namespace Nc\Std;

class SequenceRedisHash implements SequenceInterface
{
    const DEFAULT_HASH_NAME = "sequencehash";

    protected redis;
    protected hashName;

    public function __construct(var redis, string hashName = self::DEFAULT_HASH_NAME) -> void
    {
        let this->redis = redis;
        let this->hashName = hashName;
    }

    public function getNextSequence(string identifier) -> long
    {
        var s;

        let s = this->redis->hincrby(this->hashName, identifier, 1);
        if unlikely s === false {
            throw new Exception("Cannot get next sequence of: " . identifier);
        }

        return (long) s;
    }

    public function restoreSequence(string identifier, long sequence) -> void
    {
        this->redis->hset(this->hashName, identifier, sequence);
    }

}
