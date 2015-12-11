namespace Nc\View;

use Nc\Std;

class ReadFile implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        string readFile;

        let readFile = (string) Std::valueAt(options, "readFile", "");
        if unlikely readFile->length() < 1 {
            throw new Exception("Missing option: readFile");
        }

        if unlikely ! file_exists(readFile) {
            throw new Exception("Cannot find file in path: " . readFile);
        }

        header("Content-Description: File Transfer");
        header("Content-Type: application/octet-stream");
        header("Content-Transfer-Encoding: binary");
        header("Expires: 0");
        header("Cache-Control: must-revalidate");
        header("Pragma: public");

        if unlikely readfile(readFile) === false {
            throw new Exception("Cannot read file: " . readFile);
        }
    }

}
