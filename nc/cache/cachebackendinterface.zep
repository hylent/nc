namespace Nc\Cache;

interface CacheBackendInterface
{
    public function getPool(string poolName) -> <CachePool>;

    public function clear(string poolName = "") -> void;

    public function store(string poolName, string key, var value, long ttl = 0) -> void;
    public function storeMany(string poolName, array keyValues, long ttl = 0) -> void;

    public function $fetch(string poolName, string key);
    public function fetchMany(string poolName, array keys) -> array;

    public function forget(string poolName, string key) -> void;
    public function forgetMany(string poolName, array keys) -> void;

}
