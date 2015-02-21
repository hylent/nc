namespace Nc\Db;

interface DbInterface
{
    const READ = 1;
    const WRITE = 2;
    const SELECT = 0x10;
    const INSERT = 0x20;
    const DELETE = 0x30;
    const UPDATE = 0x40;
    const REPLACE = 0x50;
    const FETCH_MASK = 0xf00;
    const ALL = 0x100;
    const ROW = 0x200;
    const ONE = 0x300;
    const COLUMN = 0x400;

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
