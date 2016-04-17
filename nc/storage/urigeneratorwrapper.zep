namespace Nc\Storage;

class UriGeneratorWrapper implements UriGeneratorInterface
{
    protected wrapped;

    public function __construct(var wrapped) -> void
    {
        let this->wrapped = wrapped;
    }

    public function generateUri(string src, string pre, string ext) -> string
    {
        return (string) call_user_func(this->wrapped, src, pre, ext);
    }

}
