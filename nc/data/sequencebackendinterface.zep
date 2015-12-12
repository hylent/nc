namespace Nc\Data;

interface SequenceBackendInterface
{
    public function nextSequence(string identifier, string name) -> long;
    public function restoreSequence(string identifier, array sequences) -> void;

}
