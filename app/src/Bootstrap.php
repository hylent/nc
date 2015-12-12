<?php

namespace NcApp;

class Bootstrap
{
    public function __construct(\Nc\Application $app)
    {
        $actionFactory = new \Nc\Factory\Namespaced(__NAMESPACE__.'\Action');
        $actionFactory->setArgs($app);

        $router = new \Nc\Router\Action($actionFactory);
        $router->setSource(new \Nc\Router\SourceSapiStrategy());

        $router->route();
    }

}
