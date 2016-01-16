namespace Nc\Renderer;

use Nc\Http\Response;

interface RendererInterface
{
    public function withResponse(<Response> response) -> void;
    public function render() -> void;

}
