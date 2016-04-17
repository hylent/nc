namespace Nc\Storage;

interface StorageInterface
{
    const COPY                  = 1;
    const MOVE                  = 2;
    const MOVE_UPLOADED_FILE    = 3;

    public function store(string src, string pre = "", string ext = "", long type = StorageInterface::COPY) -> string;
    public function remove(string uri) -> boolean;
    public function exists(string uri) -> boolean;

}
