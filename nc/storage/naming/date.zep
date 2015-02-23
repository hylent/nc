namespace Nc\Storage\Naming;

use Nc\Std;

class Date implements StorageNamingInterface
{
    protected dateFormat;
    protected randStringLength;

    public function __construct(string dateFormat = "Y/m/d/His_", long randStringLength = 6) -> void
    {
        let this->dateFormat = dateFormat;
        let this->randStringLength = randStringLength;
    }

    public function generateName() -> string
    {
        return date(this->dateFormat) . Std::randString(this->randStringLength);
    }
}
