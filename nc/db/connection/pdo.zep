namespace Nc\Db\Connection;

class Pdo extends DbConnectionAdapter
{
    protected pdo;

    public function __construct() -> void
    {
        if unlikely ! extension_loaded("pdo") {
            throw new Exception("Missing extension: pdo");
        }

        let this->pdo = (new \ReflectionClass("PDO"))->newInstanceArgs(func_get_args());
    }

    public function begin() -> boolean
    {
        if unlikely !! this->inTransaction {
            throw new Exception("Already in transaction");
        }

        if this->pdo->beginTransaction() {
            let this->inTransaction = true;
            return true;
        }

        return false;
    }

    public function commit() -> boolean
    {
        if this->pdo->commit() {
            let this->inTransaction = false;
            return true;
        }

        return false;
    }

    public function rollback() -> boolean
    {
        if this->pdo->rollback() {
            let this->inTransaction = false;
            return true;
        }

        return false;
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
                    stmt->bindParam(k, "" . v, \Pdo::PARAM_STR, strlen(v));
                } else {
                    stmt->bindValue(k, v);
                }
            }
        }

        let success = stmt->execute();

        if unlikely ! success {
            let err = stmt->errorInfo();
            throw new QueryException(err[2] . "[SQL:] " . sql);
        }

        switch (flag & DbConnectionInterface::FETCH_MASK) {
            case DbConnectionInterface::ALL:
                return stmt->fetchAll(\Pdo::FETCH_ASSOC);

            case DbConnectionInterface::ROW:
                let row = stmt->$fetch(\Pdo::FETCH_ASSOC);
                return row ? row : null;

            case DbConnectionInterface::ONE:
                let item = stmt->fetchColumn();
                return item;

            case DbConnectionInterface::COLUMN:
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
}
