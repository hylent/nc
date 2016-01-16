namespace Nc\Renderer;

use Nc\Std;
use Nc\Application\ApplicationAbstract;

class Tpl extends RendererAbstract
{
    protected baseDirectory;
    protected layoutDirectory;
    protected extension;
    protected layout = "";
    protected id = "";

    public function __construct(string baseDirectory, string layoutDirectory, string extension = "phtml") -> void
    {
        let this->baseDirectory = baseDirectory;
        let this->layoutDirectory = layoutDirectory;
        let this->extension = extension;
    }

    public function setLayout(string layout) -> void
    {
        let this->layout = layout;
    }

    public function getLayout() -> string
    {
        return this->layout;
    }

    public function setId(string id) -> void
    {
        let this->id = id;
    }

    public function getId() -> string
    {
        return this->id;
    }

    public function render() -> void
    {
        var data;
        string id, path, layout;

        let data = this->data;

        let id = (string) this->id;
        if unlikely id->length() < 1 || strpos(id, "..") !== false {
            throw new Exception("Invalid id: " . id);
        }

        let path = (string) sprintf("%s/%s.%s", this->baseDirectory, id, this->extension);
        if unlikely ! file_exists(path) {
            throw new Exception("Cannot find tpl path: " . path);
        }

        let layout = (string) this->layout;
        if layout->length() > 0 {
            if unlikely strpos(layout, "..") !== false {
                throw new Exception("Invalid layout: " . layout);
            }
            let data["__tpl__"] = path;
            let path = (string) sprintf("%s/%s.%s", this->layoutDirectory, layout, this->extension);
            if unlikely ! file_exists(path) {
                throw new Exception("Cannot find layout path: " . path);
            }
        }

        echo Std::renderScript(path, data);
    }

}
