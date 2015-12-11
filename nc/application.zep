namespace Nc;

class Application extends Di implements \ArrayAccess
{
    protected configs;
    protected data;

    public function __construct(array configs = []) -> void
    {
        let this->configs = configs;
    }

    public function config(string name, var defaultValue = null)
    {
        return Std::valueOf(this->configs, name, defaultValue);
    }

    public function mergeConfigs(array configs) -> void
    {
        let this->configs = array_replace_recursive(this->configs, configs);
    }

    public function mergeConfigsInPathIfValid(string path) -> void
    {
        var configs;

        if ! file_exists(path) {
            return;
        }

        let configs = require path;

        if typeof configs != "array" {
            return;
        }

        this->mergeConfigs(configs);
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
