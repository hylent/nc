namespace Nc\Application;

class Cli extends ContextAbstract
{
    protected args;

    public function __construct() -> void
    {
        var args, arg, pos;

        let this->serverVars = _SERVER;
        let this->params = [];
        let this->args = [];

        let args = this->getServerVar("argv");

        if typeof args == "array" {
            array_shift(args);

            for arg in args {
                let arg = (string) arg;
                if strpos(arg, "--") !== 0 {
                    let this->params[] = arg;
                    continue;
                }

                let arg = (string) substr(arg, 2);
                let pos = strpos(arg, "=");
                if pos === false {
                    let this->args[arg] = "";
                } else {
                    let this->args[substr(arg, 0, pos)] = (string) substr(arg, pos + 1);
                }
            }
        }
    }

    public function get(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->args[name] {
            return value;
        }

        return defaultValue;
    }

    public function getRawInput() -> string
    {
        return file_get_contents("php://stdin");
    }

}
