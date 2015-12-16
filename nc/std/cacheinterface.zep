namespace Nc\Std;

interface CacheInterface
{
    public function setCache(string identifier, var data, long lifetime = 0) -> void;
    public function getCache(string identifier);
    public function deleteCache(string identifier) -> void;

}
