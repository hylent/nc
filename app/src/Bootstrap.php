<?php

namespace NcApp;

class Bootstrap
{
    public function __construct(\Nc\Application $app)
    {
        // configs
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.php');
        $app->mergeConfigsInPathIfValid(__DIR__.'/../config.local.php');

        // di services
        $app('redis', function($app) {
            $redis = new \Redis();
            $redis->connect($app->config('redis.host'), $app->config('redis.port'));
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
