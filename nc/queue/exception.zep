namespace Nc\Queue;

use Nc\Exception as Ex;

class Exception extends Ex
{
    const PUT_FAILURE           = 1;
    const RESERVE_FAILURE       = 2;
    const RESERVE_INVALID_TTR   = 3;
    const DELETE_FAILURE        = 4;
}
