namespace Nc\Application;

abstract class ResponseAbstract
{
    protected content;

    public function addContent(var content) -> void
    {
        let this->content .= content;
    }

    public function setContent(var content) -> void
    {
        let this->content = content;
    }

    public function getContent()
    {
        return this->content;
    }

    public function __invoke() -> void
    {
        echo this->content;
    }

}
