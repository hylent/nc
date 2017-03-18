namespace Nc\Config;

interface ConfigInterface
{
    public function get(string name, var defaultValue = null);
}
