namespace Nc\Std;

class RateLimiter extends StdAbstract
{
    public function __construct(<RateLimiterBackendInterface> backend, string identifier) -> void
    {
        let this->backend = backend;
        let this->identifier = identifier;
    }

    public function pass(long seconds, long times) -> bool
    {
        return this->backend->passRateLimiter(this->identifier, seconds, times);
    }

}
