namespace Nc\View;

use Nc\Std;

class Tpl implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        string tplBaseDirectory, tplLayoutDirectory, tplId, tplExtension, tplLayout, path;

        let tplBaseDirectory = (string) Std::valueAt(options, "tplBaseDirectory", "");
        if unlikely tplBaseDirectory->length() < 1 {
            throw new Exception("Missing option: tplBaseDirectory");
        }

        let tplLayoutDirectory = (string) Std::valueAt(options, "tplLayoutDirectory", tplBaseDirectory . "/layout");
        if unlikely tplLayoutDirectory->length() < 1 {
            throw new Exception("Invalid option: tplLayoutDirectory");
        }

        let tplId = (string) Std::valueAt(options, "tplId", "");
        if unlikely tplId->length() < 1 || strpos(tplId, "..") !== false {
            throw new Exception("Invalid option: tplId");
        }

        let tplExtension = (string) Std::valueAt(options, "tplExtension", "phtml");
        let tplLayout = (string) Std::valueAt(options, "tplLayout", "");

        let path = (string) sprintf("%s/%s.%s", tplBaseDirectory, tplId, tplExtension);
        if unlikely ! file_exists(path) {
            throw new Exception("Cannot find tpl path: " . path);
        }

        if tplLayout->length() > 0 {
            if unlikely strpos(tplLayout, "..") !== false {
                throw new Exception("Invalid option: tplLayout");
            }
            let data["__tpl_path"] = path;
            let path = (string) sprintf("%s/%s.%s", tplLayoutDirectory, tplLayout, tplExtension);
            if unlikely ! file_exists(path) {
                throw new Exception("Cannot find layout path: " . path);
            }
        }

        echo Std::renderScript(path, data);
    }

}
