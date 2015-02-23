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

    public function inTransaction() -> boolean;
    public function begin() -> void;
    public function commit() -> void;
    public function rollback() -> void;

    public function savepoint(string savepoint = "") -> string;
    public function releaseSavepoint(string savepoint) -> void;
    public function releaseLastSavepoint() -> void;
    public function rollbackToSavepoint(string savepoint) -> void;
    public function rollbackToLastSavepoint() -> void;

    public function transactionAtomic(var callback, array args = []);
    public function savepointAtomic(var callback, array args = [], string savepointIfNeeded = "");
    public function atomic(var callback, array args = []);

    public function quote(string value) -> string;
    public function query(long flag, string sql, array params = null);

    public function setQueryClass(string queryClass) -> void;
    public function getQueryClass() -> string;
    public function __invoke(string table, string tableAlias = "");
}
