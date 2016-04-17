namespace Nc\Sequence;

interface SequenceBackendInterface
{
    public function getSequence(string name) -> <Sequence>;

    public function next(string name) -> long;
    public function restore(string name, long sequence) -> void;

    public function clear() -> void;

}
