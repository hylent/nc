namespace Nc\Storage;

class Ftp extends StorageAbstract
{
    protected ftp;
    protected baseDirectory;

    public static function ignoreError(long n, string s, string f, string l, array context = null) -> void
    {
        return;
    }

    public function __construct(string host, string user, string passwd, array options = []) -> void
    {
        var o, ftp;
        string baseDirectory = "";
        long port = 21, timeout = 10;
        boolean ssl = false;

        if fetch o, options["baseDirectory"] {
            let baseDirectory = (string) o;
        }
        if fetch o, options["port"] {
            let port = (long) o;
        }
        if fetch o, options["timeout"] {
            let timeout = (long) o;
        }
        if fetch o, options["ssl"] {
            let ssl = (boolean) o;
        }

        if ssl {
            if unlikely ! function_exists("ftp_ssl_connect") {
                throw new Exception("Missing ssl ftp support");
            }

            let ftp = ftp_ssl_connect(host, port, timeout);
        } else {
            if unlikely ! function_exists("ftp_connect") {
                throw new Exception("Missing ftp support");
            }

            let ftp = ftp_connect(host, port, timeout);
        }

        if unlikely ! ftp {
            throw new Exception(sprintf("Cannot connect to ftp server '%s'", host));
        }

        if unlikely user && ! ftp_login(ftp, user, passwd) {
            throw new Exception(sprintf("Cannot login ftp server '%s@%s'", user, host));
        }

        if unlikely ! ftp_pasv(ftp, true) {
            throw new Exception("Cannot set PASV mode");
        }

        let this->ftp = ftp;
        let this->baseDirectory = baseDirectory;
    }

    public function getInternalHandler()
    {
        return this->ftp;
    }

    public function getBaseDirectory() -> string
    {
        return this->baseDirectory;
    }

    public function store(string src, string pre = "", string ext = "", long type = 0) -> string
    {
        string destUri, destPath;

        let destUri = (string) this->generateUri(src, pre, ext);
        let destPath = this->baseDirectory . destUri;

        this->mkDirIfNotExists(dirname(destPath));

        if unlikely ! ftp_put(this->ftp, destPath, src, FTP_BINARY) {
            throw new Exception("Cannot store file to: " . destPath);
        }

        switch type {
            case StorageAbstract::MOVE_UPLOADED_FILE:
            case StorageAbstract::MOVE:
                unlink(src);
                break;
        }

        return destUri;
    }

    public function remove(string uri) -> boolean
    {
        return ftp_delete(this->ftp, uri);
    }

    public function exists(string uri) -> boolean
    {
        return ftp_mdtm(this->ftp, uri) !== -1;
    }

    public function __destruct() -> void
    {
        ftp_close(this->ftp);
    }

    protected function mkDirIfNotExists(string dir) -> void
    {
        var ftp, parts, cur, stack = [];

        let ftp = this->ftp;
        let parts = preg_split("#/+#", dir, -1, PREG_SPLIT_NO_EMPTY);

        set_error_handler(__CLASS__ . "::ignoreError");

        while count(parts) > 0 {
            let cur = "/" . join("/", parts);
            if ! ftp_chdir(ftp, cur) {
                let stack[] = cur;
            }
            array_pop(parts);
        }

        restore_error_handler();

        for cur in reverse stack {
            ftp_mkdir(ftp, cur);
        }
    }

}
