<?php

namespace NcApp\Action;

use NcApp\ActionBase;

class Std extends ActionBase
{
    public function __invoke()
    {
        if (1) {
            $sequence = new \Nc\Std\SequenceMysql($this->app->db);
            $r = $sequence->getNextSequence('hi'.(mt_rand() % 3));
            var_dump($r);
        }

        if (1) {
            $rateLimiter = new \Nc\Std\RateLimiterRedis($this->app->redis);
            $r = $rateLimiter->passRateLimiter('hi', 5, 2);
            var_dump($r);
        }

    }

}
