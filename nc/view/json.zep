namespace Nc\View;

use Nc\Std;

class Json implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        var jsonFlag;
        string jsonCallback;
        bool jsonCors, jsonHeaderPlain;

        let jsonFlag = Std::valueAt(options, "jsonFlag", 0);
        let jsonCallback = (string) Std::valueAt(options, "jsonCallback", "");
        let jsonCors = (bool) Std::valueAt(options, "jsonCors", false);
        let jsonHeaderPlain = (bool) Std::valueAt(options, "jsonHeaderPlain", false);

        if jsonCors {
            header("Access-Control-Allow-Origin: *");
        }
        if jsonHeaderPlain {
            header("Content-type: text/plain; charset=UTF-8");
        }

        if jsonCallback->length() > 0 {
            echo sprintf("%s(%s);", jsonCallback, json_encode(data, jsonFlag));
        } else {
            echo json_encode(data, jsonFlag);
        }
    }

}
