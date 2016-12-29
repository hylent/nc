namespace Nc\Db;

interface DbInterface
{
    public function inTransaction() -> boolean;
    public function begin() -> void;
    public function commit() -> void;
    public function rollback() -> void;

    public function savepoint(string savepoint) -> void;
    public function releaseSavepoint(string savepoint) -> void;
    public function rollbackToSavepoint(string savepoint) -> void;

    public function quote(string value) -> string;
    public function expression(array input) -> string;

    public function execute(string sql, array params = []) -> long;
    public function query(string sql, array params = []) -> array;

    public function queryRow(string sql, array params = []);
    public function queryCell(string sql, array params = []) -> string;
    public function queryVector(string sql, array params = []) -> array;
    public function queryMap(string sql, array params = []) -> array;

    public function getSqls() -> array;
}
