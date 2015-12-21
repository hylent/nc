namespace Nc\Action;

class Http extends ActionAbstract
{
    protected function getRequest(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _REQUEST[name] {
            return value;
        }

        return defaultValue;
    }

    protected function getQuery(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _GET[name] {
            return value;
        }

        return defaultValue;
    }

    protected function getPost(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _POST[name] {
            return value;
        }

        return defaultValue;
    }

    protected function getCookie(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _COOKIE[name] {
            return value;
        }

        return defaultValue;
    }

    protected function getUploadedFile(string name) -> <UploadedFile>
    {
        return new UploadedFile();
    }

    protected function getUploadedFiles(string name) -> array
    {
        return [];
    }

}
