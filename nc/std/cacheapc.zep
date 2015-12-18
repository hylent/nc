namespace Nc\Std;

class CacheApc implements CacheInterface
{
    const DEFAULT_PREFIX = "cache:";

    protected prefix;

    public function __construct(string prefix = self::DEFAULT_PREFIX) -> void
    {
        if unlikely ! extension_loaded("apc") {
            throw new Exception("Missing extension: apc");
        }

        let this->prefix = prefix;
    }

    public function setCache(string identifier, var data, long lifetime = 0) -> void
    {
        if unlikely ! apc_store(this->prefix . identifier, data, lifetime) {
            throw new Exception("Cannot apc_store cache data: " . identifier);
        }
    }

    public function getCache(string identifier)
    {
        var data, success = null;

        let data = apc_fetch(this->prefix . identifier, success);
        if success {
            return data;
        }
    }

    public function deleteCache(string identifier) -> void
    {
        apc_delete(this->prefix . identifier);
    }

}
