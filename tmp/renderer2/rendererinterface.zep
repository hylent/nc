namespace Nc\Renderer;

use Nc\Application\ApplicationAbstract;

interface RendererInterface
{
    public function withApplication(<ApplicationAbstract> application) -> void;
    public function render() -> void;

}
