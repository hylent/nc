namespace Nc\Storage;

class UriGeneratorCallback implements UriGeneratorInterface
{
    protected callback;

    public function __construct(var callback) -> void
    {
        let this->callback = callback;
    }

    public function generateUri(string src, string pre, string ext) -> string
    {
        return (string) call_user_func(this->callback, src, pre, ext);
    }

}
