namespace Nc\Application;

class RequestCli extends RequestAbstract
{
    public function getParams() -> array
    {
        var argv;

        let argv = (array) this->getServer("argv");
        array_shift(argv);

        return argv;
    }

}
