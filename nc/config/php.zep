namespace Nc\Config;

class Php extends FileSystemAbstract
{
    protected fileExtension = "php";

    protected function readFromPath(string path)
    {
        return require path;
    }
}
