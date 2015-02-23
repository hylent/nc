namespace Nc\Router;

interface RouterInterface
{
    const DEFAULT_CONTROLLER = "index";
    const DEFAULT_ACTION = "index";

    public function getController() -> string;
    public function getAction() -> string;
    public function getParams() -> array;

    public function __invoke() -> string;
}
