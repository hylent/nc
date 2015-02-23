namespace Nc\Db;

abstract class DbAbstract implements DbInterface
{
    protected inTransaction = false;
    protected savepointSerial = 0;
    protected savepoints;
    protected queryClass;

    public function inTransaction() -> boolean
    {
        return this->inTransaction;
    }

    public function begin() -> void
    {
        if unlikely !! this->inTransaction {
            throw new TransactionException("Cannot begin when already in transaction");
        }

        if unlikely ! this->tryToBegin() {
            throw new TransactionException("Cannot begin transaction");
        }

        let this->inTransaction = true;
    }

    public function commit() -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot commit when not in transaction");
        }

        if unlikely ! this->tryToCommit() {
            throw new TransactionException("Cannot commit transaction");
        }

        let this->inTransaction = false;
        let this->savepoints = null;
    }

    public function rollback() -> void
    {
        if unlikely ! this->inTransaction {
            throw new TransactionException("Cannot rollback when not in transaction");
        }

        if unlikely ! this->tryToRollback() {
            throw new TransactionException("Cannot rollback transaction");
        }

        let this->inTransaction = false;
        let this->savepoints = null;
    }

    public function savepoint(string savepoint = "") -> string
    {
        if unlikely ! this->inTransaction {
            throw new SavepointException("Cannot acquire a savepoint when not in a transaction");
        }

        if savepoint->length() < 1 {
            let this->savepointSerial++;
            let savepoint = (string) sprintf("s%06d", this->savepointSerial);
        }

        if unlikely isset this->savepoints[savepoint] {
            throw new SavepointException("Duplicate savepoint: " . savepoint);
        }

        if unlikely ! this->query(DbInterface::WRITE, "savepoint " . savepoint) {
            throw new SavepointException("Cannot acquire savepoint: " . savepoint);
        }

        let this->savepoints[savepoint] = savepoint;
        return savepoint;
    }

    public function releaseSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new SavepointException("Cannot release a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new SavepointException("Cannot find savepoint: " . savepoint);
        }

        if unlikely ! this->query(DbInterface::WRITE, "release savepoint " . savepoint) {
            throw new SavepointException("Cannot release savepoint: " . savepoint);
        }

        unset(this->savepoints[savepoint]);
    }

    public function releaseLastSavepoint() -> void
    {
        string savepoint;

        if unlikely ! this->inTransaction {
            throw new SavepointException("Cannot release last savepoint when not in a transaction");
        }

        if unlikely ! this->savepoints {
            throw new SavepointException("Empty savepoint stack");
        }

        let savepoint = (string) array_pop(this->savepoints);

        if unlikely ! this->query(DbInterface::WRITE, "release savepoint " . savepoint) {
            let this->savepoints[savepoint] = savepoint;
            throw new SavepointException("Cannot release last savepoint: " . savepoint);
        }
    }

    public function rollbackToSavepoint(string savepoint) -> void
    {
        if unlikely ! this->inTransaction {
            throw new SavepointException("Cannot rollback to a savepoint when not in a transaction");
        }

        if unlikely ! isset this->savepoints[savepoint] {
            throw new SavepointException("Cannot find savepoint: " . savepoint);
        }

        if unlikely ! this->query(DbInterface::WRITE, "rollback to savepoint " . savepoint) {
            throw new SavepointException("Cannot rollback to savepoint: " . savepoint);
        }

        loop {
            if (string) array_pop(this->savepoints) === savepoint {
                let this->savepoints[savepoint] = savepoint;
                break;
            }
        }
    }

    public function rollbackToLastSavepoint() -> void
    {
        string savepoint;

        if unlikely ! this->inTransaction {
            throw new SavepointException("Cannot rollback to last savepoint when not in a transaction");
        }

        if unlikely ! this->savepoints {
            throw new SavepointException("Empty savepoint stack");
        }

        let savepoint = (string) array_pop(this->savepoints);
        let this->savepoints[savepoint] = savepoint;

        if unlikely ! this->query(DbInterface::WRITE, "rollback to savepoint " . savepoint) {
            throw new SavepointException("Cannot rollback to last savepoint: " . savepoint);
        }
    }

    public function transactionAtomic(var callback, array args = [])
    {
        var result, ex;

        if unlikely ! is_callable(callback) {
            throw new Exception("Invalid callback");
        }

        if unlikely !! this->inTransaction {
            throw new TransactionException("Cannot do transaction atomic operations when in a transaction");
        }

        this->begin();

        try {
            let result = call_user_func_array(callback, args);
            this->commit();
            return result;
        } catch \Exception, ex {
            this->rollback();
            throw ex;
        }
    }

    public function savepointAtomic(var callback, array args = [], string savepointIfNeeded = "")
    {
        string savepoint;
        var ex;

        if unlikely ! is_callable(callback) {
            throw new Exception("Invalid callback");
        }

        if unlikely ! this->inTransaction {
            throw new SavepointException("Cannot do savepoint atomic operations when not in a transaction");
        }

        let savepoint = (string) this->savepoint(savepointIfNeeded);

        try {
            return call_user_func_array(callback, args);
        } catch \Exception, ex {
            this->rollbackToSavepoint(savepoint);
            throw ex;
        }
    }

    public function atomic(var callback, array args = [])
    {
        if this->inTransaction {
            return this->savepointAtomic(callback, args);
        }

        return this->transactionAtomic(callback, args);
    }

    public function setQueryClass(string queryClass) -> void
    {
        if unlikely ! is_subclass_of(queryClass, "Nc\\Db\\Query\\DbQueryAbstract") {
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

    abstract protected function tryToBegin() -> boolean;
    abstract protected function tryToCommit() -> boolean;
    abstract protected function tryToRollback() -> boolean;
}
