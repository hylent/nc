<?php

(new \Nc\Mvc\Application([
    'Demo' => __DIR__.'/php',
], [
    'cli/sw'    => 'Nc\Mvc\ControllerCliSwoole',
    'cli'       => 'Demo\Controller\Cli',
    'http'      => 'Demo\Controller\Http',
]))->__invoke();
