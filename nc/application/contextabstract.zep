namespace Nc\Application;

abstract class ContextAbstract
{
    const DEFAULT_BOOTSTRAP_SCRIPT = "bootstrap.php";

    protected serverVars;
    protected params;

    public function bootstrap(string script = "") -> void
    {
        if script->length() < 1 {
            let script = self::DEFAULT_BOOTSTRAP_SCRIPT;
        }

        if file_exists(script) {
            require script;
        }
    }

    public function getServerVar(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->serverVars[name] {
            return value;
        }

        return defaultValue;
    }

    public function getRequestTime() -> double
    {
        return this->getServerVar("REQUEST_TIME");
    }

    public function getRequestTimeFloat() -> double
    {
        return this->getServerVar("REQUEST_TIME_FLOAT");
    }

    public function get(string name, var defaultValue = null)
    {
        return;
    }

    public function getRawInput() -> string
    {
        return "";
    }

    public function getParams() -> array
    {
        return this->params;
    }

    public function output(string content) -> void
    {
        echo content;
    }

}
