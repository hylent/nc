namespace Nc\Factory;

class Di extends FactoryAbstract
{
    protected initializers;

    public function __invoke(string name, <\Closure> initializer) -> void
    {
        let this->initializers[name] = initializer;
    }

    public function __set(string name, var production) -> void
    {
        let this->productions[name] = production;
    }

    public function __unset(string name) -> void
    {
        unset this->productions[name];
        unset this->initializers[name];
    }

    public function __isset(string name) -> bool
    {
        return isset this->productions[name] || isset this->initializers[name];
    }

    public function newProduction(string name)
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