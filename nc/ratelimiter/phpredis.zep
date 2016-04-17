namespace Nc\RateLimiter;

class PhpRedis extends RateLimiterBackendAbstract
{
    const DEFAULT_TTL       = 60;
    const DEFAULT_PREFIX    = "ratelimiter:";

    protected redis;
    protected prefix;

    public function __construct(var redis, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->redis = redis;
        let this->prefix = prefix;
    }

    public function getPhpRedis()
    {
        return this->redis;
    }

    public function getPrefix() -> string
    {
        return this->prefix;
    }

    public function passRateLimits(string name, array rateLimits) -> boolean
    {
        var seconds, times, validRateLimits = [], redis, pre, now, k, v, r, fallbacks = [];
        boolean pass = true;

        for seconds, times in rateLimits {
            let seconds = (long) seconds;
            let times = (long) times;
            if unlikely seconds < 1 || times < 1 {
                throw new Exception(sprintf("Invalid input seconds/times '%d/%d'", seconds, times));
            }
            let validRateLimits[seconds] = times;
        }

        let redis = this->redis;
        let pre = this->prefix . name;
        let now = time();

        for seconds, times in validRateLimits {
            let k = sprintf("%s:%d:%d", pre, seconds, now / seconds);
            let v = redis->get(k);

            if v === false {
                let r = redis->multi()
                    ->incr(k, 1)
                    ->expire(k, seconds + self::DEFAULT_TTL)
                    ->exec();
                if typeof r != "array" || ! fetch v, r[0] {
                    let v = false;
                }
            } else {
                if v >= times {
                    let pass = false;
                    break;
                }
                let v = redis->incr(k, 1);
            }

            if unlikely v === false {
                throw new Exception(sprintf("Cannot incr key '%s'", k));
            }

            let fallbacks[] = k;

            if v <= times {
                continue;
            }

            let pass = false;
            break;
        }

        if pass {
            return true;
        }

        if count(fallbacks) > 0 {
            redis->multi();
            for k in fallbacks {
                redis->incr(k, -1);
            }
            if unlikely ! redis->exec() {
                throw new Exception("Cannot decr fallback keys");
            }
        }

        return false;
    }

}
