namespace Nc\Factory;

abstract class ClassNameAbstract extends FactoryAbstract
{
    protected args;

    public static function newInstanceOf(string className, array args = null)
    {
        long c;
        var a;

        let c = count(args);
        if c < 1 {
            return new {className}();
        }
        if c > 5 {
            return (new \ReflectionClass(className))->newInstanceArgs(args);
        }

        let a = array_values(args);
        switch c {
            case 1:
                return new {className}(a[0]);
            case 2:
                return new {className}(a[0], a[1]);
            case 3:
                return new {className}(a[0], a[1], a[2]);
            case 4:
                return new {className}(a[0], a[1], a[2], a[3]);
            case 5:
                return new {className}(a[0], a[1], a[2], a[3], a[4]);
        }

        throw new Exception("Fail to fetch a new instance of class: " . className);
    }

    abstract public function getClassName(string name) -> string;

    public function __isset(string name) -> boolean
    {
        return parent::__isset(name) || class_exists(this->getClassName(name));
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

    protected function createInternally(string name)
    {
        string className;

        let className = (string) this->getClassName(name);
        if unlikely ! class_exists(className) {
            throw new Exception("Invalid production: " . name);
        }

        return self::newInstanceOf(className, this->args);
    }

}
