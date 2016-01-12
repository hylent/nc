namespace Nc\Db;

interface DbInterface
{
    const NONE      = 0;
    const ALL       = 1;
    const ROW       = 2;
    const CELL      = 3;
    const COLUMNS   = 4;

    public function getInternalHandler();
    public function getQueries() -> array;

    public function quote(string value) -> string;
    public function queryAndFetch(long $fetch, string sql, array params = []);
    public function query(string sql, array params = []);
    public function queryAll(string sql, array params = []);
    public function queryRow(string sql, array params = []);
    public function queryCell(string sql, array params = []);
    public function queryColumns(string sql, array params = []);

    public function inTransaction() -> bool;
    public function begin() -> void;
    public function commit() -> void;
    public function rollback() -> void;
    public function savepoint(string savepoint) -> void;
    public function releaseSavepoint(string savepoint) -> void;
    public function rollbackToSavepoint(string savepoint) -> void;
    public function atomic(var delegate);

    public function delete(string table, array where = []) -> void;
    public function insert(string table, array data, string returningId = "");
    public function update(string table, array data, array where = []) -> void;
    public function upsert(string table, array data, var primaryKey = "id") -> void;
    public function select(string table, array options = [], long $fetch = self::ALL);
    public function selectRow(string table, array options = []);
    public function selectCell(string table, array options = []);
    public function selectColumns(string table, array options = []);
    public function countAndSelect(string table, array options = [], long $fetch = self::ALL) -> array;
    public function selectUnionAll(array selects, array options = [], long $fetch = self::ALL);
    public function countAndSelectUnionAll(array selects, array options = [], long $fetch = self::ALL) -> array;

    public function count(string table, string column = "*", array where = []) -> long;
    public function max(string table, string column, array where = []);
    public function min(string table, string column, array where = []);
    public function sum(string table, string column, array where = []);
    public function avg(string table, string column, array where = []);
    public function aggregation(string table, string aggregationFunction, string column, array where = []);
    public function aggregations(string table, array aggregations, array where = []) -> array;
    public function groupAggregations(string table, string groupBy, array aggregations, array options = []) -> array;

}
