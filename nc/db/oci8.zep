namespace Nc\Db;

class Oci8 extends DbAbstract
{
    protected oci;

    public function __construct(string dsn, string user, string passwd) -> void
    {
        var oci;

        if unlikely ! extension_loaded("oci8") {
            throw new Exception("Missing extension: oci8");
        }

        let oci = oci_connect(user, passwd, dsn, "utf8");
        if unlikely ! oci {
            throw new Exception("Cannot connect: " . dsn);
        }

        let this->oci = oci;
    }

    public function getInternalHandler()
    {
        return this->oci;
    }

    public function quote(string value) -> string
    {
        return "'" . str_replace("'", "''", value) . "'";
    }

    public function queryAndFetch(long $fetch, string sql, array params = [])
    {
        var statement, k, v, err, errMessage, queryMode;
        double startMt;
        string profiledQuery;
        bool success;
        var result, resultRow, resultCell;

        let startMt = (double) microtime(true);
        let statement = oci_parse(this->oci, sql);

        if count(params) > 0 {
            for k, v in params {
                oci_bind_by_name(statement, ":" . k, v);
            }
        }

        if this->inTransaction {
            let queryMode = OCI_NO_AUTO_COMMIT;
        } else {
            let queryMode = OCI_COMMIT_ON_SUCCESS;
        }

        let success = (bool) oci_execute(statement, queryMode);

        let profiledQuery = (string) DbAbstract::profiledQuery(sql, params, startMt);
        let this->queries[] = profiledQuery;

        if unlikely ! success {
            let err = oci_error(this->oci);
            if typeof err != "array" || ! fetch errMessage, err["message"] {
                let errMessage = "Unknown Error";
            }
            throw new QueryException(errMessage . " [SQL] " . profiledQuery);
        }

        switch $fetch {
            case DbInterface::NONE:
                return;

            case DbInterface::ALL:
                let result = [];
                let queryMode = OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_ASSOC;
                loop {
                    let resultRow = oci_fetch_array(statement, queryMode);
                    if ! resultRow {
                        break;
                    }
                    let result[] = array_change_key_case(resultRow);
                }
                return result;

            case DbInterface::ROW:
                let resultRow = oci_fetch_array(statement, OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_ASSOC);
                if resultRow {
                    return array_change_key_case(resultRow);
                }
                return null;

            case DbInterface::CELL:
                let resultRow = oci_fetch_array(statement, OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_NUM);
                if resultRow && typeof resultRow == "array" && fetch resultCell, resultRow[0] {
                    return resultCell;
                }
                return "";

            case DbInterface::COLUMNS:
                let result = [];
                let queryMode = OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_NUM;
                loop {
                    let resultRow = oci_fetch_array(statement, queryMode);
                    if ! resultRow || typeof resultRow != "array" || ! fetch resultCell, resultRow[0] {
                        break;
                    }
                    let result[] = resultCell;
                }
                return result;
        }

        throw new Exception("Invalid fetch mode: " . strval($fetch));
    }

    public function upsert(string table, array data, var primaryKey = "id") -> void
    {
        var where, k, v, dual, cond, kk, vv, kv;
        string s;

        let where = this->pickWhereByKey(data, primaryKey);
        if unlikely count(where) < 1 {
            throw new Exception("Cannot upsert with empty where");
        }

        let dual = [];
        let cond = [];
        let kk = [];
        let vv = [];
        let kv = [];

        for k, v in where {
            let dual[] = sprintf("'%s' %s", v, k);
            let cond[] = sprintf("a.%s = b.%s", k, k);
        }

        for k, _ in data {
            let kk[] = k;
            let vv[] = ":" . k;
            if ! isset where[k] {
                let kv[] = k . " = :" . k;
            }
        }

        let s = "MERGE INTO " . table . " a";
        let s .= " USING (SELECT " . implode(", ", dual) . " FROM dual WHERE rownum < 2) b";
        let s .= " ON (" . implode(" AND ", cond) . ")";
        let s .= " WHEN MATCHED THEN UPDATE SET " . implode(", ", kv);
        let s .= " WHEN NOT MATCHED THEN INSERT (" . implode(", ", kk) . ") VALUES (" . implode(", ", vv) . ")";

        this->query(s, data);
    }

    public function parsePagination(string query, long limit, long skip) -> string
    {
        string s, t1, t2, r3;

        let t1 = (string) this->nextFlag("t");
        let s = (string) sprintf("SELECT %s.* FROM (%s) %s WHERE rownum <= %d", t1, query, t1, limit);

        if skip == 0 {
            return s;
        }

        let t2 = (string) this->nextFlag("t");
        let r3 = (string) this->nextFlag("r");

        return sprintf(
            "SELECT * FROM (SELECT %s.*, rownum %s FROM (%s) %s WHERE rownum <= %d) %s WHERE %s > %d",
            t1,
            r3,
            query,
            t1,
            limit,
            t2,
            r3,
            skip
        );
    }

    public function parseRandomOrder() -> string
    {
        return "dbms_random.value()";
    }

    protected function tryToBegin() -> bool
    {
        return true;
    }

    protected function tryToCommit() -> bool
    {
        return oci_commit(this->oci);
    }

    protected function tryToRollback() -> bool
    {
        return oci_rollback(this->oci);
    }

}
