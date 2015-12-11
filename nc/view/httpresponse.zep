namespace Nc\View;

use Nc\Std;

class HttpResponse implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        long httpResponseCode;
        string httpResponseContent;

        let httpResponseCode = (long) Std::valueAt(options, "httpResponseCode", 200);
        http_response_code(httpResponseCode);

        let httpResponseContent = (string) Std::valueAt(options, "httpResponseContent", "");
        echo httpResponseContent;
    }

}
