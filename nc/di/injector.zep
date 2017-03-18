namespace Nc\Di;

class Injector implements ContainerInterface, \ArrayAccess
{
    const ANNOTATION_PATTERN = "/^[ \\t]*\\*[ \\t]*@@[ \\t]*(\\S*)[ \\t]*(\\S*)[ \\t]*$/m";

    protected objects;
    protected delegates;
    protected nameLocks;

    public function __isset(string name) -> boolean
    {
        var pos, containerName, container, subName;

        if isset this->objects[name] {
            return true;
        }

        if isset this->delegates[name] {
            return true;
        }

        let pos = strrpos(name, ".");
        if pos !== false {
            let containerName = substr(name, 0, pos);
            if this->__isset(containerName) {
                let container = this->__get(containerName);
                if typeof container == "object" && (container instanceof ContainerInterface) {
                    let subName = substr(name, pos + 1);
                    if container->__isset(subName) {
                        return true;
                    }
                }
            }
        }

        return false;
    }

    public function __get(string name)
    {
        var obj, delegate, pos, containerName, container, subName;

        if fetch obj, this->objects[name] {
            return obj;
        }

        if unlikely isset this->nameLocks[name] {
            throw new Exception(sprintf("Initializing %s", name));
        }

        let this->nameLocks[name] = true;

        loop {
            if fetch delegate, this->delegates[name] {
                let obj = call_user_func(delegate, this, name);
                if typeof obj == "object" && (obj instanceof InjectedSetupMethodInterface) {
                    obj->setupByInjector(this);
                }
                break;
            }

            let pos = strrpos(name, ".");
            if pos !== false {
                let containerName = substr(name, 0, pos);
                let container = this->__get(containerName);
                if typeof container == "object" && (container instanceof ContainerInterface) {
                    let subName = substr(name, pos + 1);
                    let obj = container->__get(subName);
                    break;
                }
            }

            throw new Exception(sprintf("CannotResolveDependency %s", name));
        }

        unset this->nameLocks[name];
        let this->objects[name] = obj;

        return obj;
    }

    public function __set(string name, var obj) -> void
    {
        if typeof obj == "object" && (obj instanceof InjectedSetupMethodInterface) {
            obj->setupByInjector(this);
        }

        let this->objects[name] = obj;
    }

    public function __unset(string name) -> void
    {
        unset this->objects[name];
    }

    public function __invoke(string className, string type = "")
    {
        var refClass, obj, refProperty, resolvedValue, refCtor, params;

        if unlikely strlen(className) < 1 || ! class_exists(className) {
            throw new Exception(sprintf("InvalidClass %s", className));
        }

        let refClass = new \ReflectionClass(className);
        if unlikely ! refClass->isInstantiable() {
            throw new Exception(sprintf("NotInstantiable %s", className));
        }

        if strlen(type) > 0 {
            if unlikely ! class_exists(type) && ! interface_exists(type) {
                throw new Exception(sprintf("InvalidType %s", type));
            }
            if unlikely ! refClass->isSubclassOf(type) && strcasecmp(className, type) != 0 {
                throw new Exception(sprintf("InvalidClassType: %s provided, %s required", className, type));
            }
        }

        let obj = refClass->newInstanceWithoutConstructor();

        if obj instanceof InjectedPropertyInterface {
            for refProperty in refClass->getProperties() {
                if refProperty->isStatic() {
                    continue;
                }
                if ! refProperty->isPublic() {
                    refProperty->setAccessible(true);
                }
                if refProperty->getValue(obj) === null {
                    let resolvedValue = this->resolveFirst(refProperty->getDocComment());
                    if resolvedValue !== null {
                        refProperty->setValue(obj, resolvedValue);
                    }
                }
            }
        }

        if refClass->hasMethod("__construct") {
            let refCtor = refClass->getMethod("__construct");
            if obj instanceof InjectedCtorParamsInterface {
                let params = this->resolveAll(refCtor->getDocComment());
            } else {
                let params = [];
            }
            if unlikely count(params) < refCtor->getNumberOfRequiredParameters() {
                throw new Exception("MissingRequiredParam");
            }
            refCtor->invokeArgs(obj, params);
        }

        if obj instanceof InjectedSetupMethodInterface {
            obj->setupByInjector(this);
        }

        return obj;
    }

    public function offsetSet(string name, var delegate) -> void
    {
        let this->delegates[name] = delegate;
    }

    public function offsetGet(string name)
    {
        var delegate;

        if fetch delegate, this->delegates[name] {
            return delegate;
        }
    }

    public function offsetExists(string name) -> boolean
    {
        return isset this->delegates[name];
    }

    public function offsetUnset(string name) -> void
    {
        unset this->delegates[name];
    }

    public function setClassMapper(string name, array classMapper) -> void
    {
        this->__set(name, new CreatorClassMapper(classMapper));
    }

    public function setClassPrefix(string name, string prefix) -> void
    {
        this->__set(name, new CreatorClassPrefix(prefix));
    }

    public function setClassNamespace(string name, string ns) -> void
    {
        this->__set(name, new CreatorClassNamespace(ns));
    }

    protected function resolveFirst(string annotation)
    {
        var m = null, m1, m2, obj;

        if ! preg_match(self::ANNOTATION_PATTERN, annotation, m) {
            return;
        }

        let m1 = (string) m[1];
        let m2 = (string) m[2];

        if m1 === "" {
            return;
        }

        let obj = this->__get(m1);
        if m2 === "" {
            return obj;
        }

        if typeof obj != "object" || ! (obj instanceof ContainerInterface) {
            throw new Exception("InvalidContainer");
        }

        if ! obj->__isset(m2) {
            return;
        }

        return obj->__get(m2);
    }

    protected function resolveAll(string annotation)
    {
        var r = [], mVec = null, m, m1, m2, obj;

        if preg_match_all(self::ANNOTATION_PATTERN, annotation, mVec, PREG_SET_ORDER) {
            for m in mVec {
                let m1 = (string) m[1];
                let m2 = (string) m[2];

                if m1 === "" {
                    let r[] = null;
                    continue;
                }

                let obj = this->__get(m1);
                if m2 === "" {
                    let r[] = obj;
                    continue;
                }

                if typeof obj != "object" || ! (obj instanceof ContainerInterface) {
                    throw new Exception("InvalidContainer");
                }

                if ! obj->__isset(m2) {
                    let r[] = null;
                    continue;
                }

                let r[] = obj->__get(m2);
            }
        }

        return r;
    }
}
