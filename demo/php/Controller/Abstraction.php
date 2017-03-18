<?php

namespace Demo\Controller;

abstract class Abstraction extends \Nc\Mvc\ControllerDefault
{
    protected function initialize()
    {
        $this->injector->config = new \Nc\Config\Ini(__DIR__.'/../../resource/config');

        $this->injector->setClassNamespace('commonModelRepo', 'Demo\\Model');
        $this->injector->setClassNamespace('cliModelRepo', 'Demo\\Model\\Cli');
    }

    protected function onException(\Exception $ex)
    {
        echo $ex, PHP_EOL;
    }
}
