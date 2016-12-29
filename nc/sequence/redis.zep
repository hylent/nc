namespace Nc\Sequence;

class Redis extends SequenceBackendAbstract
{
    const DEFAULT_PREFIX = "sequence:";

    protected redis;
    protected prefix;

    public function __construct(var redis, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->redis = redis;
        let this->prefix = prefix;
    }

    public function getRedis()
    {
        return this->redis;
    }

    public function getPrefix() -> string
    {
        return this->prefix;
    }

    public function next(string name) -> long
    {
        var s;

        let s = this->redis->incr(this->prefix . name, 1);
        if unlikely s === false {
            throw new Exception(sprintf("Cannot get next sequence of '%s'", name));
        }

        return (long) s;
    }

    public function restore(string name, long sequence) -> void
    {
        this->redis->set(this->prefix . name, sequence);
    }

    public function clear() -> void
    {
        var redis, pat, iter = null, ks, k;

        let redis = this->redis;
        let pat = this->prefix . "*";

        redis->setOption(\Redis::OPT_SCAN, \Redis::SCAN_RETRY);

        loop {
            let ks = redis->scan(iter, pat, 1000);
            if ! ks {
                break;
            }

            redis->multi();
            for k in ks {
                redis->del(k);
            }
            redis->exec();
        }
    }

}
