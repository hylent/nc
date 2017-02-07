<?php

namespace Demo\Main;

class App
{
    public function __invoke()
    {
        throw new \RuntimeException();
    }
}
