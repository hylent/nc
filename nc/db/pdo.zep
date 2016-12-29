namespace Nc\Db;

class Pdo extends DbAbstract
{
    protected pdo;

    public function __construct(string dsn, string user = "", string passwd = "", array driverOptions = []) -> void
    {
        var ex = null;

        if unlikely ! extension_loaded("pdo") {
            throw new Exception("pdo", Exception::CONNECTION_NOT_SUPPORTED);
        }

        try {
            let this->pdo = new \Pdo(dsn, user, passwd, driverOptions);
        } catch \PdoException, ex {
            throw new Exception(ex->getMessage(), Exception::CONNECTION_FAILURE);
        }
    }

    public function getPdo()
    {
        return this->pdo;
    }

    public function quote(string value) -> string
    {
        return this->pdo->quote(value);
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

    protected function executeQuery(string sql, array params = [], boolean executionOnly = false)
    {
        var t, s, statement, k, v, err;
        boolean success;

        let t = microtime(true);
        let statement = this->pdo->prepare(sql);

        if count(params) > 0 {
            for k, v in params {
                if ! is_int(k) {
                    statement->bindValue(":" . k, v, \Pdo::PARAM_STR);
                }
            }
        }

        let success = (boolean) statement->execute();
        let s = this->addSql(sql, params, t);

        if unlikely ! success {
            let err = statement->errorInfo();
            throw new Exception(err[2] . " [SQL] " . s, Exception::EXECUTION_FAILURE);
        }

        if executionOnly {
            return (long) statement->rowCount();
        }

        return statement->fetchAll(\Pdo::FETCH_ASSOC);
    }

}
