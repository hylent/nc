namespace Nc\Cache;

class Apcu extends CacheBackendAbstract
{
    public function __construct() -> void
    {
        if unlikely ! extension_loaded("apcu") {
            throw new Exception("Missing extension 'apcu'");
        }

        if unlikely PHP_SAPI == "cli" && ini_get("apc.enable_cli") != "1" {
            throw new Exception("Missing apcu support in cli mode, check ini item 'apc.enable_cli'");
        }
    }

    public function clear(string poolName = "") -> void
    {
        var iter;

        if poolName->length() < 1 {
            if unlikely ! apc_clear_cache("user") {
                throw new Exception("Cannot clear all user caches");
            }
            return;
        }

        let iter = new \ApcIterator("user", "/^" . preg_quote(poolName . ":", "/") . "/", APC_ITER_KEY, 1000);

        iter->rewind();
        while iter->valid() {
            apc_delete(iter->key());
            iter->next();
        }
    }

    public function store(string poolName, string key, var value, long ttl = 0) -> void
    {
        if unlikely ! apc_store(poolName . ":" . key, value, ttl) {
            throw new Exception(sprintf("Cannot store cache key '%s'", key));
        }
    }

    public function storeMany(string poolName, array keyValues, long ttl = 0) -> void
    {
        var k, v, kvs = [];

        for k, v in keyValues {
            let kvs[poolName . ":" . k] = v;
        }

        if unlikely !! apc_store(kvs, null, ttl) {
            throw new Exception("Cannot store cache keys");
        }
    }

    public function $fetch(string poolName, string key)
    {
        var value, success = null;

        let value = apc_fetch(poolName . ":" . key, success);
        if success {
            return value;
        }
    }

    public function fetchMany(string poolName, array keys) -> array
    {
        var pre, k, ks = [], success = null, kvs, v, len, r = [];

        let pre = poolName . ":";

        for k in keys {
            let ks[] = pre . k;
        }

        let kvs = apc_fetch(ks, success);
        if success {
            let len = strlen(pre);
            for k, v in kvs {
                let r[substr(k, len)] = v;
            }
        }

        return r;
    }

    public function forget(string poolName, string key) -> void
    {
        apc_delete(poolName . ":" . key);
    }

}
