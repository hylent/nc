namespace Nc\Db;

class Pdo extends DbAbstract
{
    protected pdo;

    public function __construct() -> void
    {
        var pdo;

        if unlikely ! extension_loaded("pdo") {
            throw new Exception("Missing extension: pdo");
        }

        let pdo = (new \ReflectionClass("PDO"))->newInstanceArgs(func_get_args());

        let this->pdo = pdo;
        let this->queryClass = "Nc\\Db\\Query\\" . ucfirst(pdo->getAttribute(\Pdo::ATTR_DRIVER_NAME));
    }

    public function quote(string value) -> string
    {
        return this->pdo->quote(value);
    }

    public function query(long flag, string sql, array params = null)
    {
        var stmt, k, v, success, err, data, row, item;

        let stmt = this->pdo->prepare(sql);

        if count(params) > 0 {
            for k, v in params {
                if typeof v == "string" {
                    stmt->bindParam(":" . k, "" . v, \Pdo::PARAM_STR, strlen(v));
                } else {
                    stmt->bindValue(":" . k, v);
                }
            }
        }

        let success = stmt->execute();

        if unlikely ! success {
            let err = stmt->errorInfo();
            throw new QueryException(err[2] . "[SQL:] " . sql);
        }

        switch (flag & DbInterface::FETCH_MASK) {
            case DbInterface::ALL:
                return stmt->fetchAll(\Pdo::FETCH_ASSOC);

            case DbInterface::ROW:
                let row = stmt->$fetch(\Pdo::FETCH_ASSOC);
                return row ? row : null;

            case DbInterface::ONE:
                let item = stmt->fetchColumn();
                return item;

            case DbInterface::COLUMN:
                let data = [];
                loop {
                    let item = stmt->fetchColumn();
                    if typeof item != "string" {
                        break;
                    }
                    let data[] = item;
                }
                return data;
        }

        return true;
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
