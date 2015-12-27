<?php

namespace NcApp;

class Bootstrap
{
    public function __construct($di)
    {
        // configs
        $configs = [];
        foreach ([
            __DIR__.'/../config.php',
            __DIR__.'/../config.local.php',
        ] as $c) {
            if (file_exists($c)) {
                $configs = array_replace_recursive($configs, (array) require $c);
            }
        }
        $di->configs = (object) $configs;

        // di services
        $di('redis', function($di) {
            $config = $di->configs->redis;
            $redis = new \Redis();
            $redis->connect($config['host'], $config['port']);
            return $redis;
        });

        $di('mysql', function($di) {
            $config = $di->configs->mysql;
            return new \Nc\Db\PdoMysql(sprintf(
                'mysql:host=%s;port=%d;dbname=%s;charset=utf8',
                $config['host'],
                $config['port'],
                $config['dbname']
            ), $config['user'], $config['passwd']);
        });

        $di('mongodb', function($di) {
            $config = $di->configs->mongodb;
            return (new \MongoClient(sprintf(
                'mongodb://%s:%d',
                $config['host'],
                $config['port']
            )))->selectDb($config['dbname']);
        });

        $di('', function($di) {
        });

        // routing
        $controllerFactory = new \Nc\Factory\Namespaced(__NAMESPACE__.'\Controller');
        $controllerFactory->setArgs($di);

        \Nc\Application\ControllerAbstract::dispatch($controllerFactory, []);
    }

}
