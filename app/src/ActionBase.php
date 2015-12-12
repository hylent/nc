<?php

namespace NcApp;

abstract class ActionBase
{
    protected $app;

    public function __construct(\Nc\Application $app)
    {
        $this->app = $app;
    }

}
