namespace Nc\Mvc;

class ContextCli extends ContextAbstract
{
    protected paramMap;

    public function __construct() -> void
    {
        var args, arg, pos;

        let this->serverVars = _SERVER;
        let this->argVector = [];
        let this->paramMap = [];

        let args = this->getServerVar("argv");

        if typeof args == "array" {
            array_shift(args);

            for arg in args {
                let arg = (string) arg;
                if strpos(arg, "--") !== 0 {
                    let this->argVector[] = arg;
                    continue;
                }

                let arg = (string) substr(arg, 2);
                let pos = strpos(arg, "=");
                if pos === false {
                    let this->paramMap[arg] = "";
                } else {
                    let this->paramMap[substr(arg, 0, pos)] = (string) substr(arg, pos + 1);
                }
            }
        }
    }

    public function getRoutingNames() -> array
    {
        return [
            "cli"
        ];
    }

    public function getParamMap() -> array
    {
        return this->paramMap;
    }

    public function getParam(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->paramMap[name] {
            return value;
        }

        return defaultValue;
    }

}
