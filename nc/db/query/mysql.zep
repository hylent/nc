namespace Nc\Db\Query;

use Nc\Db\DbInterface;

class Mysql extends DbQueryAdapter
{
    public function insert(array data, string returningId = "")
    {
        var k, v, ks = [], vs = [];
        string sql;

        for k in array_keys(data) {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        let sql = "insert into " . this->table . " (" . join(", ", ks) . ") values (" . join(", ", vs) . ")";

        if ! this->db->query(DbInterface::WRITE, sql, data) {
            return false;
        }

        if returningId->length() < 1 {
            return true;
        }

        if fetch v, data[returningId] {
            return v;
        }

        return this->db->query(DbInterface::WRITE | DbInterface::ONE, "select last_insert_id()");
    }

    public function concat(string field, string value, boolean prepend = false)
    {
        if prepend {
            let this->updates[field] = "concat(:" . field . ", " . field . ")";
        } else {
            let this->updates[field] = "concat(" . field . ", :" . field . ")";
        }

        let this->updateParams[field] = value;
        return this;
    }

    public function replace(array data, var primaryKey = "id")
    {
        var k, ks = [], vs = [];
        string sql;

        for k in array_keys(data) {
            let ks[] = k;
            let vs[] = ":" . k;
        }

        let sql = "replace into " . this->table . " (" . join(", ", ks) . ") values (" . join(", ", vs) . ")";
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
            let s .= " limit " . this->rowOffset . ", " . this->pageSize;
        }

        return s;
    }

    public function selectAndCount() -> array
    {
        string sql;
        var data;
        long numRows;

        let sql = (string) preg_replace("/^select/", "select sql_calc_found_rows", this->getSelectAsString());
        let data = this->db->query(DbInterface::READ | DbInterface::ALL, sql);
        let numRows = (long) this->db->query(DbInterface::READ | DbInterface::ONE, "select found_rows()");

        this->setNumRows(numRows);

        return data;
    }

    protected function buildOrderBy() -> string
    {
        if this->orderBy === false {
            return " order by rand()";
        }

        return parent::buildOrderBy();
    }
}
