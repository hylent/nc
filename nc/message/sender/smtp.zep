namespace Nc\Message\Sender;

class Smtp implements MessageSenderInterface
{
    const EOL = "\r\n";

    protected socket;
    protected from;
    protected sender;
    protected preSubject;

    public function __construct(string host, string port, string user, string passwd, string from,
        string sender = "", string preSubject = "") -> void
    {
        var socket;

        if unlikely user->length() < 1 || passwd->length() < 1 {
            throw new Exception("Empty user or passwd");
        }

        let socket = fsockopen(host, port, null, null, 30);
        if unlikely ! socket || ! stream_set_blocking(socket, 1) {
            throw new Exception("Cannot connect or set blocking to " . host . ":" . port);
        }

        let this->socket = socket;

        this->doCommand("CONNECT", "", 220);
        this->doCommand("EHLO HELO", "EHLO HELO", 250);
        this->doCommand("AUTH LOGIN", "AUTH LOGIN", 334);
        this->doCommand("AUTH USER", base64_encode(user), 334);
        this->doCommand("AUTH PASSWD", base64_encode(passwd), 235);

        let this->from = from;

        if sender {
            let this->sender = "=?UTF-8?B?" . base64_encode(sender) . "?= <" . from . ">";
        } else {
            let this->sender = from;
        }

        if preSubject {
            let this->preSubject = preSubject;
        } else {
            if sender {
                let this->preSubject = "[" . sender . "]";
            } else {
                let this->preSubject = "";
            }
        }
    }

    public function __destruct() -> void
    {
        try {
            this->doCommand("QUIT", "QUIT", 221);
        }

        fclose(this->socket);
    }

    public function send(string to, string subject, string message) -> void
    {
        var lines = [];

        let lines[] = "Content-type: text/html; charset=UTF-8";
        let lines[] = "Content-Transfer-Encoding: base64";
        let lines[] = "From: " . this->sender;
        let lines[] = "To: " . to;
        let lines[] = "Subject: " . this->preSubject . subject;
        let lines[] = "Date: " . gmdate("r");
        let lines[] = "MIME-Version: 1.0";
        let lines[] = "Message-ID: " . md5(uniqid(mt_rand(), true));
        let lines[] = "X-Priority: 3";
        let lines[] = "X-Mailer: nc";
        let lines[] = "";
        let lines[] = chunk_split(base64_encode(message)) . ".";

        this->doCommand("MAIL FROM", "MAIL FROM: <" . this->from . ">", 250);
        this->doCommand("RCPT TO", "RCPT TO: <" . to . ">", 250);
        this->doCommand("DATA", "DATA", 354);
        this->doCommand("END DATA", (string) join(self::EOL, lines), 250);
    }

    protected function doCommand(string step, string command, string validResult) -> void
    {
        string output;

        if unlikely command && ! fputs(this->socket, command . self::EOL) {
            throw new Exception("Cannot do command: " . step);
        }

        let output = (string) rtrim(fread(this->socket, 1024));

        if unlikely validResult && strpos(output, validResult) !== 0 {
            throw new Exception("Invalid command result: " . step . ", with output: " . output);
        }
    }
}
