namespace Nc\Db;

abstract class PdoAbstract extends DbAbstract
{
    protected pdo;
    protected lastStatement;

    public function __construct() -> void
    {
        if unlikely ! extension_loaded("pdo") {
            throw new Exception("Missing extension: 'pdo'");
        }

        let this->pdo = (new \ReflectionClass("Pdo"))->newInstanceArgs(func_get_args());
    }

    public function getInternalHandler()
    {
        return this->pdo;
    }

    public function quote(string value) -> string
    {
        return this->pdo->quote(value);
    }

    public function execute(string sql, array params = []) -> void
    {
        var t, q, statement, k, v, err;
        boolean success;

        let t = microtime(true);
        let statement = this->pdo->prepare(sql);

        if count(params) > 0 {
            for k, v in params {
                if typeof v == "string" {
                    statement->bindParam(":" . k, "" . v, \Pdo::PARAM_STR, strlen(v));
                } else {
                    statement->bindValue(":" . k, v);
                }
            }
        }

        let success = (boolean) statement->execute();
        let q = this->addQuery(sql, params, t);

        if unlikely ! success {
            let err = statement->errorInfo();
            throw new ExecutionException(err[2] . " [SQL] " . q);
        }

        let this->lastStatement = statement;
    }

    public function query(string sql, array params = []) -> array
    {
        this->execute(sql, params);

        return this->lastStatement->fetchAll(\Pdo::FETCH_ASSOC);
    }

    public function queryRow(string sql, array params = [])
    {
        var resultRow;

        this->execute(sql, params);

        let resultRow = this->lastStatement->$fetch(\Pdo::FETCH_ASSOC);
        if resultRow {
            return resultRow;
        }
    }

    public function queryCell(string sql, array params = []) -> string
    {
        this->execute(sql, params);

        return (string) this->lastStatement->fetchColumn();
    }

    public function queryColumns(string sql, array params = []) -> array
    {
        var statement, resultCell, result = [];

        this->execute(sql, params);
        let statement = this->lastStatement;

        loop {
            let resultCell = statement->fetchColumn();
            if resultCell === false || typeof resultCell != "string" {
                break;
            }
            let result[] = resultCell;
        }

        return result;
    }

    protected function tryToBegin() -> boolean
    {
        return this->pdo->beginTransaction();
    }

    protected function tryToCommit() -> boolean
    {
        return this->pdo->commit();
    }

    protected function tryToRollback() -> boolean
    {
        return this->pdo->rollback();
    }

}
