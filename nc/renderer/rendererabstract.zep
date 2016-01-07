namespace Nc\Renderer;

abstract class RendererAbstract implements RendererInterface, \ArrayAccess
{
    protected extraHeaders;
    protected data;

    public function getExtraHeaders() -> array
    {
        return (array) this->extraHeaders;
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
        return (array) this->data;
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
