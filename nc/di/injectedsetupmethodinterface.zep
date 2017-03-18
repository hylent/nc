namespace Nc\Di;

interface InjectedSetupMethodInterface
{
    public function setupByInjector(<Injector> injector) -> void;
}
