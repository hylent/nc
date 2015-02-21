namespace Nc\Db;

interface DbAwareInterface
{
    public function setDb(<DbInterface> db) -> void;
    public function getDb() -> <DbInterface>;
}
