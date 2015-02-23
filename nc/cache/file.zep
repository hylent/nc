namespace Nc\Cache;

class File extends CacheAbstract
{
    protected directory;

    public function __construct(string directory) -> void
    {
        if unlikely ! is_dir(directory) || ! is_writable(directory) {
            throw new Exception("Invalid cache directory");
        }

        let this->directory = directory;
    }

    public function flush() -> void
    {
        var p;

        for p in glob(this->directory . "/*.php") {
            if preg_match(";/[0-9a-f]{32}\\.php$;", p) && is_writable(p) {
                unlink(p);
            }
        }
    }

    public function rawSet(string key, var value, long lifetime = 0) -> void
    {
        var path, data;

        let path = this->getPath(key);

        if lifetime > 0 {
            let data = sprintf("<?php return %ld < time() ? false : %s;", time() + lifetime, var_export(value, true));
        } else {
            let data = "<?php return " . var_export(value, true) . ";";
        }

        file_put_contents(path, data, LOCK_EX);
    }

    public function rawGet(string key)
    {
        var path, data;

        let path = this->getPath(key);
        if ! file_exists(path) {
            return;
        }

        let data = require path;
        if data === false {
            unlink(path);
            return;
        }

        return data;
    }

    public function rawDelete(string key) -> void
    {
        var path;

        let path = this->getPath(key);
        if file_exists(path) {
            unlink(path);
        }
    }

    public function set(string key, var value, long lifetime = 0) -> void
    {
        this->rawSet(key, value, lifetime);
    }

    public function get(string key)
    {
        return this->rawGet(key);
    }

    protected function getPath(string key) -> string
    {
        return this->directory . DIRECTORY_SEPARATOR . md5(key) . ".php";
    }
}
