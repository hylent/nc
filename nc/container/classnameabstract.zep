namespace Nc\Container;

abstract class ClassNameAbstract extends CreatorAbstract
{
    protected args;
    protected lazyArgs;

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

        throw new Exception(sprintf(
            "Fail to fetch a new instance of class '%s'",
            className
        ));
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

    public function setArrayArgs(array args) -> void
    {
        let this->args = array_values(args);
    }

    public function getArgs() -> array
    {
        if count(this->args) > 0 {
            return this->args;
        }

        return [];
    }

    public function setLazyArg(long index, <\Closure> lazyArg) -> void
    {
        let this->lazyArgs[index] = lazyArg;
    }

    public function getLazyArgs() -> array
    {
        if count(this->lazyArgs) > 0 {
            return this->lazyArgs;
        }

        return [];
    }

    protected function create(string name)
    {
        string className;

        let className = (string) this->getClassName(name);
        if unlikely ! class_exists(className) {
            throw new Exception(sprintf(
                "Cannot create object '%s', missing class '%s'",
                name,
                className
            ));
        }

        this->processLazyArgs();

        return self::newInstanceOf(className, this->args);
    }

    protected function processLazyArgs() -> void
    {
        var index, lazyArg;

        if count(this->lazyArgs) > 0 {
            for index, lazyArg in this->lazyArgs {
                if isset this->args[index] && typeof lazyArg == "object" && (lazyArg instanceof \Closure) {
                    let this->args[index] = call_user_func(lazyArg, this, index);
                }
            }

            let this->lazyArgs = null;
        }
    }

}
