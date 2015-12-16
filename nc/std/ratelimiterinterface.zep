namespace Nc\Std;

interface RateLimiterInterface
{
    public function passRateLimiter(string identifier, long seconds, long times) -> bool;

}
