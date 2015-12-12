<?php

if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}

header('Content-type: text/plain; charset=utf-8');
set_error_handler(\Nc\Std::THROW_ERROR);

// ReflectionExtension::export('nc');

try {
    $app = new \Nc\Application();

    $app->loader = new \Nc\Loader\NamespaceDirectory(true, [
        'App' => __DIR__.'/../app/src',
    ]);

    $app('', function($app) {
    });

    $app('actionFactory', function($app) {
        return new \Nc\Factory\Namespaced('App\Action');
    });

    $app('router', function($app) {
        $router = new \Nc\Router\Action($app->actionFactory);
        $router->setSource(new \Nc\Router\SourceSapiStrategy());
        return $router;
    });

    $router = $app->router;
    $router->route();

} catch (Exception $ex) {
    echo $ex, PHP_EOL;
}

echo PHP_EOL, str_repeat('-', 80), PHP_EOL;
echo sprintf('%0.3fs', microtime(true) - $_SERVER['REQUEST_TIME_FLOAT']), PHP_EOL;
echo \Nc\Std::bytesToSize(memory_get_peak_usage()), PHP_EOL;
print_R(get_included_files());
print_R($app);
