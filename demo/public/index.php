<?php

call_user_func(
    function($development) {
        do {
            $appName = 'main';

            if (PHP_SAPI == 'cli') {
                $argv = (array) $_SERVER['argv'];
                array_shift($argv);
                $argv1 = (string) array_shift($argv);
                if ($argv1) {
                    $appName = $argv1;
                }
            } else {
                $m = null;
                if (preg_match('#^/(\w+)#', (string) $_SERVER['REQUEST_URI'], $m)) {
                    $appName = $m[1];
                }
            }

            $appPath = __DIR__.'/../'.$appName.'/php/App.php';
            if (!file_exists($appPath)) {
                break;
            }

            require $appPath;

            $appClass = 'Demo\\'.ucfirst($appName).'\\App';
            if (!class_exists($appClass, false)) {
                break;
            }

            try {
                $appObj = new $appClass();
                $appObj->__invoke();
            } catch (Exception $ex) {
                header('HTTP/1.1 500 Internal Server Error');
                if ($development) {
                    header('Content-type: text/plain; charset=UTF-8');
                    echo $ex, PHP_EOL;
                }
            }

            return;
        } while (false);

        header('HTTP/1.1 404 Not Found');
        if ($development) {
            echo 'App ', $appName, ' not found!', PHP_EOL;
        }
    },
    getenv('DEMO_DEVELOPMENT') || 1
);
