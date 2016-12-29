namespace Nc\RateLimiter;

class Redis extends RateLimiterBackendAbstract
{
    const DEFAULT_PREFIX    = "ratelimiter:";

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

    public function passRateLimits(string name, array rateLimits) -> boolean
    {
        var pre, now, seconds, times, index, keys = [], argv = [];

        if count(rateLimits) < 1 {
            return true;
        }

        let pre = this->prefix . name;
        let now = time();

        for seconds, times in rateLimits {
            let seconds = (long) seconds;
            let times = (long) times;
            if unlikely seconds < 1 || times < 1 {
                throw new Exception(sprintf("Invalid input seconds/times '%d/%d'", seconds, times));
            }

            let index = (long) (now / seconds);

            let keys[] = sprintf("%s:%d:%d", pre, seconds, index);
            let argv[] = times;
            let argv[] = seconds * (index + 1) - now;
        }

        return (boolean) this->redis->eval(
            "local iv = {}; local v; for i, k in pairs(KEYS) do v = redis.pcall('get', k); if not v then v = 0; end if v - ARGV[i * 2 - 1] >= 0 then return 0; end iv[i] = v end for i, k in pairs(KEYS) do redis.pcall('setex', k, 1 + ARGV[i * 2], iv[i] + 1); end return 1;",
            array_merge(keys, argv),
            count(keys)
        );
    }

}
