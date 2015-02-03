namespace Nc\Storage\NamePolicy;

use Nc\Std;

class Uuid implements StorageNamePolicyInterface
{
    public function generateName() -> string
    {
        return Std::uuid();
    }
}
