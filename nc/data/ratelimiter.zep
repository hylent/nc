namespace Nc\Data;

class RateLimiter extends DataAbstract
{
    public function pass(string item, long seconds, long times) -> bool
    {
        return this->backend->passRateLimiter(this->identifier, item, seconds, times);
    }

}
