<?php
try {
    $di = new Nc\Factory\Di();
    $di->context = $this;
    $di->loader = $loader = new Nc\Loader\NamespaceDirectory([
        'NcApp' => __DIR__.'/src',
    ]);
    $loader->register();
    new NcApp\Bootstrap($di);
} catch (Exception $ex) {
    if ($this instanceof Nc\Application\Http) {
        $this->status(500);
        $this->header('Content-Type', 'text/plain; charset=UTF-8');
    }
    $this->output($ex);
}
