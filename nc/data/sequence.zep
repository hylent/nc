namespace Nc\Data;

class Sequence extends DataAbstract
{
    public function next(string name) -> long
    {
        return this->backend->nextSequence(this->identifier, name);
    }

    public function restore(array sequences) -> void
    {
        this->backend->restoreSequence(this->identifier, sequences);
    }

}
