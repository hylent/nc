namespace Nc\RateLimiter;

use Nc\Db\DbInterface;
use Nc\Db\DaoMysql;

class Mysql extends RateLimiterBackendAbstract
{
    CONST DDL = "CREATE TABLE %s (name VARCHAR(200) NOT NULL, rate VARCHAR(1000) NOT NULL, ts INT UNSIGNED NOT NULL DEFAULT 0, PRIMARY KEY (name)) ENGINE=InnoDB";

    protected daoMysql;
    protected numRetries;

    public function __construct(<DbInterface> db, string table, long numRetries = 2) -> void
    {
        let this->daoMysql = new DaoMysql(db, table, ["name"], "");
        let this->numRetries = numRetries;
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

    public function getNumRetries() -> long
    {
        return this->numRetries;
    }

    public function passRateLimits(string name, array rateLimits) -> boolean
    {
        var now, s, t, item, rate = [], row, rateOld, itemOld;
        long numRetries = 0;

        if count(rateLimits) < 1 {
            return true;
        }

        let now = time();

        for s, t in rateLimits {
            let s = (long) s;
            let t = (long) t;

            if unlikely s < 1 || t < 1 {
                throw new Exception(sprintf("Invalid input s/t '%d/%d'", s, t));
            }

            let item = [];
            let item[0] = (long) (now / s);
            let item[1] = t;
            let item[2] = 1;

            let rate[s] = item;
        }

        loop {
            let row = this->daoMysql->findFirst([
                "name ="    : name
            ], null, true);

            if ! row {
                try {
                    this->daoMysql->insert([
                        "name"  : name,
                        "rate"  : json_encode(rate),
                        "ts"    : now
                    ]);

                    return true;
                }

                continue;
            }

            let rateOld = json_decode(row["rate"], true);
            if typeof rateOld != "array" {
                let rateOld = [];
            }

            for s, item in rate {
                if ! fetch itemOld, rateOld[s] || ! itemOld {
                    continue;
                }
                if itemOld[0] < item[0] {
                    continue;
                }
                let t = (long) itemOld[2] + 1;
                if t > item[1] {
                    return false;
                }
                let rate[s][2] = t;
            }

            try {
                this->daoMysql->update([
                    "rate"      : json_encode(rate),
                    "ts"        : now
                ], [
                    "name ="    : name
                ]);

                return true;
            }

            let numRetries++;
            if numRetries > this->numRetries {
                break;
            }
        }

        return false;
    }

}
