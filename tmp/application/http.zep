namespace Nc\Application;

class Http extends ApplicationAbstract
{
    public function __construct() -> void

        var uri, pos;

        if fetch uri, _SERVER["REQUEST_URI"] {
            let pos = strpos(uri, "?");
            if pos !== false {
                let uri = (string) substr(uri, 0, pos);
            }

            let this->args = preg_split("#/+#", uri, null, PREG_SPLIT_NO_EMPTY);
        }
    }

}
