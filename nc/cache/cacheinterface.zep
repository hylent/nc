namespace Nc\Cache;

interface CacheInterface
{
    const NONE = "";
    const INTEGER_PREFIX = ":i:";
    const GROUP_PREFIX = ":g:";
    const GROUP_SEPARATOR = ":";

    public function flush() -> void;

    public function rawSet(string key, var value, long lifetime = 0) -> void;
    public function rawGet(string key);
    public function rawDelete(string key) -> void;

    public function setInteger(string key, long value) -> void;
    public function getInteger(string key) -> long;
    public function deleteInteger(string key) -> void;
    public function incrementInteger(string key, long step = 1) -> long;
    public function decrementInteger(string key, long step = 1) -> long;

    public function set(string key, var value, long lifetime = 0) -> void;
    public function get(string key);
    public function delete(string key) -> void;

    public function multiSet(array keyValues, long lifetime = 0) -> void;
    public function multiGet(array keys) -> array;
    public function multiDelete(array keys) -> void;

    public function groupSetAll(string group, array keyValues) -> void;
    public function groupGetAll(string group) -> array;
    public function groupDeleteAll(string group) -> void;

    public function groupSet(string group, array keyValues) -> void;
    public function groupGet(string group, array keys) -> array;
    public function groupDelete(string group, array keys) -> void;
}
