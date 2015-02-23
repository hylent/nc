namespace Nc\Router;

interface RouterAwareInterface
{
    public function setRouter(<RouterInterface> router) -> void;
    public function getRouter() -> <RouterInterface>;
}
