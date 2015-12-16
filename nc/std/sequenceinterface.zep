namespace Nc\Std;

interface SequenceInterface
{
    public function getNextSequence(string identifier) -> long;
    public function restoreSequence(string identifier, long sequence) -> void;

}
