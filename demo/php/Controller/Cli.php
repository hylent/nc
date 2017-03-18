<?php

namespace Demo\Controller;

class Cli extends Abstraction
{
    protected function execute()
    {
        $argVec = $this->context->getArgVector();
        $arg0 = (string) array_shift($argVec);

        switch ($arg0) {
            case 'ping':
                echo 'pong', PHP_EOL;
                break;

            case 'foo':
                $this->injector->__get('cliModelRepo.foo')->run();
                break;

            case 'ex':
                throw new \RuntimeException(__METHOD__);

            case 'build':
                $baseDir = __DIR__.'/../..';
                $pharPath = $baseDir.'/demo.phar';
                if (file_exists($pharPath)) {
                    unlink($pharPath);
                }
                $phar = new \Phar($pharPath);
                $phar->buildFromDirectory($baseDir, '@/(php|resource|bootstrap\.php)@');
                $phar->setStub("<?php require 'phar://'.__FILE__.'/bootstrap.php'; __HALT_COMPILER(); ?>");
                break;
        }
    }
}
