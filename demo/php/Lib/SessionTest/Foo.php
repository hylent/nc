<?php

namespace Demo\Lib\SessionTest;

class Foo implements \Nc\Mvc\SessionAutoGcStorageInterface
{
    public function readSessionData($id)
    {
        return;

        echo __METHOD__, PHP_EOL;
        var_dump(func_get_args());

        return '';
    }

    public function writeSessionData($id, $data, $ttl)
    {
        return;

        echo __METHOD__, PHP_EOL;
        var_dump(func_get_args());
    }

    public function destroySessionData($id)
    {
        return;

        echo __METHOD__, PHP_EOL;
        var_dump(func_get_args());
    }
}
