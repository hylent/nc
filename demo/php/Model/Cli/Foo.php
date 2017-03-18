<?php

namespace Demo\Model\Cli;

class Foo implements \Nc\Di\InjectedPropertyInterface
{
    /**
     * @@ commonModelRepo.example
     */
    protected $exampleCommonModel;

    public function run()
    {
        var_dump($this->exampleCommonModel->getFoo());
    }

}
