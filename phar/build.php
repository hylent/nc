<?php

$f = __DIR__.'/NcApp.phar';

if (file_exists($f)) {
    unlink($f);
}

$phar = new \Phar($f);
$phar->buildFromDirectory(__DIR__.'/../app');

$stub = $phar->createDefaultStub('public/index.php');
$phar->setStub($stub);
