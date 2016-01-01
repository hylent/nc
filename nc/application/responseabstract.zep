namespace Nc\Application;

abstract class ResponseAbstract
{
    protected content = "";

    public function __invoke() -> void
    {
        echo this->content;
    }

}
