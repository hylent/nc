namespace Nc\Storage\NamePolicy;

interface StorageNamePolicyInterface
{
    public function generateName() -> string;
}
