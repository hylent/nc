namespace Nc\Upload;

use Nc\Std;

class Ftp extends StorageAbstract
{
    protected ftp;
    protected baseDirectory;

    public function __construct(string host, string user, string passwd, array options = []) -> void
    {
        string baseDirectory;
        long port, timeout;
        bool ssl;
        var ftp;

        let baseDirectory = (string) Std::valueAt(options, "baseDirectory", "");
        let port = (long) Std::valueAt(options, "port", 21);
        let timeout = (long) Std::valueAt(options, "timeout", 10);
        let ssl = (bool) Std::valueAt(options, "ssl", false);

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
            throw new Exception("Cannot connect to ftp server: " . host);
        }

        if unlikely user && ! ftp_login(ftp, user, passwd) {
            throw new Exception("Cannot login ftp server: " . user . "@" . host);
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

    public function store(string source, string prefix = "", string extension = "", long flag = 0) -> string
    {
        string destUri, destPath;

        let destUri = (string) this->generateUri(source, prefix, extension);
        let destPath = this->baseDirectory . destUri;

        this->mkDirIfNotExists(dirname(destPath));

        if ftp_put(this->ftp, destPath, source, FTP_BINARY) {
            switch flag {
                case StorageAbstract::MOVE_UPLOADED_FILE:
                case StorageAbstract::MOVE:
                    unlink(source);
                    break;
            }

            return destUri;
        }

        return "";
    }

    public function remove(string uri) -> bool
    {
        return ftp_delete(this->ftp, uri);
    }

    public function exists(string uri) -> bool
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

        set_error_handler(Std::IGNORE_ERROR);

        while parts {
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
