namespace Nc\Application;

class Cli extends ApplicationAbstract
{
    protected params;

    public function __construct() -> void
    {
        var args, arg, pos;

        let this->args = [];
        let this->params = [];

        let args = (array) this->serverVar("argv");
        array_shift(args);

        for arg in args {
            let arg = (string) arg;
            if strpos(arg, "--") !== 0 {
                let this->args[] = arg;
                continue;
            }

            let arg = substr(arg, 2);
            let pos = strpos(arg, "=");
            if pos === false {
                let this->params[arg] = "";
            } else {
                let this->params[substr(arg, 0, pos)] = (string) substr(arg, pos + 1);
            }
        }
    }

    public function params() -> array
    {
        return this->params;
    }

    public function get(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->params[name] {
            return value;
        }

        return defaultValue;
    }

}
