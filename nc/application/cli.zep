namespace Nc\Application;

class Cli extends ApplicationAbstract
{
    public function __construct() -> void
    {
        var args, arg, pos;

        let this->params = [];
        let this->routingParams = [];

        let args = (array) this->serverVar("argv");
        array_shift(args);

        for arg in args {
            let arg = (string) arg;
            if strpos(arg, "--") === 0 {
                let arg = substr(arg, 2);
                let pos = strpos(arg, "=");
                if pos === false {
                    let this->params[arg] = "";
                } else {
                    let this->params[substr(arg, 0, pos)] = substr(arg, pos + 1);
                }
            } else {
                let this->routingParams[] = arg;
            }
        }
    }

}
