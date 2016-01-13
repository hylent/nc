namespace Nc\Renderer;

class Json extends RendererAbstract
{
    protected flag      = 0;
    protected callback  = "";

    public function __construct(bool cors = false) -> void
    {
        let this->extraHeaders["content-type"] = "Content-Type: application/json; charset=UTF-8";
        if cors {
            let this->extraHeaders["access-control-allow-origin"] = "Access-Control-Allow-Origin: *";
        }
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
