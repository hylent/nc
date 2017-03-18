namespace Nc\Mvc;

use Nc\Di\Injector;

class ControllerDefault implements ControllerInterface
{
    protected injector;
    protected context;

    public function __invoke(<Injector> injector, <ContextAbstract> context) -> void
    {
        var re = null, ex = null;

        let this->injector  = injector;
        let this->context   = context;

        this->initialize();

        try {
            let re = this->execute();
        } catch \Exception, ex {
            this->onException(ex);
            return;
        }

        this->onReturn(re);
    }

    protected function initialize() -> void
    {
        return;
    }

    protected function execute()
    {
        return;
    }

    protected function onReturn(var re) -> void
    {
        return;
    }

    protected function onException(<\Exception> ex) -> void
    {
        throw ex;
    }
}
