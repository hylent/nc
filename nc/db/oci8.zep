namespace Nc\Db;

class Oci8 extends DbAbstract
{
    protected oci;

    public function __construct(string dsn, string user = "", string passwd = "") -> void
    {
        var oci;

        if unlikely ! extension_loaded("oci8") {
            throw new Exception("oci8", Exception::CONNECTION_NOT_SUPPORTED);
        }

        let oci = oci_connect(user, passwd, dsn, "utf8");
        if unlikely ! oci {
            throw new Exception(dsn, Exception::CONNECTION_FAILURE);
        }

        let this->oci = oci;
    }

    public function getOciResource()
    {
        return this->oci;
    }

    public function quote(string value) -> string
    {
        return "'" . str_replace("'", "''", value) . "'";
    }

    protected function tryToBegin() -> boolean
    {
        return true;
    }

    protected function tryToCommit() -> boolean
    {
        return oci_commit(this->oci);
    }

    protected function tryToRollback() -> boolean
    {
        return oci_rollback(this->oci);
    }

    protected function executeQuery(string sql, array params = [], boolean executionOnly = false)
    {
        var t, s, statement, k, v, mode, err, result, resultRow;
        boolean success;

        let t = microtime(true);
        let statement = oci_parse(this->oci, sql);

        if count(params) > 0 {
            for k, v in params {
                if ! is_int(k) {
                    oci_bind_by_name(statement, ":" . k, v);
                }
            }
        }

        if this->inTransaction {
            let mode = OCI_NO_AUTO_COMMIT;
        } else {
            let mode = OCI_COMMIT_ON_SUCCESS;
        }

        let success = (boolean) oci_execute(statement, mode);
        let s = this->addSql(sql, params, t);

        if unlikely ! success {
            let err = oci_error(this->oci);
            throw new Exception(err["message"] . " [SQL] " . s, Exception::EXECUTION_FAILURE);
        }

        if executionOnly {
            return (long) oci_num_rows(statement);
        }

        let result = [];
        let mode = OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_ASSOC;

        loop {
            let resultRow = oci_fetch_array(statement, mode);
            if ! resultRow {
                break;
            }
            let result[] = array_change_key_case(resultRow);
        }

        return result;
    }

}
