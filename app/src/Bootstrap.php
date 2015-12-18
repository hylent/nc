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

        $app('db', function($app) {
            return new \Nc\Db\PdoMysql(sprintf(
                'mysql:host=%s;port=%d;dbname=%s;charset=utf8',
                $app->config('db.host'),
                $app->config('db.port'),
                $app->config('db.dbname')
            ), $app->config('db.user'), $app->config('db.passwd'));
        });

        $app('mongo', function($app) {
            return (new \MongoClient(sprintf(
                'mongodb://%s:%d',
                $app->config('mongo.host'),
                $app->config('mongo.port')
            )))->selectDb($app->config('mongo.dbname'));
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
