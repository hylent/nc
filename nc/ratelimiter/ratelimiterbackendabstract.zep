namespace Nc\RateLimiter;

abstract class RateLimiterBackendAbstract implements RateLimiterBackendInterface
{
    public function getRateLimiter(string name) -> <RateLimiter>
    {
        return new RateLimiter(this, name);
    }

}
