<?php

namespace NcApp\Action;

use NcApp\ActionBase;

class R extends ActionBase
{
    public function __invoke($c = null)
    {
        if ($c === null) {
            \ReflectionExtension::export('nc');
            return;
        }

        $c = strtr((string) $c, [
            '-' => '\\',
        ]);

        \ReflectionClass::export($c);
    }

}
