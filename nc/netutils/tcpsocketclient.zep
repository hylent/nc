namespace Nc\NetUtils;

class TcpSocketClient
{
    protected handler;

    public function __construct(array options = []) -> void
    {
        var mergedOptions, host, port, connectTimeout, persistent;
        var address, flags, handler, errNo = null, errStr = null;

        let mergedOptions = options + [
            "host"              : "",
            "port"              : 0,
            "connectTimeout"    : 5,
            "persistent"        : false
        ];

        let host            = (string) mergedOptions["host"];
        let port            = (long) mergedOptions["port"];
        let connectTimeout  = (long) mergedOptions["connectTimeout"];
        let persistent      = (boolean) mergedOptions["persistent"];

        let address = sprintf("tcp://%s:%d", host, port);
        let flags = STREAM_CLIENT_CONNECT;
        if persistent {
            let flags = flags | STREAM_CLIENT_PERSISTENT;
        }

        let handler = stream_socket_client(address, errNo, errStr, connectTimeout, flags);
        if unlikely ! handler {
            throw new TcpSocketClientException(sprintf("Cannot connect to '%s' [%s] %s", address, errNo, errStr));
        }

        let this->handler = handler;
    }

    public function __destruct() -> void
    {
        if this->handler {
            fclose(this->handler);
        }
    }

    public function getInternalHandler()
    {
        return this->handler;
    }

    public function setTcpNodelay(boolean on) -> void
    {
        var socket;

        let socket = socket_import_stream(this->handler);
        if unlikely ! socket {
            throw new TcpSocketClientException("Failed on 'socket_import_stream'");
        }

        if unlikely ! socket_set_option(socket, SOL_TCP, TCP_NODELAY, on ? 1 : 0) {
            throw new TcpSocketClientException("Cannot set SOL_TCP TCP_NODELAY");
        }
    }

    public function setBlocking(boolean on) -> void
    {
        if unlikely ! stream_set_blocking(this->handler, on ? 1 : 0) {
            throw new TcpSocketClientException("Cannot set blocking");
        }
    }

    public function setTimeout(double timeout) -> void
    {
        long seconds, microSeconds;

        if unlikely timeout < 0 {
            throw new TcpSocketClientException("Cannot set timeout to negative value");
        }

        let seconds = (long) timeout;
        let microSeconds = (long) ((timeout - seconds) * 1000000.0);

        if unlikely ! stream_set_timeout(this->handler, seconds, microSeconds) {
            throw new TcpSocketClientException("Failed on 'stream_set_timeout'");
        }
    }

    public function enableCrypto(var cryptoType) -> void
    {
        if unlikely ! stream_socket_enable_crypto(this->handler, true, cryptoType) {
            throw new TcpSocketClientException("Failed on 'stream_socket_enable_crypto'");
        }
    }

    public function write(string data) -> void
    {
        if unlikely fwrite(this->handler, data) === false {
            throw new TcpSocketClientException("Cannot write");
        }
    }

    public function readLine() -> string
    {
        var line;

        let line = fgets(this->handler);
        if unlikely line === false {
            throw new TcpSocketClientException("Cannot read line");
        }

        return line;
    }

    public function readAll() -> string
    {
        var line;

        let line = stream_get_contents(this->handler);
        if unlikely line === false {
            throw new TcpSocketClientException("Cannot read all");
        }

        return line;
    }

    public function readLength(long len) -> string
    {
        var line;

        if unlikely len < 1 {
            throw new TcpSocketClientException(sprintf("Invalid read length '%d'", len));
        }

        let line = stream_get_contents(this->handler, len);
        if unlikely line === false {
            throw new TcpSocketClientException("Cannot read length");
        }

        return line;
    }

    public function readMaxLength(long len) -> string
    {
        var line;

        if unlikely len < 1 {
            throw new TcpSocketClientException(sprintf("Invalid read max length '%d'", len));
        }

        let line = fread(this->handler, len);
        if unlikely line === false {
            throw new TcpSocketClientException("Cannot read max length");
        }

        return line;
    }

}
