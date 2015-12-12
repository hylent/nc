namespace Nc\Data;

class Grouped extends DataAbstract
{
    public function set(string key, var value) -> void
    {
        this->backend->setGrouped(this->identifier, key, value);
    }

    public function get(string key)
    {
        return this->backend->getGrouped(this->identifier, key);
    }

    public function delete(string key) -> void
    {
        this->backend->deleteGrouped(this->identifier, key);
    }

    public function setMany(array keyValues) -> void
    {
        this->backend->setManyGrouped(this->identifier, keyValues);
    }

    public function getMany(array keys) -> array
    {
        return this->backend->getManyGrouped(this->identifier, keys);
    }

    public function deleteMany(array keys) -> void
    {
        this->backend->deleteManyGrouped(this->identifier, keys);
    }

    public function setAll(array keyValues) -> void
    {
        this->backend->setAllGrouped(this->identifier, keyValues);
    }

    public function getAll() -> array
    {
        return this->backend->getAllGrouped(this->identifier);
    }

    public function deleteAll() -> void
    {
        this->backend->deleteAllGrouped(this->identifier);
    }

}
