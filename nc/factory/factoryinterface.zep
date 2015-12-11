namespace Nc\Factory;

interface FactoryInterface
{
    public function __isset(string name) -> bool;
    public function __get(string name);

}
