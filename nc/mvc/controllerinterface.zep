namespace Nc\Mvc;

use Nc\Di\Injector;

interface ControllerInterface
{
    const TYPE = __CLASS__;

    public function __invoke(<Injector> injector, <ContextAbstract> context) -> void;
}
