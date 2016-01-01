namespace Nc\Application;

class ResponseHttp extends ResponseAbstract
{
    protected status;
    protected headers;

    public function __invoke() -> void
    {
        parent::__invoke();
    }

}
