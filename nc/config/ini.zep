namespace Nc\Config;

class Ini extends FileSystemAbstract
{
    protected fileExtension = "ini";

    protected function readFromPath(string path)
    {
        return parse_ini_file(path, true, INI_SCANNER_RAW);
    }
}
