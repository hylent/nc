namespace Nc\Cache;

use Nc\Serializer\SerializerInterface;
use Nc\Serializer\SerializerAwareInterface;

abstract class CacheAdapter implements CacheInterface, SerializerAwareInterface
{
    protected serializer;

    public function setSerializer(<SerializerInterface> serializer) -> void
    {
        let this->serializer = serializer;
    }

    public function getSerializer() -> <SerializerInterface>
    {
        return this->serializer;
    }

    public function setInteger(string key, long value) -> void
    {
        this->rawSet(CacheInterface::INTEGER_PREFIX . key, value);
    }

    public function getInteger(string key) -> long
    {
        return (long) this->rawGet(CacheInterface::INTEGER_PREFIX . key);
    }

    public function deleteInteger(string key) -> void
    {
        this->rawDelete(CacheInterface::INTEGER_PREFIX . key);
    }

    public function incrementInteger(string key, long step = 1) -> long
    {
        long value;

        let value = (long) this->getInteger(key);
        let value += step;
        this->setInteger(key, value);

        return value;
    }

    public function decrementInteger(string key, long step = 1) -> long
    {
        long value;

        let value = (long) this->getInteger(key);
        let value -= step;
        this->setInteger(key, value);

        return value;
    }

    public function set(string key, var value, long lifetime = 0) -> void
    {
        this->rawSet(key, this->getSerializer()->serialize(value), lifetime);
    }

    public function get(string key)
    {
        var r;

        let r = this->rawGet(key);
        if typeof r != "string" || ! r {
            return;
        }

        return this->getSerializer()->unserialize(r);
    }

    public function delete(string key) -> void
    {
        this->rawDelete(key);
    }

    public function multiSet(array keyValues, long expiredAt = 0) -> void
    {
        var k, v;

        for k, v in keyValues {
            this->set(k, v, expiredAt);
        }
    }

    public function multiGet(array keys) -> array
    {
        var r = [], k, v;

        for k in keys {
            let v = this->get(k);
            if v !== null {
                let r[k] = v;
            }
        }

        return r;
    }

    public function multiDelete(array keys) -> void
    {
        var k;

        for k in keys {
            this->delete(k);
        }
    }

    public function groupSetAll(string group, array keyValues) -> void
    {
        string realGroup, prefix;
        var k, v, groupedKeys = [], data = [];

        let realGroup = CacheInterface::GROUP_PREFIX . group;
        let prefix = realGroup . CacheInterface::GROUP_SEPARATOR;

        for k, v in keyValues {
            let groupedKeys[k] = null;
            let data[prefix . k] = v;
        }

        let data[realGroup] = groupedKeys;
        this->multiSet(data, 0);
    }

    public function groupGetAll(string group) -> array
    {
        string realGroup, prefix;
        long prefixLen;
        var groupedKeys, ks = [], k, v, data = [];

        let realGroup = CacheInterface::GROUP_PREFIX . group;

        let groupedKeys = this->get(realGroup);
        if typeof groupedKeys != "array" || ! groupedKeys {
            return;
        }

        let prefix = realGroup . CacheInterface::GROUP_SEPARATOR;
        let prefixLen = prefix->length();

        for k in array_keys(groupedKeys) {
            let ks[] = prefix . k;
        }

        for k, v in this->multiGet(ks) {
            if strpos(k, prefix) === 0 {
                let data[substr(k, prefixLen)] = v;
            }
        }

        return data;
    }

    public function groupDeleteAll(string group) -> void
    {
        string realGroup, prefix;
        var groupedKeys, k, ks = [];

        let realGroup = CacheInterface::GROUP_PREFIX . group;

        let groupedKeys = this->get(realGroup);
        if typeof groupedKeys != "array" || ! groupedKeys {
            return;
        }

        let prefix = realGroup . CacheInterface::GROUP_SEPARATOR;

        for k in array_keys(groupedKeys) {
            let ks[] = prefix . k;
        }

        let ks[] = realGroup;
        this->multiDelete(ks);
    }

    public function groupSet(string group, array keyValues) -> void
    {
        string realGroup, prefix;
        var groupedKeys, k, v, data = [];

        let realGroup = CacheInterface::GROUP_PREFIX . group;

        let groupedKeys = this->get(realGroup);
        if typeof groupedKeys != "array" {
            let groupedKeys = [];
        }

        let prefix = realGroup . CacheInterface::GROUP_SEPARATOR;

        for k, v in keyValues {
            let groupedKeys[k] = null;
            let data[prefix . k] = v;
        }

        let data[realGroup] = groupedKeys;
        this->multiSet(data, 0);
    }

    public function groupGet(string group, array keys) -> array
    {
        string realGroup, prefix;
        long prefixLen;
        var groupedKeys, ks = [], k, v, data = [];

        let realGroup = CacheInterface::GROUP_PREFIX . group;

        let groupedKeys = this->get(realGroup);
        if typeof groupedKeys != "array" || ! groupedKeys {
            return;
        }

        let prefix = realGroup . CacheInterface::GROUP_SEPARATOR;
        let prefixLen = prefix->length();

        for k in array_unique(keys) {
            if array_key_exists(k, groupedKeys) {
                let ks[] = prefix . k;
            }
        }

        if ! ks {
            return [];
        }

        for k, v in this->multiGet(ks) {
            if strpos(k, prefix) === 0 {
                let data[substr(k, prefixLen)] = v;
            }
        }

        return data;
    }

    public function groupDelete(string group, array keys) -> void
    {
        string realGroup, prefix;
        var groupedKeys, k, ks = [];

        let realGroup = CacheInterface::GROUP_PREFIX . group;

        let groupedKeys = this->get(realGroup);
        if typeof groupedKeys != "array" || ! groupedKeys {
            return;
        }

        let prefix = realGroup . CacheInterface::GROUP_SEPARATOR;

        for k in array_unique(keys) {
            if array_key_exists(k, groupedKeys) {
                unset(groupedKeys[k]);
                let ks[] = prefix . k;
            }
        }

        if ks {
            this->set(realGroup, groupedKeys);
            this->multiDelete(ks);
        }
    }
}
