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

    public function query(string sql, array params = [], long mode = DbAbstract::NONE)
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

        switch mode {
            case DbAbstract::NONE:
                return;

            case DbAbstract::ALL:
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

            case DbAbstract::ROW:
                let resultRow = oci_fetch_array(statement, OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_ASSOC);
                if resultRow {
                    return array_change_key_case(resultRow);
                }
                return null;

            case DbAbstract::CELL:
                let resultRow = oci_fetch_array(statement, OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_NUM);
                if resultRow && typeof resultRow == "array" && fetch resultCell, resultRow[0] {
                    return resultCell;
                }
                return "";

            case DbAbstract::COLUMNS:
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

        throw new Exception("Invalid fetch mode: " . strval(mode));
    }

    public function paginationSql(string query, long limit, long skip) -> string
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

    public function randomOrderSql() -> string
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