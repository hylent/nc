<?php

namespace Demo\Controller;

class CliTaskQueueConsumer extends Abstraction
{
    protected $numProcesses = 1;

    protected function initialize()
    {
        parent::initialize();

        $this->injector->jobQueue = new \Nc\Queue\Redis($this->injector->redis, 'job:test');
    }

    protected function execute()
    {
        $expire = time() + 60 * $this->numProcesses;

        while (1) {
            if (time() >= $expire) {
                break;
            }

            $jobId = $this->injector->jobQueue->reserve(120 * $this->numProcesses);

            if ($jobId) {
                $this->doJob($jobId);
            } else {
                echo '#sleep5', PHP_EOL;
                sleep(5);
            }
        }
    }

    protected function doJob($jobId)
    {
        echo '@', $jobId, PHP_EOL;
        sleep(10);
    }
}
