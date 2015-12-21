namespace Nc\Action;

abstract class ActionAbstract
{
    protected core;

    public function __construct(<Core> core) -> void
    {
        let this->core = core;
    }

    protected function getServer(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _SERVER[name] {
            return value;
        }

        return defaultValue;
    }

}
