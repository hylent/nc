namespace Nc\Router;

class SourceArgv implements SourceInterface
{
    public function getSource() -> array
    {
        var argv;

        if unlikely ! fetch argv, _SERVER["argv"] || typeof argv != "array" {
            throw new Exception("Invalid argv");
        }

        array_shift(argv);

        return argv;
    }

}
