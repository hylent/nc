namespace Nc\View;

use Nc\Std;

class Content implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        string content, contentType;

        let content = (string) Std::valueAt(options, "content", "");
        let contentType = (string) Std::valueAt(options, "contentType", "");

        if contentType->length() > 0 {
            header("Content-Type: " . contentType);
        }

        echo content;
    }

}
