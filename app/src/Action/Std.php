<?php

namespace NcApp\Action;

use NcApp\ActionBase;

class Std extends ActionBase
{
    public function __invoke()
    {
        $b = $this->app->stdRedis->rateLimiter('test')->pass(5, 2);
        var_dump($b);
    }

}
