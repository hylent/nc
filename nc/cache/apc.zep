namespace Nc\Cache;

use Nc\Serializer\SerializerInterface;

class Apc extends CacheAbstract
{
    public function __construct() -> void
    {
        if unlikely ! extension_loaded("apc") {
            throw new Exception("Missing extension: apc");
        }
    }

    public function flush() -> void
    {
        apc_clear_cache("user");
    }

    public function rawSet(string key, var value, long lifetime = 0) -> void
    {
        apc_store(key, value, lifetime);
    }

    public function rawGet(string key)
    {
        var r;

        let r = apc_fetch(key);
        if r === false {
            return;
        }

        return r;
    }

    public function rawDelete(string key) -> void
    {
        apc_delete(key);
    }

    public function incrementInteger(string key, long step = 1) -> long
    {
        string realKey;
        var value;

        let realKey = CacheInterface::INTEGER_PREFIX . key;

        let value = apc_inc(realKey, step);
        if value === false {
            apc_store(realKey, step);
            return step;
        }

        return (long) value;
    }

    public function decrementInteger(string key, long step = 1) -> long
    {
        string realKey;
        var value;

        let realKey = CacheInterface::INTEGER_PREFIX . key;

        let value = apc_dec(realKey, step);
        if value === false {
            apc_store(realKey, -step);
            return -step;
        }

        return (long) value;
    }

    public function multiSet(array keyValues, long expiredAt = 0) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->serializer->serialize(v);
        }

        apc_store(data, expiredAt - time());
    }

    public function multiGet(array keys) -> array
    {
        var r, k, v, data = [];

        let r = apc_fetch(keys);
        if typeof r == "array" && r {
            for k, v in r {
                let data[k] = this->serializer->unserialize(v);
            }
        }

        return data;
    }
}
