namespace Nc\NetUtils;

class Smtp
{
    const CRLF = "\r\n";

    protected tcpSocketClient;
    protected sender;
    protected namedSender;

    public static function pack(string name = "", string addr = "") -> string
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

    public function __construct(string host, string user, string passwd, array options = []) -> void
    {
        var o, port = 25, connectTimeout = 10, timeout = 5.0, from, name, tcpSocketClient;
        int secure = 0;

        if fetch o, options["port"] {
            let port = (long) o;
        }

        if fetch o, options["connectTimeout"] {
            let connectTimeout = (long) o;
        }
        if fetch o, options["timeout"] {
            let timeout = (double) o;
        }
        if fetch o, options["secure"] && o {
            let secure = 1;
            if o === "tls" {
                let secure = 2;
            }
        }

        if fetch o, options["name"] {
            let name = (string) o;
        } else {
            let name = "";
        }
        if fetch o, options["from"] {
            let from = (string) o;
        } else {
            let from = user;
        }

        let this->sender = self::pack("", from);
        let this->namedSender = self::pack(name, from);

        let tcpSocketClient = new TcpSocketClient(host, port, connectTimeout, false);
        let this->tcpSocketClient = tcpSocketClient;

        tcpSocketClient->setTcpNodelay(true);
        tcpSocketClient->setBlocking(true);

        if timeout > 0 {
            tcpSocketClient->setTimeout(timeout);
        }

        if secure == 1 {
            tcpSocketClient->enableCrypto(constant("STREAM_CRYPTO_METHOD_SSLv23_CLIENT"));
        }

        this->cmd("CONNECT", "", "220");
        this->cmd("EHLO HELO", "EHLO HELO", "250");

        if secure == 2 {
            this->cmd("STARTTLS", "STARTTLS", "220");
            tcpSocketClient->enableCrypto(STREAM_CRYPTO_METHOD_TLS_CLIENT);
            this->cmd("EHLO HELO", "EHLO HELO", "250");
        }

        this->cmd("AUTH LOGIN", "AUTH LOGIN", "334");
        this->cmd("AUTH USER", base64_encode(user), "334");
        this->cmd("AUTH PASSWD", base64_encode(passwd), "235");
    }

    public function getTcpSocketClient() -> <TcpSocketClient>
    {
        return this->tcpSocketClient;
    }

    public function sendMessageTo(array message, array to, array cc = [], array bcc = []) -> void
    {
        var data = [], recievers, addr, name, subject, plain, body, attachments, path;
        string boundary;

        this->cmd("MAIL FROM", "MAIL FROM: " . this->sender, "250");
        let data[] = "FROM: " . this->namedSender;

        if unlikely count(to) < 1 {
            throw new SmtpException("No recievers to send to");
        }

        let recievers = [];
        for addr, name in to {
            this->cmd("RCPT TO", "RCPT TO: " . self::pack("", addr), "250");
            let recievers[] = self::pack(name, addr);
        }
        let data[] = "TO: " . join(",", recievers);

        if count(cc) > 0 {
            let recievers = [];
            for addr, name in cc {
                this->cmd("RCPT TO", "RCPT TO: " . self::pack("", addr), "250");
                let recievers[] = self::pack(name, addr);
            }
            let data[] = "CC: " . join(",", recievers);
        }
        if count(bcc) > 0 {
            let recievers = [];
            for addr, name in bcc {
                this->cmd("RCPT TO", "RCPT TO: " . self::pack("", addr), "250");
                let recievers[] = self::pack(name, addr);
            }
            let data[] = "BCC: " . join(",", recievers);
        }

        let boundary = "----Boundary-" . md5(uniqid(mt_rand(), true));

        if fetch subject, message["subject"] {
            let data[] = "Subject: " . self::pack(subject);
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
                    throw new SmtpException(sprintf("Cannot find attachment '%s'", path));
                }
                let data[] = boundary;
                let data[] = "Content-Type: application/octet-stream";
                let data[] = "Content-Disposition: attachment; filename=\"" . self::pack(basename(path)) . "\"";
                let data[] = "Content-Transfer-Encoding: base64";
                let data[] = "";
                let data[] = chunk_split(base64_encode(file_get_contents(path)));
                let data[] = "";
            }
        }

        let boundary .= "--";

        let data[] = boundary;
        let data[] = ".";

        this->cmd("DATA", "DATA", "354");
        this->cmd("END DATA", join(self::CRLF, data), "250");
    }

    public function __destruct() -> void
    {
        try {
            this->cmd("QUIT", "QUIT", "221");
        }
    }

    protected function cmd(string step, string cmd, string expected) -> void
    {
        string output;

        if cmd->length() > 0 {
            this->tcpSocketClient->write(cmd . self::CRLF);
        }

        let output = (string) rtrim(this->tcpSocketClient->readMaxLength(1024));

        if unlikely expected->length() > 0 && strpos(output, expected) !== 0 {
            throw new SmtpException(sprintf("Unexpected response '%s' on step '%s'", output, step));
        }
    }

}
