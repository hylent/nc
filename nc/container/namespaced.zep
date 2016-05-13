namespace Nc\Container;

class Namespaced extends Prefixed
{
    public function __construct(string ns) -> void
    {
        parent::__construct(ns . "\\");
    }

}
