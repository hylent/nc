namespace Nc\Db;

class Oci8 extends DbAbstract
{
    protected oci;

    public function __construct(string dsn, string user, string passwd) -> void
    {
        var oci;

        if unlikely ! extension_loaded("oci8") {
            throw new Exception("Missing extension: 'oci8'");
        }

        let oci = oci_connect(user, passwd, dsn, "utf8");
        if unlikely ! oci {
            throw new Exception(sprintf("Cannot connect to '%s'", dsn));
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

    public function execute(string sql, array params = [], long $fetch = DbInterface::NONE)
    {
        var t, q, statement, k, v, err, errMessage, queryMode;
        boolean success;
        var result, resultRow, resultCell;

        let t = microtime(true);
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

        let success = (boolean) oci_execute(statement, queryMode);
        let q = this->addQuery(sql, params, t);

        if unlikely ! success {
            let err = oci_error(this->oci);
            if typeof err != "array" || ! fetch errMessage, err["message"] {
                let errMessage = "Unknown Error";
            }
            throw new ExecutionException(errMessage . " [SQL] " . q);
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
                return;

            case DbInterface::CELL:
                let resultRow = oci_fetch_array(statement, OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_NUM);
                if typeof resultRow == "array" && fetch resultCell, resultRow[0] {
                    return resultCell;
                }
                return "";

            case DbInterface::COLUMNS:
                let result = [];
                let queryMode = OCI_RETURN_NULLS + OCI_RETURN_LOBS + OCI_NUM;
                loop {
                    let resultRow = oci_fetch_array(statement, queryMode);
                    if typeof resultRow != "array" || ! fetch resultCell, resultRow[0] {
                        break;
                    }
                    let result[] = resultCell;
                }
                return result;
        }

        throw new Exception(sprintf("Invalid fetch mode '%s'", $fetch));
    }

    public function upsert(string t, array data, var primaryKey = "id") -> void
    {
        var pks, k, kk = [], vv = [], dual = [], cond = [], updates = [], s;

        let pks = this->checkUpsert(data, primaryKey);

        for k, _ in data {
            let kk[] = k;
            let vv[] = ":" . k;
            if isset pks[k] {
                let dual[] = sprintf(":%s %s", k, k);
                let cond[] = sprintf("a.%s = b.%s", k, k);
            } else {
                let updates[] = sprintf("%s = :%s", k, k);
            }
        }

        let s = "MERGE INTO " . t . " a";
        let s .= " USING (SELECT " . implode(", ", dual) . " FROM dual WHERE rownum < 2) b";
        let s .= " ON (" . implode(" AND ", cond) . ")";
        if count(updates) > 0 {
            let s .= " WHEN MATCHED THEN UPDATE SET " . implode(", ", updates);
        }
        let s .= " WHEN NOT MATCHED THEN INSERT (" . implode(", ", kk) . ") VALUES (" . implode(", ", vv) . ")";

        this->execute(s, data);
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

    protected function makeRandomOrder() -> string
    {
        return "dbms_random.value()";
    }

    protected function makePagination(string query, long limit, long skip) -> string
    {
        if skip == 0 {
            return sprintf("SELECT a.* FROM (%s) a WHERE rownum <= %d", query, limit);
        }

        return sprintf(
            "SELECT * FROM (SELECT a.*, rownum r FROM (%s) a WHERE rownum <= %d) b WHERE r > %d",
            query,
            limit,
            skip
        );
    }

}
