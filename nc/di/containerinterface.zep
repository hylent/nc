namespace Nc\Di;

interface ContainerInterface
{
    public function __isset(string name) -> boolean;
    public function __get(string name);
}
