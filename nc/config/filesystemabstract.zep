namespace Nc\Config;

use Nc\Di\ContainerInterface;

abstract class FileSystemAbstract implements ConfigInterface, ContainerInterface
{
    const VALID_FILENAME_PATTERN = "#^[\\w]+$#";

    protected configs;

    protected baseDirectory;
    protected fileExtension = "";

    public function __construct(string baseDirectory) -> void
    {
        let this->baseDirectory = baseDirectory;
    }

    public function __isset(string name) -> boolean
    {
        return true;
    }

    public function __get(string name)
    {
        return this->get(name);
    }

    public function get(string name, var defaultValue = null)
    {
        var parts, part, value, path, tmpValue;

        let parts = explode(".", name);
        let part = array_shift(parts);

        if ! fetch value, this->configs[part] {
            if unlikely ! preg_match(self::VALID_FILENAME_PATTERN, part) {
                return defaultValue;
            }
            let path = this->baseDirectory . "/" . part . "." . this->fileExtension;
            if file_exists(path) {
                let value = this->readFromPath(path);
            } else {
                let value = null;
            }
            let this->configs[part] = value;
        }

        for part in parts {
            if typeof value != "array" || ! fetch tmpValue, value[part] {
                return defaultValue;
            }
            let value = tmpValue;
        }

        return value;
    }

    public function loadAll() -> array
    {
        var paths, path, name, value, configs = [];

        let paths = glob(this->baseDirectory . "/*." . this->fileExtension);
        if typeof paths == "array" {
            for path in paths {
                let name = (string) pathinfo(path, PATHINFO_FILENAME);
                if ! preg_match(self::VALID_FILENAME_PATTERN, name) {
                    continue;
                }
                if fetch value, this->configs[name] {
                    let configs[name] = value;
                } else {
                    let value = this->readFromPath(path);
                    let configs[name] = value;
                    let this->configs[name] = value;
                }
            }
        }

        return configs;
    }

    abstract protected function readFromPath(string path);
}
