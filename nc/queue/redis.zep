namespace Nc\Queue;

class Redis implements QueueInterface
{
    protected redis;
    protected keyName;

    public function __construct(var redis, string keyName) -> void
    {
        let this->redis = redis;
        let this->keyName = keyName;
    }

    public function getRedis()
    {
        return this->redis;
    }

    public function getKeyName() -> string
    {
        return this->keyName;
    }

    public function put(string id, long delay = 0) -> void
    {
        var r;

        let r = this->redis->zAdd(this->keyName, time() + delay, id);
        if unlikely r === false {
            throw new Exception(this->keyName, Exception::PUT_FAILURE);
        }
    }

    public function reserve(long ttr) -> string
    {
        var args = [], r;

        if unlikely ttr < 1 {
            throw new Exception(__FUNCTION__, Exception::RESERVE_INVALID_TTR);
        }

        let args[] = this->keyName;
        let args[] = time();
        let args[] = ttr;

        let r = (string) this->redis->eval(
            "local t = redis.pcall('zrangebyscore', KEYS[1], 1, ARGV[1], 'limit', 0, 1); if type(t) == 'table' and t[1] then redis.pcall('zadd', KEYS[1], ARGV[1] + ARGV[2], t[1]); return t[1]; end",
            args,
            1
        );

        if unlikely r === false {
            throw new Exception(this->keyName, Exception::RESERVE_FAILURE);
        }

        return (string) r;
    }

    public function delete(string id) -> void
    {
        var r;

        let r = this->redis->zRem(this->keyName, id);
        if unlikely r === false {
            throw new Exception(this->keyName, Exception::DELETE_FAILURE);
        }
    }

}
