namespace Nc\Db;

abstract class PdoAbstract extends DbAbstract
{
    protected pdo;

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

    public function execute(string sql, array params = [], long $fetch = DbInterface::NONE)
    {
        var t, q, statement, k, v, err;
        boolean success;
        var resultItem, result;

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

        switch $fetch {
            case DbInterface::NONE:
                return;

            case DbInterface::ALL:
                return statement->fetchAll(\Pdo::FETCH_ASSOC);

            case DbInterface::ROW:
                let resultItem = statement->$fetch(\Pdo::FETCH_ASSOC);
                if resultItem {
                    return resultItem;
                }
                return;

            case DbInterface::CELL:
                return (string) statement->fetchColumn();

            case DbInterface::COLUMNS:
                let result = [];
                loop {
                    let resultItem = statement->fetchColumn();
                    if resultItem === false || typeof resultItem != "string" {
                        break;
                    }
                    let result[] = resultItem;
                }
                return result;
        }

        throw new Exception(sprintf("Invalid fetch mode '%s'", $fetch));
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
