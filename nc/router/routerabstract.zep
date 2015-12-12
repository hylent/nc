namespace Nc\Router;

abstract class RouterAbstract implements SourceInterface
{
    protected source;
    protected id;

    public function setSource(var source) -> void
    {
        let this->source = source;
    }

    public function getSource() -> array
    {
        var source;

        let source = this->source;

        if typeof source == "array" {
            return source;
        }

        if unlikely typeof source != "object" || ! (source instanceof SourceInterface) {
            throw new Exception("Invalid source");
        }

        let source = (array) source->getSource();
        let this->source = source;

        return source;
    }

    abstract public function route();

    public function getId() -> string
    {
        if unlikely this->id === null {
            throw new Exception("Id not ready");
        }

        return (string) this->id;
    }

}
