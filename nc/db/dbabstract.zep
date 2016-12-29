namespace Nc\Db;

abstract class DbAbstract implements DbInterface
{
    protected inTransaction = false;
    protected sqls;

    public function inTransaction() -> boolean
    {
        return this->inTransaction;
    }

    public function begin() -> void
    {
        if unlikely !! this->inTransaction || ! this->tryToBegin() {
            throw new Exception(__FUNCTION__, Exception::TRANSACTION_FAILURE);
        }

        let this->inTransaction = true;
    }

    public function commit() -> void
    {
        if unlikely ! this->inTransaction || ! this->tryToCommit() {
            throw new Exception(__FUNCTION__, Exception::TRANSACTION_FAILURE);
        }

        let this->inTransaction = false;
    }

    public function rollback() -> void
    {
        if unlikely ! this->inTransaction || ! this->tryToRollback() {
            throw new Exception(__FUNCTION__, Exception::TRANSACTION_FAILURE);
        }

        let this->inTransaction = false;
    }

    public function savepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new Exception(__FUNCTION__, Exception::TRANSACTION_FAILURE);
        }

        this->execute("SAVEPOINT " . savepoint);
    }

    public function releaseSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new Exception(__FUNCTION__, Exception::TRANSACTION_FAILURE);
        }

        this->execute("RELEASE SAVEPOINT " . savepoint);
    }

    public function rollbackToSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new Exception(__FUNCTION__, Exception::TRANSACTION_FAILURE);
        }

        this->execute("ROLLBACK TO SAVEPOINT " . savepoint);
    }

    public function expression(array input) -> string
    {
        return vsprintf(
            str_replace(["%", "?"], ["%%", "%s"], (string) array_shift(input)),
            array_map([this, "quote"], input)
        );
    }

    public function execute(string sql, array params = []) -> long
    {
        return this->executeQuery(sql, params, true);
    }

    public function query(string sql, array params = []) -> array
    {
        return this->executeQuery(sql, params, false);
    }

    public function queryRow(string sql, array params = [])
    {
        var data, row;

        let data = this->query(sql, params);

        if fetch row, data[0] && typeof row == "array" {
            return row;
        }
    }

    public function queryCell(string sql, array params = []) -> string
    {
        var data, row;

        let data = this->query(sql, params);

        if fetch row, data[0] && typeof row == "array" {
            return (string) array_shift(row);
        }

        return "";
    }

    public function queryVector(string sql, array params = []) -> array
    {
        var data, row, result = [];

        let data = this->query(sql, params);

        for row in data {
            if typeof row == "array" {
                let result[] = (string) array_shift(row);
            }
        }

        return result;
    }

    public function queryMap(string sql, array params = []) -> array
    {
        var data, row, k, v, result = [];

        let data = this->query(sql, params);

        for row in data {
            if typeof row == "array" {
                let k = (string) array_shift(row);
                let v = (string) array_shift(row);
                let result[k] = v;
            }
        }

        return result;
    }

    public function getSqls() -> array
    {
        if count(this->sqls) > 0 {
            return this->sqls;
        }

        return [];
    }

    abstract protected function tryToBegin() -> boolean;
    abstract protected function tryToCommit() -> boolean;
    abstract protected function tryToRollback() -> boolean;

    abstract protected function executeQuery(string sql, array params, boolean executionOnly = false);

    protected function addSql(string sql, array params, double startTime) -> string
    {
        var s;

        let s = sprintf("%s # %0.3fms", sql, 1000.0 * ((double) microtime(true) - startTime));
        if count(params) > 0 {
            let s .= " " . json_encode(params, JSON_UNESCAPED_UNICODE);
        }

        let this->sqls[] = s;

        return s;
    }
}
