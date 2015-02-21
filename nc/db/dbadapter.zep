namespace Nc\Db;

use Nc\Std;

abstract class DbAdapter implements DbInterface
{
    protected queryClass;
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

        if this->query(DbInterface::WRITE, "savepoint " . savepoint) {
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

        if this->query(DbInterface::WRITE, "release savepoint " . savepoint) {
            unset(this->savepoints[savepoint]);
            return true;
        }

        return false;
    }

    public function releaseLastSavepoint() -> boolean
    {
        string savepoint;

        if unlikely ! this->savepoints {
            throw new Exception("Empty savepoint stack");
        }

        let savepoint = (string) array_pop(this->savepoints);
        if this->query(DbInterface::WRITE, "release savepoint " . savepoint) {
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

        if this->query(DbInterface::WRITE, "rollback to savepoint " . savepoint) {
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

        if unlikely ! this->savepoints {
            throw new Exception("Empty savepoint stack");
        }

        let savepoint = (string) array_pop(this->savepoints);
        if this->query(DbInterface::WRITE, "rollback to savepoint " . savepoint) {
            return true;
        }

        let this->savepoints[savepoint] = savepoint;
        return false;
    }

    public function setQueryClass(string queryClass) -> void
    {
        if unlikely ! is_subclass_of(queryClass, "Nc\\Db\\Query\\DbQueryAdapter") {
            throw new Exception("Invalid query class: " . queryClass);
        }

        let this->queryClass = queryClass;
    }

    public function getQueryClass() -> string
    {
        return this->queryClass;
    }

    public function __invoke(string table, string tableAlias = "")
    {
        string queryClass;

        let queryClass = (string) this->queryClass;
        return new {queryClass}(this, table, tableAlias);
    }
}
