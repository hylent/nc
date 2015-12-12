namespace Nc\Data;

interface GroupedBackendInterface
{
    public function setGrouped(string identifier, string key, var value) -> void;
    public function getGrouped(string identifier, string key);
    public function deleteGrouped(string identifier, string key) -> void;
    public function setManyGrouped(string identifier, array keyValues) -> void;
    public function getManyGrouped(string identifier, array keys) -> array;
    public function deleteManyGrouped(string identifier, array keys) -> void;
    public function setAllGrouped(string identifier, array keyValues) -> void;
    public function getAllGrouped(string identifier) -> array;
    public function deleteAllGrouped(string identifier) -> void;

}
