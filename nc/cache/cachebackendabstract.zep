namespace Nc\Cache;

abstract class CacheBackendAbstract implements CacheBackendInterface
{
    public function getPool(string poolName) -> <CachePool>
    {
        return new CachePool(this, poolName);
    }

    public function storeMany(string poolName, array keyValues, long ttl = 0) -> void
    {
        var key, value;

        for key, value in keyValues {
            this->store(poolName, key, value, ttl);
        }
    }

    public function fetchMany(string poolName, array keys) -> array
    {
        var key, value, keyValues = [];

        for key in keys {
            let value = this->$fetch(poolName, key);
            if value !== null {
                let keyValues[key] = value;
            }
        }

        return keyValues;
    }

    public function forgetMany(string poolName, array keys) -> void
    {
        var key;

        for key in keys {
            this->forget(poolName, key);
        }
    }

}
