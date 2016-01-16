namespace Nc\Renderer;

use Nc\Application\ApplicationAbstract;

class Nil implements RendererInterface
{
    public function withApplication(<ApplicationAbstract> application) -> void
    {
        return;
    }

    public function render() -> void
    {
        return;
    }

}
