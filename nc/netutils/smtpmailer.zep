namespace Nc\NetUtils;

use Nc\Std;

class SmtpMailer
{
    const CRLF = "\r\n";

    protected socket;
    protected from;

    public function __construct(array options) -> void
    {
        string host, user, passwd, from, name;
        long port, connectTimeout;
        double timeout;
        bool secure;
        var socket;

        let host = (string) Std::valueAt(options, "host");
        let user = (string) Std::valueAt(options, "user");
        let passwd = (string) Std::valueAt(options, "passwd");

        let from = (string) Std::valueAt(options, "from", user);
        let name = (string) Std::valueAt(options, "name", "");
        let connectTimeout = (long) Std::valueAt(options, "connectTimeout", 10);
        let timeout = (double) Std::valueAt(options, "timeout", 5);
        let secure = (bool) Std::valueAt(options, "secure", false);

        if secure {
            let port = (long) Std::valueAt(options, "port", 465);
        } else {
            let port = (long) Std::valueAt(options, "port", 25);
        }

        let socket = new TcpSocketClient(host, port, connectTimeout, false);

        socket->setTcpNodelay(true);
        socket->setBlocking(true);

        if timeout > 0 {
            socket->setTimeout(timeout);
        }
        if secure {
            socket->enableCrypto(constant("STREAM_CRYPTO_METHOD_SSLv23_CLIENT"));
        }

        let this->socket = socket;
        let this->from = this->pack(name, from);

        this->cmd("CONNECT", "", 220);
        this->cmd("EHLO HELO", "EHLO HELO", 250);
        this->cmd("AUTH LOGIN", "AUTH LOGIN", 334);
        this->cmd("AUTH USER", base64_encode(user), 334);
        this->cmd("AUTH PASSWD", base64_encode(passwd), 235);
    }

    public function getSocket()
    {
        return this->socket;
    }

    public function sendMessageTo(array message, array to, array cc = [], array bcc = []) -> void
    {
        var data = [], recievers, addr, name, subject, plain, body, attachments, path;
        string boundary;

        this->cmd("MAIL FROM", "MAIL FROM: " . this->from, 250);
        let data[] = "FROM: " . this->from;

        if count(to) < 1 {
            throw new Exception("No recievers to send to");
        }

        let recievers = [];
        for addr, name in to {
            let name = this->pack(name, addr);
            this->cmd("RCPT TO", "RCPT TO: " . name, 250);
            let recievers[] = name;
        }
        let data[] = "TO: " . join(",", recievers);

        if count(cc) > 0 {
            let recievers = [];
            for addr, name in cc {
                let name = this->pack(name, addr);
                this->cmd("RCPT TO", "RCPT TO: " . name, 250);
                let recievers[] = name;
            }
            let data[] = "CC: " . join(",", recievers);
        }
        if count(bcc) > 0 {
            let recievers = [];
            for addr, name in bcc {
                let name = this->pack(name, addr);
                this->cmd("RCPT TO", "RCPT TO: " . name, 250);
                let recievers[] = name;
            }
            let data[] = "BCC: " . join(",", recievers);
        }

        let boundary = "----Boundary-" . Std::uuid();

        if fetch subject, message["subject"] {
            let data[] = "Subject: " . this->pack(subject);
        }
        let data[] = "Mime-Version: 1.0";
        let data[] = "Content-Type: multipart/mixed; boundary=\"" . boundary . "\"";
        let data[] = "Content-Transfer-Encoding: 8Bit";
        let data[] = "Date: " . gmdate("r");
        let data[] = "";
        let data[] = "This is a multi-part message in MIME format!";
        let data[] = "";

        let boundary = "--" . boundary;

        let data[] = boundary;
        if fetch plain, message["plain"] && plain {
            let data[] = "Content-Type: text/plain; charset=UTF-8";
        } else {
            let data[] = "Content-Type: text/html; charset=UTF-8";
        }
        let data[] = "Content-Transfer-Encoding: base64";
        let data[] = "";
        if fetch body, message["body"] {
            let body = (string) body;
        } else {
            let body = " ";
        }
        let data[] = chunk_split(base64_encode(body));
        let data[] = "";

        if fetch attachments, message["attachments"] && typeof attachments == "array" && count(attachments) > 0 {
            for path in attachments {
                if unlikely ! file_exists(path) {
                    throw new Exception("Cannot find attachment: " . path);
                }
                let data[] = boundary;
                let data[] = "Content-Type: application/octet-stream";
                let data[] = "Content-Disposition: attachment; filename=\"" . this->pack(basename(path)) . "\"";
                let data[] = "Content-Transfer-Encoding: base64";
                let data[] = "";
                let data[] = chunk_split(base64_encode(file_get_contents(path)));
                let data[] = "";
            }
        }

        let boundary .= "--";

        let data[] = boundary;
        let data[] = ".";

        this->cmd("DATA", "DATA", 354);
        this->cmd("END DATA", join(self::CRLF, data), 250);
    }

    public function __destruct() -> void
    {
        try {
            this->cmd("QUIT", "QUIT", 221);
        }
    }

    protected function cmd(string step, string cmd, string expected) -> void
    {
        string output;

        if cmd->length() > 0 {
            this->socket->write(cmd . self::CRLF);
        }

        let output = (string) rtrim(this->socket->readMaxLength(1024));

        if expected->length() > 0 && strpos(output, expected) !== 0 {
            throw new Exception("Unexpected response on step: " . step . ", with output: " . output);
        }
    }

    protected function pack(string name = "", string addr = "") -> string
    {
        string s = "";

        if name->length() > 0 {
            let s .= "=?UTF-8?B?" . base64_encode(name) . "?=";
        }
        if addr->length() > 0 {
            let s .= "<" . addr . ">";
        }

        return s;
    }

}
