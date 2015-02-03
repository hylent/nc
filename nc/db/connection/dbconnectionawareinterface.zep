namespace Nc\Db\Connection;

interface DbConnectionAwareInterface
{
    public function setDbConnection(<DbConnectionInterface> dbConnection) -> void;
    public function getDbConnection() -> <DbConnectionInterface>;
}
