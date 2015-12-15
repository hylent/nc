namespace Nc\Std;

interface RateLimiterBackendInterface
{
    public function passRateLimiter(string identifier, long seconds, long times) -> bool;

}
