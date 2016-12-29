namespace Nc\Factory;

class Callback extends FactoryAbstract
{
    protected callbacks;

    public function __invoke(string name, var callback) -> void
    {
        if unlikely ! is_callable(callback) {
            throw new Exception(sprintf(
                "Invalid callback '%s'",
                name
            ));
        }

        let this->callbacks[name] = callback;
    }

    public function __isset(string name) -> boolean
    {
        return parent::__isset(name) || isset this->callbacks[name];
    }

    protected function createInternally(string name)
    {
        var callback;

        if unlikely ! fetch callback, this->callbacks[name] {
            throw new Exception(sprintf(
                "No callback for object '%s'",
                name
            ));
        }

        return call_user_func(callback, this, name);
    }

}
