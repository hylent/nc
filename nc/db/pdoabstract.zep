namespace Nc\Db;

abstract class PdoAbstract extends DbAbstract
{
    protected pdo;

    public function __construct() -> void
    {
        if unlikely ! extension_loaded("pdo") {
            throw new Exception("Missing extension: pdo");
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

    public function query(string sql, array params = [], long mode = DbAbstract::NONE)
    {
        var statement, k, v, err;
        double startMt;
        string profiledQuery;
        bool success;
        var resultItem, result;

        let startMt = (double) microtime(true);
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

        let success = (bool) statement->execute();

        let profiledQuery = (string) DbAbstract::profiledQuery(sql, params, startMt);
        let this->queries[] = profiledQuery;

        if unlikely ! success {
            let err = statement->errorInfo();
            throw new QueryException(err[2] . " [SQL] " . profiledQuery);
        }

        switch mode {
            case DbAbstract::NONE:
                return;

            case DbAbstract::ALL:
                return statement->fetchAll(\Pdo::FETCH_ASSOC);

            case DbAbstract::ROW:
                let resultItem = statement->$fetch(\Pdo::FETCH_ASSOC);
                if resultItem {
                    return resultItem;
                }
                return null;

            case DbAbstract::CELL:
                return (string) statement->fetchColumn();

            case DbAbstract::COLUMNS:
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

        throw new Exception("Invalid fetch mode: " . strval(mode));
    }

    protected function tryToBegin() -> bool
    {
        return this->pdo->beginTransaction();
    }

    protected function tryToCommit() -> bool
    {
        return this->pdo->commit();
    }

    protected function tryToRollback() -> bool
    {
        return this->pdo->rollback();
    }

}
