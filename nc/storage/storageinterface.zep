namespace Nc\Storage;

interface StorageInterface
{
    public function store(string source, string group = "", string extension = "", boolean rm = false) -> string;
    public function remove(string uri) -> boolean;
}
