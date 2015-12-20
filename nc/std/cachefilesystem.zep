namespace Nc\Std;

class CacheFileSystem implements CacheInterface
{
    protected baseDirectory;

    public function __construct(string baseDirectory) -> void
    {
        let this->baseDirectory = baseDirectory;
    }

    public function setCache(string identifier, var data, long lifetime = 0) -> void
    {
        string path;

        let path = (string) this->path(identifier, true);

        if unlikely ! file_put_contents(path, this->packData(data, lifetime), LOCK_EX) {
            throw new Exception("Cannot write data to path: " . path);
        }
    }

    public function getCache(string identifier)
    {
        string path;

        let path = (string) this->path(identifier);
        if file_exists(path) {
            return require path;
        }
    }

    public function deleteCache(string identifier) -> void
    {
        string path;

        let path = (string) this->path(identifier);
        if unlikely file_exists(path) && ! unlink(path) {
            throw new Exception("Cannot forget data in path: " . path);
        }
    }

    protected function path(string identifier, bool mkdirIfNeeded = false) -> string
    {
        string hash, path, dirname;

        let hash = (string) sha1(identifier);
        let path = (string) this->baseDirectory;

        let path .= '/';
        let path .= hash[0];
        let path .= hash[1];
        let path .= '/';
        let path .= hash;
        let path .= ".php";

        if mkdirIfNeeded {
            let dirname = (string) dirname(path);
            if unlikely ! file_exists(dirname) && ! mkdir(dirname, 0755, true) {
                throw new Exception("Cannot mkdir: " . dirname);
            }
        }

        return path;
    }

    protected function packData(var data, long lifetime) -> string
    {
        if lifetime < 1 {
            return sprintf("<?php return %s;\n", var_export(data, true));
        }

        let lifetime += (long) time();
        return sprintf("<?php return time() > %d ? null : %s;\n", lifetime, var_export(data, true));
    }

}
