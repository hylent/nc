<?php

namespace Demo\Controller;

class SessionTest extends \Nc\Mvc\ControllerDefault
{
    public function initialize()
    {
        ob_start();

        $s = new \Demo\Lib\SessionTest\Foo();
        $h = new \Nc\Mvc\SessionAutoGcSaveHandler($s);

        $h->register();

        var_dump(session_status());

        echo $this->context->startSession(), PHP_EOL;

        var_dump(session_status());
    }

    public function onReturn($re)
    {
        // session_write_close();

        $this->context->header('Content-type', 'text/plain; charset=UTF-8');
        $this->context->output(ob_get_clean());
    }

    public function onException(\Exception $ex)
    {
        echo $ex, PHP_EOL;

        $this->onReturn(null);
    }

    public function execute()
    {
        print_R($_SESSION);
        $_SESSION['a'] = time();
    }
}
