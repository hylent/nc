namespace Nc\Db\Query;

use Nc\Std;
use Nc\Db\DbInterface;

abstract class DbQueryAdapter
{
    protected db;
    protected table;
    protected tableAlias;

    protected where;
    protected join;
    protected field;
    protected groupBy;
    protected having;
    protected orderBy;
    protected page;
    protected pageSize;
    protected rowOffset;
    protected numRows;
    protected numPages;
    protected updates;
    protected updateParams;

    final public function __construct(<DbInterface> db, string table, string tableAlias = "") -> void
    {
        var a;

        let this->db = db;

        if tableAlias->length() > 0 {
            let this->table = table;
            let this->tableAlias = tableAlias;
        } else {
            let a = this->parseTableAlias(table);
            let this->table = a[0];
            let this->tableAlias = a[1];
        }
    }

    public function getDb() -> <DbInterface>
    {
        return this->db;
    }

    public function getTable() -> string
    {
        return this->table;
    }

    public function getTableAlias() -> string
    {
        return this->tableAlias;
    }

    public function duplicate()
    {
        string qClass;

        let qClass = get_class(this);
        return new {qClass}(this->db, this->table, this->tableAlias);
    }

    public function clear()
    {
        let this->where = null;
        let this->join = null;
        let this->field = null;
        let this->groupBy = null;
        let this->having = null;
        let this->orderBy = null;
        let this->page = null;
        let this->pageSize = null;
        let this->rowOffset = null;
        let this->numRows = null;
        let this->numPages = null;
        let this->updates = null;
        let this->updateParams = null;

        return this;
    }

    public function find(boolean forUpdate = false)
    {
        string sql;

        if forUpdate {
            let sql = "select * from " . this->table . this->buildWhere() . " for update";
            return this->db->query(DbInterface::WRITE | DbInterface::ROW, sql);
        }

        let sql = "select * from " . this->table . this->buildWhere();
        return this->db->query(DbInterface::READ | DbInterface::ROW, sql);
    }

    public function findMany(boolean forUpdate = false) -> array
    {
        string sql;

        if forUpdate {
            let sql = "select * from " . this->table . this->buildWhere() . " for update";
            return this->db->query(DbInterface::WRITE | DbInterface::ALL, sql);
        }

        let sql = "select * from " . this->table . this->buildWhere();
        return this->db->query(DbInterface::READ | DbInterface::ALL, sql);
    }

    public function delete() -> boolean
    {
        string sql;

        let sql = "delete from " . this->table . this->buildWhere();
        return this->db->query(DbInterface::WRITE, sql);
    }

    abstract public function insert(array data, string returningId = "");

    public function expression(string field, string expression)
    {
        let this->updates[field] = expression;
        return this;
    }

    public function increment(string field, var deta = 1)
    {
        let this->updates[field] = field . " + (:" . field . ")";
        let this->updateParams[field] = deta;

        return this;
    }

    public function decrement(string field, var deta = 1)
    {
        return this->increment(field, - deta);
    }

    public function concat(string field, string value, boolean prepend = false)
    {
        if prepend {
            let this->updates[field] = ":" . field . " || " . field;
        } else {
            let this->updates[field] = field . " || :" . field;
        }

        let this->updateParams[field] = value;
        return this;
    }

    public function clearUpdates()
    {
        let this->updates = null;
        let this->updateParams = null;

        return this;
    }

    public function update(array data = null) -> boolean
    {
        var k, v, kvs = [], params = [];
        string sql;

        if this->updates {
            for k, v in this->updates {
                let kvs[k] = k . " = " . v;
            }
        }

        if this->updateParams {
            for k, v in this->updateParams {
                let params[k] = v;
            }
        }

        if count(data) > 0 {
            for k, v in data {
                let kvs[k] = k . " = :" . k;
                let params[k] = v;
            }
        }

        let sql = "update " . this->table . " set " . join(", ", kvs) . this->buildWhere();
        return this->db->query(DbInterface::WRITE, sql, params);
    }

    public function replace(array data, var primaryKey = "id")
    {
        var k, v, pks = [], q, c;

        if typeof primaryKey == "array" {
            let pks = primaryKey;
        } else {
            let pks = [primaryKey];
        }

        let q = this->duplicate();

        for k in pks {
            if unlikely ! fetch v, data[k] {
                throw new Exception("Cannot replace when missing value in data: " . k);
            }
            q->eq(k, v);
        }

        let c = q->count();

        if unlikely c > 1 {
            throw new Exception("Cannot replace when primary key is not provided properly, records found: " . c);
        }

        if c < 1 {
            return q->insert(data);
        }

        return q->update(data);
    }

    public function aggregate(string aggregateFunction, string field)
    {
        string sql;

        let sql = "select " . aggregateFunction . "(" . field . ") from " . this->table . this->buildWhere();
        return this->db->query(DbInterface::READ | DbInterface::ONE, sql);
    }

    public function count(string field = "*") -> long
    {
        return (long) this->aggregate("count", field);
    }

    public function sum(string field)
    {
        return this->aggregate("sum", field);
    }

    public function max(string field)
    {
        return this->aggregate("max", field);
    }

    public function min(string field)
    {
        return this->aggregate("min", field);
    }

    public function groupAggregate(string aggregateFunction, string groupField, string aggregateField) -> array
    {
        var a;

        let a = this->duplicate()
            ->field(groupField . ", " . aggregateFunction . "(" . aggregateField . ") as nc_group_aggregate")
            ->groupBy(groupField)
            ->where(this->getWhere())
            ->select();

        return Std::indexedValues(a, groupField, "nc_group_aggregate");
    }

    public function groupCount(string groupField, string aggregateField = "*") -> array
    {
        return this->groupAggregate("count", groupField, aggregateField);
    }

    public function groupSum(string groupField, string aggregateField) -> array
    {
        return this->groupAggregate("sum", groupField, aggregateField);
    }

    public function groupMax(string groupField, string aggregateField) -> array
    {
        return this->groupAggregate("max", groupField, aggregateField);
    }

    public function groupMin(string groupField, string aggregateField) -> array
    {
        return this->groupAggregate("min", groupField, aggregateField);
    }

    abstract public function getSelectAsString() -> string;

    public function select()
    {
        return this->db->query(DbInterface::READ | DbInterface::ALL, this->getSelectAsString());
    }

    public function selectRow()
    {
        return this->db->query(DbInterface::READ | DbInterface::ROW, this->getSelectAsString());
    }

    public function selectOne()
    {
        return this->db->query(DbInterface::READ | DbInterface::ONE, this->getSelectAsString());
    }

    public function selectColumn() -> array
    {
        return this->db->query(DbInterface::READ | DbInterface::COLUMN, this->getSelectAsString());
    }

    abstract public function selectAndCount() -> array;

    public function join(string table, string on, string type)
    {
        var a;

        let a = this->parseTableAlias(table);
        let this->join .= " " . type . " join " . a[0] . " " . a[1] . " on " . on;

        return this;
    }

    public function innerJoin(string table, string on)
    {
        return this->join(table, on, "inner");
    }

    public function leftJoin(string table, string on)
    {
        return this->join(table, on, "left");
    }

    public function clearJoin()
    {
        let this->join = null;
        return this;
    }

    public function field(string field, boolean append = false)
    {
        if append && this->field {
            let this->field .= ", " . field;
        } else {
            let this->field = field;
        }

        return this;
    }

    public function clearField()
    {
        let this->field = null;
        return this;
    }

    public function where(string where)
    {
        if where->length() > 0 {
            let this->where = [where];
        } else {
            let this->where = [];
        }

        return this;
    }

    public function raw(string raw)
    {
        let this->where[] = raw;
        return this;
    }

    public function eq(string field, string value)
    {
        let this->where[] = field . " = " . this->db->quote(value);
        return this;
    }

    public function neq(string field, string value)
    {
        let this->where[] = field . " <> " . this->db->quote(value);
        return this;
    }

    public function gt(string field, string value)
    {
        let this->where[] = field . " > " . this->db->quote(value);
        return this;
    }

    public function gte(string field, string value)
    {
        let this->where[] = field . " >= " . this->db->quote(value);
        return this;
    }

    public function lt(string field, string value)
    {
        let this->where[] = field . " < " . this->db->quote(value);
        return this;
    }

    public function lte(string field, string value)
    {
        let this->where[] = field . " <= " . this->db->quote(value);
        return this;
    }

    public function between(string field, string v1, string v2)
    {
        let this->where[] = field . " between " . this->db->quote(v1) . " and " . this->db->quote(v2);
        return this;
    }

    public function $in(var field, array value, boolean notIn = false)
    {
        var ks, vs, vvs, i, ii;
        long len;

        if typeof field == "array" {
            let len = count(field);
            if unlikely len < 2 {
                throw new Exception("Invalid multi-in item");
            }
            let ks = [];
            for i in field {
                let ks[] = i;
            }
            let vs = [];
            for i in value {
                if typeof i != "array" || count(i) != len {
                    throw new Exception("Invalid multi-in item value");
                }
                let vvs = [];
                for ii in i {
                    let vvs[] = this->db->quote(ii);
                }
                let vs[] = "(" . join(", ", vvs) . ")";
            }
            if notIn {
                let this->where[] = "(" . join(", ", ks) . ") not in (" . join(", ", vs) . ")";
            } else {
                let this->where[] = "(" . join(", ", ks) . ") in (" . join(", ", vs) . ")";
            }
        } else {
            let vs = [];
            for i in value {
                let vs[] = this->db->quote(i);
            }
            if notIn {
                let this->where[] = field . " not in (" . join(", ", vs) . ")";
            } else {
                let this->where[] = field . " in (" . join(", ", vs) . ")";
            }
        }

        return this;
    }

    public function notIn(var field, array value)
    {
        return this->$in(field, value, true);
    }

    public function inSelect(var field, string select, boolean notInSelect = false)
    {
        string f;

        if typeof field == "array" {
            let f = "(" . join(", ", field) . ")";
        } else {
            let f = (string) field;
        }

        if notInSelect {
            let this->where[] = f . " not in (" . select . ")";
        } else {
            let this->where[] = f . " in (" . select . ")";
        }

        return this;
    }

    public function notInSelect(var field, string select)
    {
        return this->inSelect(field, select, true);
    }

    public function like(string field, string value, boolean half = false, boolean notLike = true)
    {
        if half {
            let value = value . "%";
        } else {
            let value = "%" . value . "%";
        }
        if notLike {
            let this->where[] = field . " not like " . this->db->quote(value);
        } else {
            let this->where[] = field . " like " . this->db->quote(value);
        }

        return this;
    }

    public function notLike(string field, string value, boolean half = false)
    {
        return this->like(field, value, half, true);
    }

    public function isNull(string field, boolean isNotNull = false)
    {
        if isNotNull {
            let this->where[] = field . " is not null";
        } else {
            let this->where[] = field . " is null";
        }

        return this;
    }

    public function isNotNull(string field)
    {
        return this->isNull(field, true);
    }

    public function setAnd()
    {
        var w;

        if this->where {
            let w = join(" and ", this->where);
            let this->where = ["(" . w . ")"];
        }

        return this;
    }

    public function setOr()
    {
        var w;

        if this->where {
            let w = join(" or ", this->where);
            let this->where = ["(" . w . ")"];
        }

        return this;
    }

    public function clearWhere()
    {
        let this->where = null;
        return this;
    }

    public function getWhere() -> string
    {
        if this->where {
            return implode(" and ", this->where);
        }

        return "";
    }

    public function groupBy(string field, boolean append = false)
    {
        if append && this->groupBy {
            let this->groupBy .= ", " . field;
        } else {
            let this->groupBy = field;
        }

        return this;
    }

    public function clearGroupBy()
    {
        let this->groupBy = null;
        return this;
    }

    public function having(string having)
    {
        let this->having = having;
        return this;
    }

    public function clearHaving()
    {
        let this->having = null;
        return this;
    }

    public function orderBy(string field, boolean asc = false, boolean prepend = false)
    {
        string sort;

        if asc {
            let sort = " asc";
        } else {
            let sort = " desc";
        }

        if this->orderBy {
            if prepend {
                let this->orderBy = field . sort . ", " . this->orderBy;
            } else {
                let this->orderBy .= ", " . field . sort;
            }
        } else {
            let this->orderBy = field . sort;
        }

        return this;
    }

    public function orderByRand()
    {
        let this->orderBy = false;
        return this;
    }

    public function clearOrderBy()
    {
        let this->orderBy = null;
        return this;
    }

    public function paginate(long page = 1, long pageSize = 10)
    {
        if page < 1 {
            let page = 1;
        }
        if pageSize < 1 {
            let pageSize = 1;
        }

        let this->page = page;
        let this->pageSize = pageSize;
        let this->rowOffset = pageSize * (page - 1);

        return this;
    }

    public function top(long num = 1)
    {
        let this->page = 1;
        let this->pageSize = max(1, num);
        let this->rowOffset = 0;

        return this;
    }

    public function clearPagination()
    {
        let this->page = null;
        let this->pageSize = null;
        let this->rowOffset = null;
        let this->numRows = null;
        let this->numPages = null;

        return this;
    }

    public function setNumRows(long numRows)
    {
        long numPages;

        if unlikely this->pageSize < 1 {
            throw new Exception("Cannot set num rows when not paginating");
        }

        if numRows < 1 {
            let numRows = 0;
            let numPages = 0;
        } else {
            let numPages = 1 + (long) ((numRows - 1) / this->pageSize);
        }

        let this->numRows = numRows;
        let this->numPages = numPages;

        return this;
    }

    public function getPage() -> long
    {
        return this->page;
    }

    public function getPageSize() -> long
    {
        return this->pageSize;
    }

    public function getRowOffset() -> long
    {
        return this->rowOffset;
    }

    public function getNumRows() -> long
    {
        return this->numRows;
    }

    public function getNumPages() -> long
    {
        return this->numPages;
    }

    protected function parseTableAlias(string s) -> array
    {
        var a;

        let a = preg_split("/\s+/", s, -1, PREG_SPLIT_NO_EMPTY);

        switch count(a) {
            case 1:
                let a[1] = a[0];
                break;
            case 2:
                break;

            default:
                throw new Exception("Cannot parse table alias: " . s);
        }

        return a;
    }

    protected function buildField() -> string
    {
        if this->field {
            return this->field;
        }

        return "*";
    }

    protected function buildTableAndJoin() -> string
    {
        return this->table . " " . this->tableAlias . this->join;
    }

    protected function buildWhere() -> string
    {
        if this->where {
            return " where " . join(" and ", this->where);
        }

        return "";
    }

    protected function buildGroupBy() -> string
    {
        if this->groupBy {
            return " group by " . this->groupBy;
        }

        return "";
    }

    protected function buildHaving() -> string
    {
        if this->having {
            return " having " . this->having;
        }

        return "";
    }

    protected function buildOrderBy() -> string
    {
        if this->orderBy {
            return " order by " . this->orderBy;
        }

        return "";
    }
}
