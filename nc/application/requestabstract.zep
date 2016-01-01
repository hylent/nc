namespace Nc\Application;

abstract class RequestAbstract
{
    abstract public function getParams() -> array;

    public function getServer(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _SERVER[name] {
            return value;
        }

        return defaultValue;
    }

    public function getRequestTime() -> long
    {
        return (long) this->getServer("REQUEST_TIME", 0);
    }

    public function getRequestTimeFloat() -> double
    {
        return (double) this->getServer("REQUEST_TIME_FLOAT", 0.0);
    }

    public function newUploadedFile(var error, var size, var name, var tmpName) -> <UploadedFile>
    {
        return new UploadedFile(error, size, name, tmpName);
    }

}
