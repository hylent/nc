namespace Nc\View;

use Nc\Std;

class ReadFile implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        string readFile, readFileContentType;

        let readFile = (string) Std::valueAt(options, "readFile", "");
        if unlikely readFile->length() < 1 {
            throw new Exception("Missing option: readFile");
        }

        if unlikely ! file_exists(readFile) {
            throw new Exception("Cannot find file in path: " . readFile);
        }

        let readFileContentType = (string) Std::valueAt(options, "readFileContentType", "");
        if readFileContentType->length() > 0 {
            header("Content-Type: " . readFileContentType);
        } else {
            header("Content-Description: File Transfer");
            header("Content-Type: application/octet-stream");
            header("Content-Transfer-Encoding: binary");
        }

        if unlikely readfile(readFile) === false {
            throw new Exception("Cannot read file: " . readFile);
        }
    }

}
