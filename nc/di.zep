namespace Nc;

class Di
{
    protected services;
    protected serviceInitializers;

    public function __invoke(string name, <\Closure> initializer) -> void
    {
        let this->serviceInitializers[name] = initializer;
    }

    public function __get(string name)
    {
        var service, initializer;

        if fetch service, this->services[name] {
            return service;
        }

        if unlikely ! fetch initializer, this->serviceInitializers[name] {
            throw new Exception("Invalid service: " . name);
        }

        if unlikely typeof initializer != "object" || ! (initializer instanceof \Closure) {
            throw new Exception("Invalid service initializer: " . name);
        }

        let service = {initializer}(this);
        let this->services[name] = service;

        return service;
    }

    public function __set(string name, var obj) -> void
    {
        let this->services[name] = obj;
    }

    public function __isset(string name) -> bool
    {
        return isset this->services[name] || isset this->serviceInitializers[name];
    }

    public function __unset(string name) -> void
    {
        unset this->services[name];
        unset this->serviceInitializers[name];
    }

}
