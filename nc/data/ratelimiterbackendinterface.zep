namespace Nc\Data;

interface RateLimiterBackendInterface
{
    public function passRateLimiter(string identifier, string item, long seconds, long times) -> bool;

}
