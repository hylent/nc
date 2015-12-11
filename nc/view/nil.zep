namespace Nc\View;

class Nil implements ViewInterface
{
    public function run(array data, array options) -> void
    {
        return;
    }

}
