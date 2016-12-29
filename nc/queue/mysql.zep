namespace Nc\Queue;

use Nc\Db\DbInterface;
use Nc\Db\DaoMysql;

class Mysql implements QueueInterface
{
    CONST DDL = "CREATE TABLE %s (id BIGINT UNSIGNED NOT NULL, ts INT UNSIGNED NOT NULL, PRIMARY KEY (id), KEY (ts)) ENGINE=InnoDB";

    protected daoMysql;

    public function __construct(<DbInterface> db, string table) -> void
    {
        let this->daoMysql = new DaoMysql(db, table, ["id"], "");
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

    public function put(string id, long delay = 0) -> void
    {
        this->daoMysql->repalce([
            "id"    : id,
            "ts"    : time() + delay
        ]);
    }

    public function reserve(long ttr) -> string
    {
        var now, rc;

        if unlikely ttr < 1 {
            throw new Exception(__FUNCTION__, Exception::RESERVE_INVALID_TTR);
        }

        let now = time();

        let rc = this->daoMysql->updateTop([
            "ts"    : now + ttr,
            "id = last_insert_id(id)"
        ], [
            "ts >=" : 1,
            "ts <=" : now
        ], [
            "ts"    : 1,
            "id"    : 1
        ], 1);

        if rc > 0 {
            return this->daoMysql->queryLastInsertId();
        }

        return "";
    }

    public function delete(string id) -> void
    {
        this->daoMysql->delete([
            "id ="  : id
        ]);
    }

}
