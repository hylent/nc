namespace Nc\Db;

class Oci extends DbAbstract
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
        let this->queryClass = "Nc\\Db\\Query\\Oracle";
    }

    public function quote(string value) -> string
    {
        return "'" . str_replace("'", "''", value) . "'";
    }

    public function query(long flag, string sql, array params = null)
    {
        var stmt, k, v, success, err, errMsg, mode, data, row, item, flagVar;

        if this->inTransaction {
            let flagVar = OCI_NO_AUTO_COMMIT;
        } else {
            let flagVar = OCI_COMMIT_ON_SUCCESS;
        }

        let stmt = oci_parse(this->oci, sql);

        if count(params) > 0 {
            for k, v in params {
                oci_bind_by_name(stmt, ":" . k, v);
            }
        }

        let success = oci_execute(stmt, flagVar);

        if unlikely ! success {
            let err = oci_error(this->oci);
            if typeof err != "array" || ! fetch errMsg, err["message"] {
                let errMsg = "";
            }
            throw new QueryException(errMsg . "[SQL:] " . sql);
        }

        let flagVar = flag & DbInterface::FETCH_MASK;

        if flagVar {
            let mode = OCI_RETURN_NULLS + OCI_RETURN_LOBS;

            switch (flagVar) {
            case DbInterface::ALL:
                let mode += OCI_ASSOC;
                let data = [];
                loop {
                    let row = oci_fetch_array(stmt, mode);
                    if ! row {
                        break;
                    }
                    let data[] = array_change_key_case(row);
                }
                return data;

            case DbInterface::ROW:
                let row = oci_fetch_array(stmt, mode + OCI_ASSOC);
                return row ? array_change_key_case(row) : null;

            case DbInterface::ONE:
                let row = oci_fetch_array(stmt, mode + OCI_NUM);
                if row && typeof row == "array" && fetch item, row[0] {
                    return item;
                }
                return "";

            case DbInterface::COLUMN:
                let mode += OCI_NUM;
                let data = [];
                loop {
                    let row = oci_fetch_array(stmt, mode);
                    if ! row || typeof row != "array" || ! fetch item, row[0] {
                        break;
                    }
                    let data[] = item;
                }
                return data;
            }
        }

        return true;
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
}
