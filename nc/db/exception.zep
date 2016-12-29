namespace Nc\Db;

use Nc\Exception as Ex;

class Exception extends Ex
{
    const CONNECTION_NOT_SUPPORTED  = 1;
    const CONNECTION_FAILURE        = 2;
    const EXECUTION_FAILURE         = 3;
    const TRANSACTION_FAILURE       = 4;
    const QUERY_NOT_IMPLEMENTED     = 5;
    const QUERY_INVALID_WHERE       = 6;
    const UPSERT_PK_EMPTY           = 7;
    const UPSERT_PK_UNSATISFIED     = 8;
}
