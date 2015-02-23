namespace Nc\Router;

class UriEnhanced extends Uri
{
    public function __construct() -> void
    {
        var uri, baseUri, scriptName, pos;

        if PHP_SAPI == "cli" {
            if ! fetch uri, _SERVER["argv"][1] {
                let uri = "";
            }
            let baseUri = "";
        } else {
            if unlikely ! fetch uri, _SERVER["REQUEST_URI"] {
                throw new Exception("Cannot find request uri variable in server super globals");
            }
            let baseUri = "/";
            if fetch scriptName, _SERVER["SCRIPT_NAME"] && typeof scriptName == "string" {
                let pos = strrpos(scriptName, "/");
                if pos !== false {
                    let baseUri = substr(scriptName, 0, 1 + pos);
                }
            }
        }

        parent::__construct(uri, baseUri);
    }
}
