namespace Nc\Di;

abstract class CreatorAbstract implements ContainerInterface, InjectedSetupMethodInterface
{
    protected injector;

    public function setupByInjector(<Injector> injector) -> void
    {
        let this->injector = injector;
    }

    public function __isset(string name) -> boolean
    {
        return (string) this->getValidClassName(name) !== "";
    }

    public function __get(string name)
    {
        var className;

        let className = (string) this->getValidClassName(name);

        return this->injector->__invoke(className);
    }

    abstract public function getValidClassName(string name) -> string;
}
