namespace Nc\Storage\Naming;

use Nc\Std;

class Uuid implements StorageNamingInterface
{
    public function generateName() -> string
    {
        return Std::uuid();
    }
}
