<?php

namespace App\Action;

class Index
{
    public function __invoke()
    {
        print_R(func_get_args());
    }

}
