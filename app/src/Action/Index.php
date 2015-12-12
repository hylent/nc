<?php

namespace NcApp\Action;

use NcApp\ActionBase;

class Index extends ActionBase
{
    public function __invoke()
    {
        print_R(func_get_args());
    }

}
