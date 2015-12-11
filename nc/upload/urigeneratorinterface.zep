namespace Nc\Upload;

interface UriGeneratorInterface
{
    public function generateUri(string source, string prefix, string extension) -> string;

}
