namespace Nc\Application;

use Nc\Renderer\RendererInterface;
use Nc\Renderer\Nil;

abstract class ApplicationAbstract
{
    protected renderer;

    public function getServerVar(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _SERVER[name] {
            return value;
        }

        return defaultValue;
    }

    public function getRequestTime() -> long
    {
        return (long) this->getServerVar("REQUEST_TIME", 0);
    }

    public function getRequestTimeFloat() -> double
    {
        return (double) this->getServerVar("REQUEST_TIME_FLOAT", 0.0);
    }

    public function newUploadedFile(var error, var size, var name, var tmpName) -> <UploadedFile>
    {
        return new UploadedFile(error, size, name, tmpName);
    }

    public function renderer() -> <RendererInterface>
    {
        if this->renderer === null {
            let this->renderer = new Nil();
        }

        return this->renderer;
    }

    public function setRenderer(<RendererInterface> renderer) -> void
    {
        let this->renderer = renderer;
    }

    public function __invoke() -> void
    {
        this->renderer()->render();
    }

}
