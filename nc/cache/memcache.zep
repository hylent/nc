namespace Nc\Cache;

use Nc\Serializer\SerializerInterface;

class Memcache extends CacheAbstract
{
    const INCREMENT_MAX = 1000000000;

    protected memcache;

    public function __construct(string host, long port = 11211, long timeout = 5) -> void
    {
        var mc;

        if unlikely ! extension_loaded("memcache") {
            throw new Exception("Missing extension: memcache");
        }

        let mc = new \Memcache();
        if unlikely ! mc->connect(host, port, timeout) {
            throw new Exception("Cannot connect to memcache server");
        }

        let this->memcache = mc;
    }

    public function flush() -> void
    {
        this->memcache->flush();
    }

    public function rawSet(string key, var value, long lifetime = 0) -> void
    {
        this->memcache->set(key, value, 0, lifetime);
    }

    public function rawGet(string key)
    {
        var r;

        let r = this->memcache->get(key);
        if r === false {
            return;
        }

        return r;
    }

    public function rawDelete(string key) -> void
    {
        this->memcache->delete(key);
    }

    public function setInteger(string key, long value) -> void
    {
        this->rawSet(CacheInterface::INTEGER_PREFIX . key, self::INCREMENT_MAX + value);
    }

    public function getInteger(string key) -> long
    {
        var value;

        let value = this->rawGet(CacheInterface::INTEGER_PREFIX . key);
        if value === null {
            return 0;
        }

        return (long) (value - self::INCREMENT_MAX);
    }

    public function incrementInteger(string key, long step = 1) -> long
    {
        var value;

        let value = this->memcache->increment(CacheInterface::INTEGER_PREFIX . key, step);
        if value === false {
            this->setInteger(key, step);
            return step;
        }

        return (long) (value - self::INCREMENT_MAX);
    }

    public function decrementInteger(string key, long step = 1) -> long
    {
        var value;

        let value = this->memcache->decrement(CacheInterface::INTEGER_PREFIX . key, step);
        if value === false {
            this->setInteger(key, -step);
            return -step;
        }

        return (long) (value - self::INCREMENT_MAX);
    }

    public function multiGet(array keys) -> array
    {
        var a, k, v, data = [];

        let a = this->memcache->get(keys);
        if typeof a == "array" && a {
            for k, v in a {
                let data[k] = this->serializer->unserialize(v);
            }
        }

        return data;
    }
}
