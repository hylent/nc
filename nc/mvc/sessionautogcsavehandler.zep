namespace Nc\Mvc;

class SessionAutoGcSaveHandler implements \SessionHandlerInterface
{
    protected storage;
    protected gcMaxLifetime;

    public function __construct(<SessionAutoGcStorageInterface> storage) -> void
    {
        let this->storage = storage;
        let this->gcMaxLifetime = (long) ini_get("session.gc_maxlifetime");
    }

    public function register() -> void
    {
        session_set_save_handler(this);
        ini_set("session.gc_probability", 0);
    }

    public function getStorage() -> <SessionAutoGcStorageInterface>
    {
        return this->storage;
    }

    public function open(string savePath, string sessionName) -> boolean
    {
        return true;
    }

    public function read(string id) -> string
    {
        try {
            return (string) this->storage->readSessionData(id);
        }

        return "";
    }

    public function write(string id, string data) -> boolean
    {
        try {
            this->storage->writeSessionData(id, data, this->gcMaxLifetime);
            return true;
        }

        return false;
    }

    public function destroy(string id) -> boolean
    {
        try {
            this->storage->destroySessionData(id);
            return true;
        }

        return false;
    }

    public function close() -> boolean
    {
        return true;
    }

    public function gc(long maxLifetime) -> boolean
    {
        return true;
    }
}
