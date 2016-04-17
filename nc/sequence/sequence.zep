namespace Nc\Sequence;

class Sequence
{
    protected backend;
    protected name;

    public function __construct(<SequenceBackendInterface> backend, string name) -> void
    {
        let this->backend = backend;
        let this->name = name;
    }

    public function getBackend() -> <SequenceBackendInterface>
    {
        return this->backend;
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function next() -> long
    {
        return this->backend->next(this->name);
    }

    public function restore(long sequence) -> void
    {
        this->backend->restore(this->name, sequence);
    }

}
