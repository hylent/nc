<?php

namespace Demo\Controller;

abstract class Abstraction extends \Nc\Mvc\ControllerDefault
{
    protected function initialize()
    {
        $this->injector->config = new \Nc\Config\Ini(__DIR__.'/../../resource/config');

        $this->injector->setClassNamespace('commonModelRepo', 'Demo\\Model');
        $this->injector->setClassNamespace('cliModelRepo', 'Demo\\Model\\Cli');

        $this->injector['redis'] = function(\Nc\Di\Injector $injector) {
            $h = $injector->config->get('app.redis.host', '127.0.0.1');
            $p = $injector->config->get('app.redis.port', 6379);
            $r = new \Redis();
            $r->connect($h, $p);
            return $r;
        };
    }

    protected function onException(\Exception $ex)
    {
        echo $ex, PHP_EOL;
    }
}
