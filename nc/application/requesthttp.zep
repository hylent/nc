namespace Nc\Application;

class RequestHttp extends RequestAbstract
{
    public function getParams() -> array
    {
        string uri;
        var pos;

        let uri = (string) this->getServer("REQUEST_URI", "/");
        let pos = strpos(uri, "?");
        if pos !== false {
            let uri = (string) substr(uri, 0, pos);
        }

        return preg_split("#/+#", uri, 0, PREG_SPLIT_NO_EMPTY);
    }

    public function getMethod() -> string
    {
        return (string) this->getServer("REQUEST_METHOD", "UNKNOWN");
    }

    public function getIp(string index = "REMOTE_ADDR") -> string
    {
        return (string) this->getServer(index, "0.0.0.0");
    }

    public function getRequest(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _REQUEST[name] {
            return value;
        }

        return defaultValue;
    }

    public function getQuery(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _GET[name] {
            return value;
        }

        return defaultValue;
    }

    public function getPost(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _POST[name] {
            return value;
        }

        return defaultValue;
    }

    public function getCookie(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _COOKIE[name] {
            return value;
        }

        return defaultValue;
    }

    public function hasUploadedFile(string index) -> bool
    {
        return isset _FILES[index];
    }

    public function getUploadedFile(string index) -> <UploadedFile>
    {
        var a, error, size, name, tmpName;

        loop {
            if unlikely ! fetch a, _FILES[index] || typeof a != "array" {
                break;
            }

            if unlikely ! fetch error, a["error"] || typeof error != "int" {
                break;
            }
            if unlikely ! fetch size, a["size"] || typeof size != "int" {
                break;
            }
            if unlikely ! fetch name, a["name"] || typeof name != "string" {
                break;
            }
            if unlikely ! fetch tmpName, a["tmp_name"] || typeof tmpName != "string" {
                break;
            }

            return this->newUploadedFile(error, size, name, tmpName);
        }

        throw new Exception("Invalid uploaded file: " . index);
    }

    public function getUploadedFiles(string index) -> array
    {
        var files = [], a, errors, i, error, size, name, tmpName;

        if unlikely ! fetch a, _FILES[index] && typeof a != "array" {
            return files;
        }

        if unlikely ! fetch errors, a["error"] && typeof errors != "array" {
            return files;
        }

        for i, error in errors {
            if unlikely ! fetch size, a["size"][i] || typeof size != "int" {
                continue;
            }
            if unlikely ! fetch name, a["name"][i] || typeof name != "string" {
                continue;
            }
            if unlikely ! fetch tmpName, a["tmp_name"][i] || typeof tmpName != "string" {
                continue;
            }

            let files[i] = this->newUploadedFile(error, size, name, tmpName);
        }

        return files;
    }

}
