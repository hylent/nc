namespace Nc\RateLimiter;

class Wrapper extends RateLimiterBackendAbstract
{
    protected wrapped;

    public function __construct(var wrapped) -> void
    {
        let this->wrapped = wrapped;
    }

    public function passRateLimits(string name, array rateLimits) -> boolean
    {
        return (boolean) call_user_func(this->wrapped, name, rateLimits);
    }

}
