namespace Nc\Router;

class SourceRequestUri extends SourceUri
{
    public function __construct() -> void
    {
        var uri;

        if unlikely ! fetch uri, _SERVER["REQUEST_URI"] {
            throw new Exception("Invalid request uri");
        }

        parent::__construct((string) uri);
    }

}
