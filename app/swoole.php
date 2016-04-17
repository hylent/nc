<?php
$server = new Swoole_Http_Server('0.0.0.0', 9527);
$server->on('request', function($request, $response) {
    $content = '';
    try {
        (new Nc\Application\SwooleHttp($request, $response))->bootstrap(__DIR__.'/bootstrap.php');
    } catch (\Exception $ex) {
        $content = (string) $ex;
    }
    $response->end($content);
});
$server->start();
