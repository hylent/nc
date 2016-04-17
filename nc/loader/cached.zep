namespace Nc\Loader;

use Nc\Cache\CachePool;

class Cached extends LoaderAbstract
{
    protected loader;
    protected cachePool;
    protected cacheTtl;

    public function __construct(<LoaderInterface> loader, <CachePool> cachePool, long cacheTtl = 900) -> void
    {
        let this->loader = loader;
        let this->cachePool = cachePool;
        let this->cacheTtl = cacheTtl;
    }

    public function setLoader(<LoaderInterface> loader) -> void
    {
        let this->loader = loader;
    }

    public function getLoader() -> <LoaderInterface>
    {
        return this->loader;
    }

    public function setCachePool(<CachePool> cachePool) -> void
    {
        let this->cachePool = cachePool;
    }

    public function getCachePool() -> <CachePool>
    {
        return this->cachePool;
    }

    public function setCacheTtl(long cacheTtl) -> void
    {
        let this->cacheTtl = cacheTtl;
    }

    public function getCacheTtl() -> long
    {
        return this->cacheTtl;
    }

    public function clearCache() -> void
    {
        this->cachePool->clear();
    }

    public function findPath(string name) -> string
    {
        var path;

        let path = this->cachePool->$fetch(name);

        if path === null {
            let path = this->loader->findPath(name);
            this->cachePool->store(name, path, this->cacheTtl);
        }

        return path;
    }

}
