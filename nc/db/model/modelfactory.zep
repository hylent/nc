namespace Nc\Db\Model;

use Nc\Db\DbAwareInterface;
use Nc\Db\DbInterface;

class ModelFactory implements DbAwareInterface
{
    public function setDb(<DbInterface> db) -> void
    {
        let this->db = db;
    }

    public function getDb() -> <DbInterface>
    {
        return this->db;
    }

    public function __isset(string name) -> boolean
    {
        return true;
    }

    public function __get(string name) -> <Model>
    {
        return new Model(this, name, name);
    }
}
