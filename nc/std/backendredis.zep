namespace Nc\Std;

class BackendRedis implements RateLimiterBackendInterface
{
    protected redis;

    public function __construct(var redis) -> void
    {
        let this->redis = redis;
    }

    public function rateLimiter(string identifier) -> <RateLimiter>
    {
        return new RateLimiter(this, identifier);
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

        let key = (string) sprintf("%s:%d:%d", identifier, seconds, time() / seconds);
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
