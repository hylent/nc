<?php

namespace NcApp\Action;

use NcApp\ActionBase;

class Std extends ActionBase
{
    public function __invoke()
    {
        $args = func_get_args();
        $m = (string) array_shift($args);

        if ($m === '' || !method_exists($this, $m)) {
            throw new \RuntimeException($m);
        }

        call_user_func_array([$this, $m], $args);
    }

    public function g($type)
    {
        switch ($type) {
            case 'r':
                $g = new \Nc\Std\GroupedRedisHashSerialized($this->app->redis);
                break;

            case 'p':
                $gr = new \Nc\Std\GroupedRedisHashSerialized($this->app->redis);
                $gm = new \Nc\Std\GroupedMongoCollections($this->app->mongo);
                $g = new \Nc\Std\GroupedProxy($gr, $gm);
                break;

            default:
                throw new \RuntimeException($type);
        }

        var_dump($g->getGrouped('test', 'a'));
        print_R($g->getAllGrouped('test'));

        // $g->setGrouped('test', 'a', mt_rand());
    }

    public function cache($type)
    {
        switch ($type) {
            case 'apc':
                $cache = new \Nc\Std\CacheApc();
                break;
            case 'fs':
                $cache = new \Nc\Std\CacheFileSystem('/tmp/cache');
                break;

            default:
                throw new \RuntimeException($type);
        }

        var_dump($cache->getCache('test'));

        $cache->deleteCache('test');
        var_dump($cache->getCache('test'));

        $cache->setCache('test', mt_rand(), 5);
        var_dump($cache->getCache('test'));
    }

    public function seq()
    {
        $sequence = new \Nc\Std\SequenceMysql($this->app->db);
        $r = $sequence->getNextSequence('hi'.(mt_rand() % 3));
        var_dump($r);
    }

    public function rl()
    {
        $rateLimiter = new \Nc\Std\RateLimiterRedis($this->app->redis);
        $r = $rateLimiter->passRateLimiter('hi', 5, 2);
        var_dump($r);
    }

}
