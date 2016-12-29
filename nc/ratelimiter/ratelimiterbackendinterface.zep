namespace Nc\RateLimiter;

interface RateLimiterBackendInterface
{
    public function getRateLimiter(string name) -> <RateLimiter>;

    public function passRateLimits(string name, array rateLimits) -> boolean;

}
