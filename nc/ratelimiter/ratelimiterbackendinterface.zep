namespace Nc\RateLimiter;

interface RateLimiterBackendInterface
{
    public function getRateLimiter(string name) -> <RateLimiter>;

    public function pass(string name, long seconds, long times) -> boolean;
    public function passRateLimits(string name, array rateLimits) -> boolean;

}
