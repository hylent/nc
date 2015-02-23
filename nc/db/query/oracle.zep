namespace Nc\Db\Query;

use Nc\Db\DbInterface;

class Oracle extends DbQueryAbstract
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

    public function replace(array data, var primaryKey = "id") -> boolean
    {
        var pks, k, a = [], b = [], ks = [], vs = [], kvs = [];
        string sql = "";

        if typeof primaryKey == "array" {
            let pks = primaryKey;
        } else {
            let pks = [];
            let pks[] = (string) primaryKey;
        }

        for k in pks {
            if unlikely typeof k != "string" {
                throw new Exception("Invalid pk type, string or string array required");
            }
            if unlikely ! isset data[k] {
                throw new Exception("Cannot find pk value in replacing data: " . k);
            }
            let a[] = ":" . k . " as " . k;
            let b[] = "a." . k . " = b." . k;
        }

        for k in array_keys(data) {
            let ks[] = k;
            let vs[] = ":" . k;
            let kvs[] = k . " = :" . k;
        }

        let sql .= "merge into ";
        let sql .= this->table;
        let sql .= " a using (select ";
        let sql .= (string) join(", ", a);
        let sql .= " from dual where rownum < 2) b on (";
        let sql .= (string) join(" and ", b);
        let sql .= ") when matched then update set ";
        let sql .= (string) join(", ", kvs);
        let sql .= " when not matched then insert (";
        let sql .= (string) join(", ", ks);
        let sql .= ") values (";
        let sql .= (string) join(", ", vs);
        let sql .= ")";

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
            let s = "select * from (select a.*, rownum r from (" . s
                . ") a where rownum <= " . this->pageSize . ") b where r > " . this->rowOffset;
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
            return " order by dbms_random.value()";
        }

        return parent::buildOrderBy();
    }
}
