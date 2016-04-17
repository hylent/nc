namespace Nc\RateLimiter;

class RateLimiter
{
    protected backend;
    protected name;

    public function __construct(<RateLimiterBackendInterface> backend, string name) -> void
    {
        let this->backend = backend;
        let this->name = name;
    }

    public function getBackend() -> <RateLimiterBackendInterface>
    {
        return this->backend;
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function pass(long seconds, long times) -> boolean
    {
        return this->backend->pass(this->name, seconds, times);
    }

    public function passRateLimits(array rateLimits) -> boolean
    {
        return this->backend->passRateLimits(this->name, rateLimits);
    }

}
