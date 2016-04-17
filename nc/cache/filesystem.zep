namespace Nc\Cache;

class FileSystem extends CacheBackendAbstract
{
    protected baseDirectory;
    protected mode;

    public static function rmDirRecursively(string dir) -> void
    {
        var handle, path;

        let handle = opendir(dir);
        if ! handle {
            return;
        }

        loop {
            let path = readdir(handle);
            if path === false {
                break;
            }

            if path == "." || path == ".." {
                continue;
            }

            let path = dir . "/" . path;

            if is_dir(path) {
                self::rmDirRecursively(path);
            } else {
                unlink(path);
            }
        }

        rmdir(dir);
    }

    public function __construct(string baseDirectory, long mode = 0777) -> void
    {
        let this->baseDirectory = baseDirectory;
        let this->mode = mode;
    }

    public function getBaseDirectory() -> string
    {
        return this->baseDirectory;
    }

    public function getMode() -> long
    {
        return this->mode;
    }

    public function clear(string poolName = "") -> void
    {
        if poolName->length() < 1 {
            self::rmDirRecursively(this->baseDirectory);
            return;
        }

        self::rmDirRecursively(this->getDir(poolName));
    }

    public function store(string poolName, string key, var value, long ttl = 0) -> void
    {
        var path;

        let path = this->getPath(poolName, key, true);

        if unlikely ! file_put_contents(path, this->packData(value, ttl), LOCK_EX) {
            throw new Exception(sprintf("Cannot write cache value to path '%s'", path));
        }
    }

    public function $fetch(string poolName, string key)
    {
        var path;

        let path = this->getPath(poolName, key);

        if file_exists(path) {
            return require path;
        }
    }

    public function forget(string poolName, string key) -> void
    {
        var path;

        let path = this->getPath(poolName, key);

        if unlikely file_exists(path) && ! unlink(path) {
            throw new Exception(sprintf("Cannot forget cache value in path '%s'", path));
        }
    }

    protected function getDir(string poolName) -> string
    {
        return this->baseDirectory . "/" . urlencode(poolName);
    }

    protected function getPath(string poolName, string key, boolean mkDirIfNeeded = false) -> string
    {
        string hash, path;
        var dirname;

        let hash = (string) sha1(key);
        let path = (string) this->getDir(poolName);

        let path .= '/';
        let path .= hash[0];
        let path .= hash[1];
        let path .= '/';
        let path .= hash;
        let path .= ".php";

        if mkDirIfNeeded {
            let dirname = dirname(path);
            if unlikely ! file_exists(dirname) && ! mkdir(dirname, this->mode, true) {
                throw new Exception(sprintf("Cannot mkdir '%s'", dirname));
            }
        }

        return path;
    }

    protected function packData(var value, long ttl) -> string
    {
        if ttl < 1 {
            return sprintf("<?php return %s;\n", var_export(value, true));
        }

        return sprintf("<?php return time() > %d ? null : %s;\n", ttl + time(), var_export(value, true));
    }

}
