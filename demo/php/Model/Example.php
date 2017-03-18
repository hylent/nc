<?php

namespace Demo\Model;

class Example implements \Nc\Di\InjectedPropertyInterface
{
    /**
     * @@ config app.foo
     */
    protected $foo;

    public function getFoo()
    {
        return $this->foo;
    }
}
