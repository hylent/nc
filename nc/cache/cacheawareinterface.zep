namespace Nc\Cache;

interface CacheAwareInterface
{
    public function setCache(<CacheInterface> cache) -> void;
    public function getCache() -> <CacheInterface>;
}
