namespace Nc\Container;

abstract class ContainerAbstract implements ContainerInterface
{
    protected super;

    public function setSuper(<ContainerInterface> super) -> void
    {
        let this->super = super;
    }

    public function getSuper() -> <ContainerInterface>
    {
        return this->super;
    }

    public function __get(string name)
    {
        return this->get(name, true);
    }

}
