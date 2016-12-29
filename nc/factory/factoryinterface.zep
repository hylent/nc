namespace Nc\Factory;

interface FactoryInterface
{
    public function __isset(string name) -> boolean;
    public function __get(string name);

}
