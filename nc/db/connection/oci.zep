namespace Nc\Db\Connection;

class Oci extends DbConnectionAdapter
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

    public function begin() -> boolean
    {
        if unlikely !! this->inTransaction {
            throw new Exception("Already in transaction");
        }

        let this->inTransaction = true;
        return true;
    }

    public function commit() -> boolean
    {
        if oci_commit(this->oci) {
            let this->inTransaction = false;
            return true;
        }

        return false;
    }

    public function rollback() -> boolean
    {
        if oci_rollback(this->oci) {
            let this->inTransaction = false;
            return true;
        }

        return false;
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
                oci_bind_by_name(stmt, k, v);
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

        let flagVar = flag & DbConnectionInterface::FETCH_MASK;

        if flagVar {
            let mode = OCI_RETURN_NULLS + OCI_RETURN_LOBS;

            switch (flagVar) {
            case DbConnectionInterface::ALL:
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

            case DbConnectionInterface::ROW:
                let row = oci_fetch_array(stmt, mode + OCI_ASSOC);
                return row ? array_change_key_case(row) : null;

            case DbConnectionInterface::ONE:
                let row = oci_fetch_array(stmt, mode + OCI_NUM);
                if row && typeof row == "array" && fetch item, row[0] {
                    return item;
                }
                return "";

            case DbConnectionInterface::COLUMN:
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
}
