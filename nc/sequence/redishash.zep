namespace Nc\Sequence;

class RedisHash extends SequenceBackendAbstract
{
    const DEFAULT_HASH_NAME = "sequencehash";

    protected redis;
    protected hashName;

    public function __construct(var redis, string hashName = self::DEFAULT_HASH_NAME) -> void
    {
        let this->redis = redis;
        let this->hashName = hashName;
    }

    public function getRedis()
    {
        return this->redis;
    }

    public function getHashName() -> string
    {
        return this->hashName;
    }

    public function next(string name) -> long
    {
        var s;

        let s = this->redis->hincrby(this->hashName, name, 1);
        if unlikely s === false {
            throw new Exception(sprintf("Cannot get next sequence of '%s'", name));
        }

        return (long) s;
    }

    public function restore(string name, long sequence) -> void
    {
        this->redis->hset(this->hashName, name, sequence);
    }

    public function clear() -> void
    {
        this->redis->del(this->hashName);
    }

}
