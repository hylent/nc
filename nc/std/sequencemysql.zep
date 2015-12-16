namespace Nc\Std;

use Nc\Db\PdoMysql;

class SequenceMysql implements SequenceInterface
{
    const DEFAULT_TABLE = "sequencetable";

    protected mysql;
    protected table;

    public function __construct(<PdoMysql> mysql, string table = self::DEFAULT_TABLE) -> void
    {
        let this->mysql = mysql;
        let this->table = table;
    }

    public function getNextSequence(string identifier) -> long
    {
        return (long) this->mysql->insert(this->table, [
            "identifier": identifier
        ], "sequence", true);
    }

    public function restoreSequence(string identifier, long sequence) -> void
    {
        this->mysql->insert(this->table, [
            "identifier": identifier,
            "sequence": sequence
        ], "", true);
    }

}

/*
CREATE TABLE IF NOT EXISTS sequencetable (
  identifier VARCHAR(100) NOT NULL,
  sequence INT(11) NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (identifier),
  KEY (identifier, sequence)
) ENGINE=MyISAM;
*/
