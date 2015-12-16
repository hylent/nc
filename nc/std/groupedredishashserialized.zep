namespace Nc\Std;

class GroupedRedisHashSerialized extends GroupedRedisHash
{
    public function serializeValue(var value) -> string
    {
        return serialize(value);
    }

    public function unserializeValue(string value)
    {
        return unserialize(value);
    }

    public function setGrouped(string identifier, string key, var value) -> void
    {
        parent::setGrouped(identifier, key, this->serializeValue(value));
    }

    public function getGrouped(string identifier, string key)
    {
        var value;

        let value = parent::getGrouped(identifier, key);
        if value === null {
            return;
        }

        return this->unserializeValue(value);
    }

    public function setManyGrouped(string identifier, array keyValues) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->serializeValue(v);
        }

        parent::setManyGrouped(identifier, data);
    }

    public function getManyGrouped(string identifier, array keys) -> array
    {
        var a, k, v, data = [];

        let a = parent::getManyGrouped(identifier, keys);
        for k, v in a {
            let data[k] = this->unserializeValue(v);
        }

        return data;
    }

    public function setAllGrouped(string identifier, array keyValues) -> void
    {
        var k, v, data = [];

        for k, v in keyValues {
            let data[k] = this->serializeValue(v);
        }

        parent::setAllGrouped(identifier, data);
    }

    public function getAllGrouped(string identifier) -> array
    {
        var a, k, v, data = [];

        let a = parent::getAllGrouped(identifier);
        for k, v in a {
            let data[k] = this->unserializeValue(v);
        }

        return data;
    }

}
