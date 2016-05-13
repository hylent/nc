namespace Nc\Container;

interface ContainerInterface
{
    public function setSuper(<ContainerInterface> super) -> void;
    public function getSuper() -> <ContainerInterface>;

    public function __isset(string name) -> boolean;
    public function __get(string name);
    public function get(string name, boolean shared = false);

}
