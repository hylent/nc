namespace Nc\Router;

class SourceSapiStrategy implements SourceInterface
{
    public function getSource() -> array
    {
        if PHP_SAPI == "cli" {
            return (new SourceArgv())->getSource();
        }

        return (new SourceRequestUri())->getSource();
    }

}
