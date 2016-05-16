namespace Nc\RateLimiter;

class Callback extends RateLimiterBackendAbstract
{
    protected callback;

    public function __construct(var callback) -> void
    {
        let this->callback = callback;
    }

    public function passRateLimits(string name, array rateLimits) -> boolean
    {
        return (boolean) call_user_func(this->callback, name, rateLimits);
    }

}
