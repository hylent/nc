<?php

namespace NcApp;

class Bootstrap
{
    public function __construct(\Nc\Application $app)
    {
        // di services
        $app('redis', function($app) {
            $redis = new \Redis();
            $redis->connect('192.168.255.11', 6379);
            return $redis;
        });

        $app('stdRedis', function($app) {
            return new \Nc\Std\BackendRedis($app->redis);
        });

        $app('', function($app) {
        });

        // routing
        $actionFactory = new \Nc\Factory\Namespaced(__NAMESPACE__.'\Action');
        $actionFactory->setArgs($app);

        $router = new \Nc\Router\Action($actionFactory);
        $router->setSource(new \Nc\Router\SourceSapiStrategy());

        $router->route();
    }

}
