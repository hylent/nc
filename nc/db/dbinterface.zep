namespace Nc\Db;

interface DbInterface
{
    const READ = 1;
    const WRITE = 2;

    const FETCH_MASK = 0xf0;
    const ALL = 0x10;
    const ROW = 0x20;
    const ONE = 0x30;
    const COLUMN = 0x40;

    public function begin() -> boolean;
    public function commit() -> boolean;
    public function rollback() -> boolean;

    public function inTransaction() -> boolean;

    public function savepoint(boolean autoTransaction = false) -> string;
    public function releaseSavepoint(string savepoint) -> boolean;
    public function releaseLastSavepoint() -> boolean;
    public function rollbackToSavepoint(string savepoint) -> boolean;
    public function rollbackToLastSavepoint() -> boolean;

    public function quote(string value) -> string;
    public function query(long flag, string sql, array params = null);

    public function setQueryClass(string queryClass) -> void;
    public function getQueryClass() -> string;
    public function __invoke(string table, string tableAlias = "");
}
