namespace Nc\Mvc;

abstract class ContextAbstract
{
    protected serverVars;
    protected argVector;
    protected numUsedArgs = 0;

    public function getRoutingNames() -> array
    {
        return [];
    }

    public function getServerVar(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->serverVars[name] {
            return value;
        }

        return defaultValue;
    }

    public function getArgVector() -> array
    {
        return this->argVector;
    }

    public function setNumUsedArgs(long numUsedArgs) -> void
    {
        if numUsedArgs < 0 {
            let numUsedArgs = 0;
        }

        let this->numUsedArgs = numUsedArgs;
    }

    public function getAvailableArgs() -> array
    {
        return array_slice(this->argVector, this->numUsedArgs);
    }

    public function getParamMap() -> array
    {
        throw new Exception("Unaccomplished");
    }

    public function getParam(string name, var defaultValue = null)
    {
        throw new Exception("Unaccomplished");
    }

    public function getRequestTime() -> double
    {
        return this->getServerVar("REQUEST_TIME");
    }

    public function getRequestTimeFloat() -> double
    {
        return this->getServerVar("REQUEST_TIME_FLOAT");
    }

    public function output(string content) -> void
    {
        echo content;
    }
}
