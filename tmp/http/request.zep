namespace Nc\Http;

class Request
{
    protected input;

    public function server(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _SERVER[name] {
            return value;
        }

        return defaultValue;
    }

    public function query(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _GET[name] {
            return value;
        }

        return defaultValue;
    }

    public function post(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _POST[name] {
            return value;
        }

        return defaultValue;
    }

    public function cookie(string name, var defaultValue = null)
    {
        var value;

        if fetch value, _COOKIE[name] {
            return value;
        }

        return defaultValue;
    }

    public function input() -> string
    {
        if this->input === null {
            let this->input = (string) file_get_contents("php://input");
        }

        return this->input;
    }

    public function time() -> long
    {
        return (long) this->server("REQUEST_TIME", 0);
    }

    public function timeFloat() -> double
    {
        return (double) this->server("REQUEST_TIME_FLOAT", 0.0);
    }

    public function method() -> string
    {
        return (string) this->server("REQUEST_METHOD", "UNKNOWN");
    }

    public function isGet() -> bool
    {
        return this->server("REQUEST_METHOD") === "GET";
    }

    public function isPost() -> bool
    {
        return this->server("REQUEST_METHOD") === "POST";
    }

    public function isXhr() -> bool
    {
        return this->server("HTTP_X_REQUESTED_WITH") === "XMLHttpRequest";
    }

    public function ip(string index = "REMOTE_ADDR") -> string
    {
        return (string) this->server(index, "0.0.0.0");
    }

    public function newUploadedFile(var error, var size, var name, var tmpName) -> <UploadedFile>
    {
        return new UploadedFile(error, size, name, tmpName);
    }

    public function hasUploadedFile(string index) -> bool
    {
        var error;

        return fetch error, _FILES[index]["error"] && is_numeric(error);
    }

    public function uploadedFile(string index) -> <UploadedFile>
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

    public function uploadedFiles(string index) -> array
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
