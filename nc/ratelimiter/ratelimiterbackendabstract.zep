namespace Nc\RateLimiter;

abstract class RateLimiterBackendAbstract implements RateLimiterBackendInterface
{
    public function getRateLimiter(string name) -> <RateLimiter>
    {
        return new RateLimiter(this, name);
    }

    public function pass(string name, long seconds, long times) -> boolean
    {
        return this->passRateLimits(name, [seconds: times]);
    }

}
