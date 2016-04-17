namespace Nc\Cache;

class CachePool
{
    protected backend;
    protected name;

    public function __construct(<CacheBackendInterface> backend, string name) -> void
    {
        let this->backend = backend;
        let this->name = name;
    }

    public function getBackend() -> <CacheBackendInterface>
    {
        return this->backend;
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function clear() -> void
    {
        this->backend->clear(this->name);
    }

    public function store(string key, var value, long ttl = 0) -> void
    {
        this->backend->store(this->name, key, value, ttl);
    }

    public function storeMany(array keyValues, long ttl = 0) -> void
    {
        this->backend->storeMany(this->name, keyValues, ttl);
    }

    public function $fetch(string key)
    {
        return this->backend->$fetch(this->name, key);
    }

    public function fetchMany(array keys) -> array
    {
        return this->backend->fetchMany(this->name, keys);
    }

    public function forget(string key) -> void
    {
        this->backend->forget(this->name, key);
    }

    public function forgetMany(array keys) -> void
    {
        this->backend->forgetMany(this->name, keys);
    }

}
