<?php

namespace NcApp;

class Bootstrap
{
    public function __construct($di)
    {
        $context = $di->context;

        if ($context instanceof \Nc\Application\Http) {
            $context->header('Content-Type', 'text/plain; charset=UTF-8');
        }

        $context->output(sprintf(
            '%0.3fms,%0.3fM',
            (microtime(true) - $context->getRequestTimeFloat()) * 1e3,
            memory_get_peak_usage() / 1024 /1024
        ));

        $context->output(PHP_EOL);
        $context->output(print_R(get_included_files(), true));
    }

}
