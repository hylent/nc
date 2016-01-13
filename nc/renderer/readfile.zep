namespace Nc\Renderer;

class ReadFile extends RendererAbstract
{
    protected path;

    public function __construct(string path, string mimeType = "") -> void
    {
        var finfoMimeType;

        if unlikely ! file_exists(path) {
            throw new Exception("Invalid path: " . path);
        }

        let this->path = path;

        if mimeType->length() < 1 {
            let finfoMimeType = finfo_file(finfo_open(FILEINFO_MIME_TYPE), path);
            if finfoMimeType === false {
                let mimeType = "application/octet-stream";
            } else {
                let mimeType = (string) finfoMimeType;
            }
        }

        let this->extraHeaders["content-type"] = "Content-Type: " . mimeType;
        let this->extraHeaders["content-length"] = "Content-Length: " . filesize(path);
    }

    public function getPath() -> string
    {
        return this->path;
    }

    public function render() -> void
    {
        if unlikely readfile(this->path) === false {
            throw new Exception("Cannot read file: " . this->path);
        }
    }

}
