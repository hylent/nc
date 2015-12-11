namespace Nc\Factory;

use Nc\Std;

abstract class ClassNameAbstract implements FactoryInterface
{
    protected args;

    public function __isset(string name) -> bool
    {
        return class_exists(this->getClassName(name));
    }

    public function __get(string name)
    {
        string className;

        let className = (string) this->getClassName(name);
        if unlikely ! class_exists(className) {
            throw new Exception("Invalid product: " . name);
        }

        return Std::newInstanceOf(className, this->args);
    }

    public function setArgs() -> void
    {
        let this->args = func_get_args();
    }

    public function setArgArray(array args) -> void
    {
        let this->args = array_values(args);
    }

    public function getArgArray() -> array
    {
        if count(this->args) > 0 {
            return this->args;
        }

        return [];
    }

    abstract protected function getClassName(string name) -> string;

}
