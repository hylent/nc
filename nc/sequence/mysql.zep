namespace Nc\Sequence;

use Nc\Db\DbInterface;
use Nc\Db\DaoMysql;

class Mysql extends SequenceBackendAbstract
{
    const DDL = "CREATE TABLE %s (name VARCHAR(100) NOT NULL, sequence BIGINT UNSIGNED NOT NULL, PRIMARY KEY (name)) ENGINE=InnoDB";

    protected daoMysql;

    public function __construct(<DbInterface> db, string table) -> void
    {
        let this->daoMysql = new DaoMysql(db, table, ["name"], "");
    }

    public function getDaoMysql() -> <DaoMysql>
    {
        return this->daoMysql;
    }

    public function initialize() -> void
    {
        this->daoMysql->getDb()->execute(sprintf(
            self::DDL,
            this->daoMysql->getTable()
        ));
    }

    public function next(string name) -> long
    {
        this->daoMysql->upsert([
            "name"      : name,
            "sequence"  : ["last_insert_id(1)"]
        ], [
            "sequence = last_insert_id(sequence + 1)"
        ]);

        return (long) this->daoMysql->queryLastInsertId();
    }

    public function restore(string name, long sequence) -> void
    {
        this->daoMysql->replace([
            "name"      : name,
            "sequence"  : sequence
        ]);
    }

    public function clear() -> void
    {
        this->daoMysql->delete();
    }

}
