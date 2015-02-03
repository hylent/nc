namespace Nc\Db\Connection;

abstract class DbConnectionAdapter implements DbConnectionInterface
{
    protected inTransaction = false;

    private savepointSerial = 0;
    private savepoints;

    public function inTransaction() -> boolean
    {
        return this->inTransaction;
    }

    public function savepoint(boolean autoTransaction = false) -> string
    {
        string savepoint;

        if ! this->inTransaction {
            if unlikely ! autoTransaction {
                throw new Exception("Cannot acquire a savepoint when not in a transaction");
            }
            if unlikely ! this->begin() {
                throw new Exception("Cannot begin an auto transaction when acquiring a savepoint");
            }
        }

        let this->savepointSerial++;
        let savepoint = (string) sprintf("s%06d", this->savepointSerial);

        if this->query(DbConnectionInterface::WRITE, "savepoint " . savepoint) {
            let this->savepoints[savepoint] = savepoint;
            return savepoint;
        }

        return "";
    }

    public function releaseSavepoint(string savepoint) -> boolean
    {
        if unlikely ! this->inTransaction {
            throw new Exception("Cannot release a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new Exception("Invalid savepoint: " . savepoint);
        }

        if this->query(DbConnectionInterface::WRITE, "release savepoint " . savepoint) {
            unset(this->savepoints[savepoint]);
            return true;
        }

        return false;
    }

    public function releaseLastSavepoint() -> boolean
    {
        string savepoint;

        let savepoint = (string) array_pop(this->savepoints);
        if this->query(DbConnectionInterface::WRITE, "release savepoint " . savepoint) {
            return true;
        }

        let this->savepoints[savepoint] = savepoint;
        return false;
    }

    public function rollbackToSavepoint(string savepoint) -> boolean
    {
        if unlikely ! this->inTransaction {
            throw new Exception("Cannot rollback to a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new Exception("Invalid savepoint: " . savepoint);
        }

        if this->query(DbConnectionInterface::WRITE, "rollback to savepoint " . savepoint) {
            loop {
                if array_pop(this->savepoints) == savepoint {
                    break;
                }
            }
            return true;
        }

        return false;
    }

    public function rollbackToLastSavepoint() -> boolean
    {
        string savepoint;

        let savepoint = (string) array_pop(this->savepoints);
        if this->query(DbConnectionInterface::WRITE, "rollback to savepoint " . savepoint) {
            return true;
        }

        let this->savepoints[savepoint] = savepoint;
        return false;
    }
}
