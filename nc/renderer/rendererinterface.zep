namespace Nc\Renderer;

interface RendererInterface
{
    public function getHeaders() -> array;
    public function render() -> void;

}
