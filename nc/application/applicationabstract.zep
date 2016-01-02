namespace Nc\Application;

abstract class ApplicationAbstract
{
    protected params;
    protected routingParams;
    protected response;

    public function param(string name, var defaultValue = null)
    {
        var value;

        if fetch value, this->params[name] {
            return value;
        }

        return defaultValue;
    }

    public function params() -> array
    {
        return this->params;
    }

    public function routingParams() -> array
    {
        return this->routingParams;
    }

    public function serverVar(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _SERVER[name] {
            return value;
        }

        return defaultValue;
    }

    public function requestTime() -> long
    {
        return (long) this->serverVar("REQUEST_TIME", 0);
    }

    public function requestTimeFloat() -> double
    {
        return (double) this->serverVar("REQUEST_TIME_FLOAT", 0.0);
    }

    public function newUploadedFile(var error, var size, var name, var tmpName) -> <UploadedFile>
    {
        return new UploadedFile(error, size, name, tmpName);
    }

    public function addResponse(string response) -> void
    {
        let this->response = this->response . response;
    }

    public function setResponse(string response) -> void
    {
        let this->response = response;
    }

    public function getResponse() -> string
    {
        return this->response;
    }

    public function __invoke() -> void
    {
        echo this->response;
    }

}
