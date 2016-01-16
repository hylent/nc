namespace Nc\Renderer;

use Nc\Application\ApplicationAbstract;

class ReadFile implements RendererInterface
{
    protected path;
    protected mimeType;

    public function __construct(string path, string mimeType = "") -> void
    {
        var finfoMimeType;

        if unlikely ! file_exists(path) {
            throw new Exception("Invalid path: " . path);
        }

        let this->path = path;

        if mimeType->length() > 0 {
            let this->mimeType = mimeType;
        } else {
            let finfoMimeType = finfo_file(finfo_open(FILEINFO_MIME_TYPE), path);
            if finfoMimeType === false {
                let this->mimeType = "application/octet-stream";
            } else {
                let this->mimeType = finfoMimeType;
            }
        }
    }

    public function getPath() -> string
    {
        return this->path;
    }

    public function getMimeType() -> string
    {
        return this->mimeType;
    }

    public function withApplication(<ApplicationAbstract> application) -> void
    {
        var headers = [];

        let headers["Content-Type"] = this->mimeType;
        let headers["Content-Length"] = filesize(this->path);

        application->setResponseHeaders(headers);
    }

    public function render() -> void
    {
        if unlikely readfile(this->path) === false {
            throw new Exception("Cannot read file: " . this->path);
        }
    }

}
