namespace Nc\Storage;

use Nc\Std;

class Ftp extends StorageAbstract
{
    protected ftp;
    protected baseDirectory;

    public function __construct(string host, string user, string passwd, string baseDirectory = "",
        long port = 0, long timeout = 30, boolean ssl = false) -> void
    {
        var ftp;

        if unlikely ! function_exists("ftp_connect") {
            throw new Exception("Missing ftp support");
        }

        if ssl {
            let ftp = ftp_ssl_connect(host, port, timeout);
        } else {
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

    public function store(string source, string group = "", string extension = "", boolean rm = false) -> string
    {
        string destUri, destPath;

        let destUri = (string) this->generateUri(source, group, extension);
        let destPath = this->baseDirectory . destUri;

        this->mkDirIfNotExists(dirname(destPath));

        if ftp_put(this->ftp, destPath, source, FTP_BINARY) {
            if rm {
                unlink(source);
            }

            return destUri;
        }

        return "";
    }

    public function remove(string uri) -> boolean
    {
        return ftp_delete(this->ftp, uri);
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
