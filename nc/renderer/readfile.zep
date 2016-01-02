namespace Nc\Renderer;

class ReadFile extends RendererAbstract
{
    protected path;
    protected mineType;
    protected fileSize;

    public function __construct(string path, string mineType = "application/octet-stream") -> void
    {
        if unlikely ! file_exists(path) {
            throw new Exception("Invalid path: " . path);
        }

        let this->path = path;
        let this->mineType = mineType;
        let this->fileSize = filesize(path);
    }

    public function getPath() -> string
    {
        return this->path;
    }

    public function getExtraHeaders() -> array
    {
        var headers = [];

        let headers[] = "Content-Type: " . this->mineType;
        let headers[] = "Content-Length: " . this->fileSize;

        return headers;
    }

    public function render() -> void
    {
        if unlikely readfile(this->path) === false {
            throw new Exception("Cannot read file: " . this->path);
        }
    }

}
