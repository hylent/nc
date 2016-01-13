namespace Nc\Renderer;

abstract class RendererAbstract implements RendererInterface, \ArrayAccess
{
    protected headers;
    protected data;

    public function getHeaders() -> array
    {
        if count(this->headers) > 0 {
            return this->headers;
        }

        return [];
    }

    public function setData(array data) -> void
    {
        var k, v;

        for k, v in data {
            let this->data[k] = v;
        }
    }

    public function getData() -> array
    {
        if count(this->data) > 0 {
            return this->data;
        }

        return [];
    }

    public function offsetSet(string key, var value) -> void
    {
        let this->data[key] = value;
    }

    public function offsetGet(string key)
    {
        var value;

        if fetch value, this->data[key] {
            return value;
        }
    }

    public function offsetExists(string key) -> bool
    {
        return isset this->data[key];
    }

    public function offsetUnset(string key) -> void
    {
        unset this->data[key];
    }

}
