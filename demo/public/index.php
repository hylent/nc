<?php

if (file_exists($_phar = __DIR__.'/../demo.phar')) {
    require $_phar;
} else {
    require __DIR__.'/../bootstrap.php';
}
