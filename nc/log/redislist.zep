namespace Nc\Log;

class RedisList extends WriterBufferedAbstract
{
    protected redis;
    protected keyName;
    protected ttl;

    public function __construct(var redis, string keyName, long ttl = 3600) -> void
    {
        let this->redis = redis;
        let this->keyName = keyName;
        let this->ttl = ttl;
    }

    public function getRedis()
    {
        return this->redis;
    }

    public function getKeyName() -> string
    {
        return this->keyName;
    }

    public function getTtl() -> long
    {
        return this->ttl;
    }

    public function retrieveLogs(long maxLogs = 1000, long blocking = 10) -> array
    {
        var log, logs = [];
        long c = 0;

        if blocking > 0 {
            let log = this->redis->brpop(this->keyName, blocking);
            if typeof log != "array" || count(log) != 2 {
                return logs;
            }

            let logs[] = log[1];
            let c++;
        }

        loop {
            if c >= maxLogs {
                break;
            }

            let log = this->redis->rpop(this->keyName);
            if log === false {
                break;
            }

            let logs[] = log;
            let c++;
        }

        return logs;
    }

    protected function writeLogs(array logs) -> void
    {
        var redis, log, res;
        long numCmds = 0;

        if count(logs) < 1 {
            return;
        }

        let redis = this->redis->multi(\Redis::PIPELINE);

        for log in logs {
            redis->lpush(this->keyName, log);
            let numCmds++;
        }

        if this->ttl > 0 {
            redis->expire(this->keyName, this->ttl);
            let numCmds++;
        }

        let res = redis->exec();

        if unlikely count(array_filter(res)) != numCmds {
            throw new Exception("Failed to write logs");
        }
    }

}
