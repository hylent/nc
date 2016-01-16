namespace Nc\Renderer;

use Nc\Application\ApplicationAbstract;

class Json extends RendererAbstract
{
    protected cors      = false;
    protected flag      = 0;
    protected callback  = "";

    public function setCors(bool cors) -> void
    {
        let this->cors = cors;
    }

    public function getCors() -> bool
    {
        return this->cors;
    }

    public function setFlag(long flag) -> void
    {
        let this->flag = flag;
    }

    public function getFlag() -> long
    {
        return this->flag;
    }

    public function setCallback(string callback) -> void
    {
        let this->callback = callback;
    }

    public function getCallback() -> string
    {
        return this->callback;
    }

    public function withApplication(<ApplicationAbstract> application) -> void
    {
        var headers = [];

        let headers["Content-Type"] = "application/json; charset=UTF-8";
        if this->cors {
            let headers["Access-Control-Allow-Origin"] = "*";
        }

        application->setResponseHeaders(headers);
    }

    public function render() -> void
    {
        string callback;

        let callback = (string) this->callback;
        if callback->length() > 0 {
            echo sprintf("%s(%s);", callback, json_encode(this->data, this->flag));
        } else {
            echo json_encode(this->data, this->flag);
        }
    }

}
