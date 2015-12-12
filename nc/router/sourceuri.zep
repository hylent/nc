namespace Nc\Router;

class SourceUri implements SourceInterface
{
    protected uri;

    public function __construct(string uri) -> void
    {
        let this->uri = uri;
    }

    public function getSource() -> array
    {
        var m = null;

        if ! preg_match("#^([^\\?]+)#", (string) this->uri, m) {
            return [];
        }

        return preg_split("#/+#", (string) m[1], null, PREG_SPLIT_NO_EMPTY);
    }

}
