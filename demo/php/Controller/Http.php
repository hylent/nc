<?php

namespace Demo\Controller;

class Http extends Abstraction
{
    protected function execute()
    {
        ob_start();

        echo sprintf(
            '%0.3fms %0.3fMb',
            (microtime(true) - $this->context->getRequestTimeFloat()) * 1e3,
            memory_get_peak_usage() / (1 << 20)
        ), PHP_EOL;

        print_R(get_included_files());
        print_R($this);

        $this->context->header('Content-type', 'text/plain; charset=utf-8');
        $this->context->output(ob_get_clean());
    }
}
