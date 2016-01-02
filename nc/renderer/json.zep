namespace Nc\Renderer;

class Json extends RendererAbstract
{
    protected cors      = false;
    protected callback  = "";
    protected flag      = 0;

    public function setCors(bool cors) -> void
    {
        let this->cors = cors;
    }

    public function getCors() -> bool
    {
        return this->cors;
    }

    public function setCallback(string callback) -> void
    {
        let this->callback = callback;
    }

    public function getCallback() -> string
    {
        return this->callback;
    }

    public function setFlag(long flag) -> void
    {
        let this->flag = flag;
    }

    public function getFlag() -> long
    {
        return this->flag;
    }

    public function getExtraHeaders() -> array
    {
        var headers = [];

        let headers[] = "Content-type: application/json; charset=UTF-8";
        if this->cors {
            let headers[] = "Access-Control-Allow-Origin: *";
        }

        return headers;
    }

    public function render() -> void
    {
        string callback;

        let callback = this->callback;
        if callback->length() > 0 {
            echo sprintf("%s(%s);", callback, json_encode(this->data, this->flag));
        } else {
            echo json_encode(this->data, this->flag);
        }
    }

}
