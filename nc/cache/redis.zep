namespace Nc\Cache;

use Nc\Serializer\SerializerInterface;

class Redis extends CacheAdapter
{
    protected redis;

    public function __construct(string host, long port = 6379, long db = 0, long timeout = 5) -> void
    {
        var redis;

        if unlikely ! extension_loaded("redis") {
            throw new Exception("Missing extension: redis");
        }

        let redis = (new \ReflectionClass("Redis"))->newInstance();
        if unlikely ! redis->connect(host, port, timeout) {
            throw new Exception("Cannot connect to redis server");
        }

        if unlikely db > 0 && ! redis->select(db) {
            throw new Exception("Cannot select db to " . db);
        }

        let this->redis = redis;
    }

    public function flush() -> void
    {
        this->redis->flushDb();
    }

    public function rawSet(string key, var value, long lifetime = 0) -> void
    {
        this->redis->set(key, value, lifetime);
    }

    public function rawGet(string key)
    {
        var r;

        let r = this->redis->get(key);
        if r === false {
            return;
        }

        return r;
    }

    public function rawDelete(string key) -> void
    {
        this->redis->del(key);
    }

    public function incrementInteger(string key, long step = 1) -> long
    {
        return this->redis->incrBy(CacheInterface::INTEGER_PREFIX . key, step);
    }

    public function decrementInteger(string key, long step = 1) -> long
    {
        return this->redis->decrBy(CacheInterface::INTEGER_PREFIX . key, step);
    }

    public function multiGet(array keys) -> array
    {
        var a, i, k, v, data = [];

        let a = this->redis->mget(keys);
        for i, k in keys {
            if fetch v, a[i] && v !== false {
                let data[k] = this->getSerializer()->unserialize(v);
            }
        }

        return data;
    }

    public function multiDelete(array keys) -> void
    {
        this->redis->del(keys);
    }

    public function groupSetAll(string group, array keyValues) -> void
    {
        var k, v, data = [];
        string realGroup;

        let realGroup = CacheInterface::GROUP_PREFIX . group;

        for k, v in keyValues {
            let data[k] = this->getSerializer()->serialize(v);
        }

        this->redis->delete(realGroup);
        this->redis->hmset(realGroup, data);
    }

    public function groupGetAll(string group) -> array
    {
        var a, k, v, data;

        let a = this->redis->hgetall(CacheInterface::GROUP_PREFIX . group);
        if typeof a != "array" {
            return;
        }

        let data = [];
        for k, v in a {
            let data[k] = this->getSerializer()->unserialize(v);
        }

        return data;
    }

    public function groupDeleteAll(string group) -> void
    {
        this->redis->delete(CacheInterface::GROUP_PREFIX . group);
    }

    public function groupSet(string group, array keyValues) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->getSerializer()->serialize(v);
        }

        this->redis->hmset(CacheInterface::GROUP_PREFIX . group, data);
    }

    public function groupGet(string group, array keys) -> array
    {
        var a, k, v, data = [];

        let a = this->redis->hmget(CacheInterface::GROUP_PREFIX . group, keys);
        if unlikely typeof a != "array" {
            return;
        }

        for k, v in a {
            if v !== false {
                let data[k] = this->getSerializer()->unserialize(v);
            }
        }

        return data;
    }

    public function groupDelete(string group, array keys) -> void
    {
        var k;

        for k in keys {
            this->redis->hdel(CacheInterface::GROUP_PREFIX . group, k);
        }
    }
}
