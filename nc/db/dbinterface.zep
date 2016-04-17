namespace Nc\Db;

interface DbInterface
{
    const NONE      = 0;
    const ALL       = 1;
    const ROW       = 2;
    const CELL      = 3;
    const COLUMNS   = 4;

    public function getInternalHandler();

    public function inTransaction() -> boolean;
    public function begin() -> void;
    public function commit() -> void;
    public function rollback() -> void;

    public function savepoint(string savepoint) -> void;
    public function releaseSavepoint(string savepoint) -> void;
    public function rollbackToSavepoint(string savepoint) -> void;

    public function atomic(var cb, string savepoint = "sp0");

    public function quote(string value) -> string;
    public function execute(string sql, array params = [], long $fetch = DbInterface::NONE);

    public function query(string sql, array params = []) -> array;
    public function queryRow(string sql, array params = []);
    public function queryCell(string sql, array params = []) -> string;
    public function queryColumns(string sql, array params = []) -> array;

    public function getQueries() -> array;

    public function delete(string t, array where = []) -> void;
    public function insert(string t, array data, string returningId = "");
    public function update(string t, array data, array where = []) -> void;
    public function upsert(string t, array data, var primaryKey = "id") -> void;

    public function select(string t, array where = [], array options = []);
    public function selectRow(string t, array where = [], array options = []);
    public function selectCell(string t, array where = [], array options = []);
    public function selectColumns(string t, array where = [], array options = []);
    public function countAndSelect(string t, array where = [], array options = []) -> array;

    public function first(string t, array where = [], var orderBy = null, boolean forUpdate = false);
    public function find(string t, array where = [], var orderBy = null, long limit = 0, long skip = 0) -> array;
    public function paged(string t, array where = [], var orderBy = null, long limit = 10, long page = 1) -> array;
    public function chunk(string t, var cb, array where = [], var orderBy = null, long limit = 5000) -> long;
    public function chunkDynamicly(string t, var cb, array where = [], var orderBy = null, long limit = 5000) -> long;

    public function group(string t, string groupBy, array aggrs, array where = [], array options = []) -> array;
    public function aggregations(string t, array aggrs, array where = []) -> array;
    public function aggregation(string t, string aggrFunction, string column, array where = []) -> string;
    public function countAll(string t, array where = []) -> long;
    public function count(string t, string column, array where = []) -> long;
    public function max(string t, string column, array where = []);
    public function min(string t, string column, array where = []);
    public function sum(string t, string column, array where = []);
    public function avg(string t, string column, array where = []);

}
