namespace Nc\Storage;

interface UriGeneratorInterface
{
    public function generateUri(string src, string pre, string ext) -> string;

}
