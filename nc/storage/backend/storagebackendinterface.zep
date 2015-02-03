namespace Nc\Storage\Backend;

interface StorageBackendInterface
{
    public function store(string source, string group = "", string extension = "", boolean mv = false) -> string;
    public function remove(string uri) -> boolean;
}
