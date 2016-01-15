namespace Nc\Renderer;

use Nc\Http\Response;

class Nil implements RendererInterface
{
    public function withResponse(<Response> response) -> void
    {
        return;
    }

    public function render() -> void
    {
        return;
    }

}
