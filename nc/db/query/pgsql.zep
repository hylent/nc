namespace Nc\Db\Query;

use Nc\Db\DbInterface;

class Pgsql extends DbQueryAdapter
{
    public function insert(array data, string returningId = "")
    {
        var k, ks = [], vs = [];
        string sql;

        for k in array_keys(data) {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        let sql = "insert into " . this->table . " (" . join(", ", ks) . ") values (" . join(", ", vs) . ")";

        if returningId->length() > 0 {
            let sql .= " returning " . returningId;
            return this->db->query(DbInterface::WRITE | DbInterface::ONE, sql, data);
        }

        return this->db->query(DbInterface::WRITE, sql, data);
    }

    public function getSelectAsString() -> string
    {
        string s = "select ";

        let s .= this->buildField();
        let s .= " from ";
        let s .= this->buildTableAndJoin();
        let s .= this->buildWhere();
        let s .= this->buildGroupBy();
        let s .= this->buildHaving();
        let s .= this->buildOrderBy();

        if this->pageSize > 0 {
            let s .= " limit " . this->pageSize . " offset " . this->rowOffset;
        }

        return s;
    }

    public function selectAndCount() -> array
    {
        string sql;
        long numRows;

        let sql = "select count(*) from " . this->buildTableAndJoin() . this->buildWhere();
        let numRows = (long) this->db->query(DbInterface::READ | DbInterface::ONE, sql);
        this->setNumRows(numRows);

        if numRows > 0 {
            return this->db->query(DbInterface::READ | DbInterface::ALL, this->getSelectAsString());
        }

        return [];
    }

    protected function buildOrderBy() -> string
    {
        if this->orderBy === false {
            return " order by random()";
        }

        return parent::buildOrderBy();
    }
}
