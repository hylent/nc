namespace Nc\Std;

class RateLimiterRedis implements RateLimiterInterface
{
    const DEFAULT_PREFIX = "ratelimiter:";

    protected redis;
    protected prefix;

    public function __construct(var redis, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->redis = redis;
        let this->prefix = prefix;
    }

    public function passRateLimiter(string identifier, long seconds, long times) -> bool
    {
        string key;
        var value, result;

        if seconds < 1 {
            let seconds = 1;
        }
        if times < 1 {
            let times = 1;
        }

        let key = (string) sprintf("%s%s:%d:%d", this->prefix, identifier, seconds, time() / seconds);
        let value = this->redis->get(key);

        if value !== false {
            if value >= times {
                return false;
            }

            let value = this->redis->incr(key, 1);
            if value > times {
                return false;
            }

            return true;
        }

        let result = this->redis->multi()
            ->incr(key, 1)
            ->expire(key, seconds + 1)
            ->exec();

        if typeof result == "array" && fetch value, result[0] && value <= times {
            return true;
        }

        return false;
    }

}
