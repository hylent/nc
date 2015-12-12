namespace Nc\Data;

abstract class DataAbstract
{
    protected backend;
    protected identifier;

    public function __construct(var backend, string identifier) -> void
    {
        let this->backend = backend;
        let this->identifier = identifier;
    }

}
