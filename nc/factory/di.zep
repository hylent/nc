namespace Nc\Factory;

class Di extends FactoryAbstract
{
    protected initializers;

    public function __invoke(string name, <\Closure> initializer) -> void
    {
        let this->initializers[name] = initializer;
    }

    public function __set(string name, var obj) -> void
    {
        let this->creations[name] = obj;
    }

    public function __unset(string name) -> void
    {
        unset this->creations[name];
        unset this->initializers[name];
    }

    public function __isset(string name) -> bool
    {
        return parent::__isset(name) || isset this->initializers[name];
    }

    protected function createInternally(string name)
    {
        var initializer;

        if unlikely ! fetch initializer, this->initializers[name] {
            throw new Exception("Invalid production: " . name);
        }

        if unlikely typeof initializer != "object" || ! (initializer instanceof \Closure) {
            throw new Exception("Invalid production initializer: " . name);
        }

        return call_user_func(initializer, this);
    }

}
