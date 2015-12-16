namespace Nc\Std;

class GroupedRedisHash implements GroupedInterface
{
    const DEFAULT_PREFIX = "groupedhash:";

    protected redis;
    protected prefix;

    public function __construct(var redis, string prefix = self::DEFAULT_PREFIX) -> void
    {
        let this->redis = redis;
        let this->prefix = prefix;
    }

    public function setGrouped(string identifier, string key, var value) -> void
    {
        this->redis->hset(this->prefix . identifier, key, value);
    }

    public function getGrouped(string identifier, string key)
    {
        var value;

        let value = this->redis->hget(this->prefix . identifier, key);
        if value === false {
            return;
        }

        return value;
    }

    public function deleteGrouped(string identifier, string key) -> void
    {
        this->redis->hdel(this->prefix . identifier, key);
    }

    public function setManyGrouped(string identifier, array keyValues) -> void
    {
        this->redis->hmset(this->prefix . identifier, keyValues);
    }

    public function getManyGrouped(string identifier, array keys) -> array
    {
        var a, k, v, r = [];

        if unlikely count(keys) < 1 {
            return r;
        }

        let a = this->redis->hmget(this->prefix . identifier, keys);
        if unlikely typeof a != "array" {
            return r;
        }

        for k in keys {
            if fetch v, a[k] && v !== false {
                let r[k] = v;
            }
        }

        return r;
    }

    public function deleteManyGrouped(string identifier, array keys) -> void
    {
        string hashName;
        var k;

        let hashName = this->prefix . identifier;

        for k in keys {
            this->redis->hdel(hashName, k);
        }
    }

    public function setAllGrouped(string identifier, array keyValues) -> void
    {
        string hashName;

        let hashName = this->prefix . identifier;

        this->redis->multi()
            ->delete(hashName)
            ->hmset(hashName, keyValues)
            ->exec();
    }

    public function getAllGrouped(string identifier) -> array
    {
        var a;

        let a = this->redis->hgetall(this->prefix . identifier);
        if typeof a != "array" {
            return [];
        }

        return a;
    }

    public function deleteAllGrouped(string identifier) -> void
    {
        this->redis->delete(this->prefix . identifier);
    }

}
