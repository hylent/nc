<?php

if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}

header('Content-type: text/plain; charset=utf-8');
set_error_handler(\Nc\Std::THROW_ERROR);

try {
    $app = new \Nc\Application();

    $app->loader = new \Nc\Loader\NamespaceDirectory(true, [
        'NcApp' => __DIR__.'/../src',
    ]);

    $app('', function($app) {
    });

    new NcApp\Bootstrap($app);

} catch (Exception $ex) {
    echo $ex, PHP_EOL;
}

echo PHP_EOL, str_repeat('-', 80), PHP_EOL;
echo sprintf('%0.3fs', microtime(true) - $_SERVER['REQUEST_TIME_FLOAT']), PHP_EOL;
echo \Nc\Std::bytesToSize(memory_get_peak_usage()), PHP_EOL;
print_R(get_included_files());
print_R($app);
