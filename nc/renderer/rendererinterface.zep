namespace Nc\Renderer;

interface RendererInterface
{
    public function getExtraHeaders() -> array;
    public function render() -> void;

}
