namespace Nc\Std;

class GroupedProxy implements GroupedInterface
{
    const NON_EXISTENT_VALUE = false;

    protected frontend;
    protected backend;

    public function __construct(<GroupedInterface> frontend, <GroupedInterface> backend) -> void
    {
        let this->frontend = frontend;
        let this->backend = backend;
    }

    public function setGrouped(string identifier, string key, var value) -> void
    {
        this->backend->setGrouped(identifier, key, value);
        this->frontend->deleteGrouped(identifier, key);
    }

    public function getGrouped(string identifier, string key)
    {
        var value;

        let value = this->frontend->getGrouped(identifier, key);
        if value !== null {
            if value !== self::NON_EXISTENT_VALUE {
                return value;
            }
            return;
        }

        let value = this->backend->getGrouped(identifier, key);
        if value !== null {
            // Backends storing value of self::NON_EXISTENT_VALUE will NOT be proxied!
            if value !== self::NON_EXISTENT_VALUE {
                this->frontend->setGrouped(identifier, key, value);
            }
            return value;
        }

        this->frontend->setGrouped(identifier, key, self::NON_EXISTENT_VALUE);
    }

    public function deleteGrouped(string identifier, string key) -> void
    {
        this->backend->deleteGrouped(identifier, key);
        this->frontend->setGrouped(identifier, key, self::NON_EXISTENT_VALUE);
    }

    public function setManyGrouped(string identifier, array keyValues) -> void
    {
        this->backend->setManyGrouped(identifier, keyValues);
        this->frontend->deleteManyGrouped(identifier, array_keys(keyValues));
    }

    public function getManyGrouped(string identifier, array keys) -> array
    {
        var k, v, a, r = [], x = [];

        let a = this->frontend->getManyGrouped(identifier, keys);
        for k in keys {
            if fetch v, a[k] {
                if v !== self::NON_EXISTENT_VALUE {
                    let r[k] = v;
                }
            } else {
                let x[] = k;
                let r[k] = null;
            }
        }

        if count(x) > 0 {
            let a = this->backend->getManyGrouped(identifier, x);
            for k in x {
                if fetch v, a[k] {
                    let r[k] = v;
                    // Backends storing value of self::NON_EXISTENT_VALUE will NOT be proxied!
                    if v !== self::NON_EXISTENT_VALUE {
                        this->frontend->setGrouped(identifier, k, v);
                    }
                } else {
                    unset r[k];
                    this->frontend->setGrouped(identifier, k, self::NON_EXISTENT_VALUE);
                }
            }
        }

        return r;
    }

    public function deleteManyGrouped(string identifier, array keys) -> void
    {
        var k;

        this->backend->deleteMany(keys);

        for k in keys {
            this->frontend->setGrouped(identifier, k, self::NON_EXISTENT_VALUE);
        }
    }

    public function setAllGrouped(string identifier, array keyValues) -> void
    {
        this->backend->setAllGrouped(identifier, keyValues);
        this->frontend->deleteAllGrouped(identifier);
    }

    public function getAllGrouped(string identifier) -> array
    {
        return this->backend->getAllGrouped(identifier);
    }

    public function deleteAllGrouped(string identifier) -> void
    {
        this->backend->deleteAllGrouped(identifier);
        this->frontend->deleteAllGrouped(identifier);
    }

}
