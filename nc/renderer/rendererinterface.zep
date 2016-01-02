namespace Nc\Renderer;

interface RendererInterface
{
    public function render() -> void;
    public function getExtraHeaders() -> array;

}
