namespace Nc\View;

use Nc\Std;

class Redirect implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        string redirectUrl;
        bool redirectDataAsQueries;

        let redirectUrl = (string) Std::valueAt(options, "redirectUrl", "");
        if unlikely redirectUrl->length() < 1 {
            throw new Exception("Missing option: redirectUrl");
        }

        let redirectDataAsQueries = (bool) Std::valueAt(options, "redirectDataAsQueries", false);

        if redirectDataAsQueries && count(data) > 0 {
            if strpos(redirectUrl, "?") === false {
                let redirectUrl .= "?";
            } else {
                let redirectUrl .= "&";
            }
            let redirectUrl .= http_build_query(data);
        }

        header("Location: " . redirectUrl);
    }

}
