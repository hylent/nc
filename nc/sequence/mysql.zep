namespace Nc\Sequence;

use Nc\Db\PdoMysql;

class Mysql extends SequenceBackendAbstract
{
    const DEFAULT_TABLE = "sequencetable";

    protected mysql;
    protected table;

    public static function createTableSql(string table = self::DEFAULT_TABLE) -> string
    {
        return "CREATE TABLE IF NOT EXISTS " . table . " ("
            . "name VARCHAR(100) NOT NULL,"
            . "sequence INT(11) NOT NULL AUTO_INCREMENT,"
            . "PRIMARY KEY (name),"
            . "KEY (name, sequence)"
            . ") ENGINE=MyISAM";
    }

    public function __construct(<PdoMysql> mysql, string table = self::DEFAULT_TABLE) -> void
    {
        let this->mysql = mysql;
        let this->table = table;
    }

    public function getPdoMysql() -> <PdoMysql>
    {
        return this->mysql;
    }

    public function getTable() -> string
    {
        return this->table;
    }

    public function next(string name) -> long
    {
        return (long) this->mysql->insert(this->table, [
            "name": name
        ], "sequence", true);
    }

    public function restore(string name, long sequence) -> void
    {
        this->mysql->insert(this->table, [
            "name": name,
            "sequence": sequence
        ], "", true);
    }

    public function clear() -> void
    {
        this->mysql->delete(this->table, []);
    }

}
