namespace Nc\Sequence;

abstract class SequenceBackendAbstract implements SequenceBackendInterface
{
    public function getSequence(string name) -> <Sequence>
    {
        return new Sequence(this, name);
    }

}
