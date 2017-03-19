namespace Nc\Mvc;

interface SessionAutoGcStorageInterface
{
    public function readSessionData(string id) -> string;
    public function writeSessionData(string id, string data, long ttl) -> void;
    public function destroySessionData(string id) -> void;
}
