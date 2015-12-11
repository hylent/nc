namespace Nc\Logger;

class Backends extends LoggerAbstract
{
    protected globalBackends;
    protected backends;

    public function addBackend(<LoggerBackendInterface> backend, string level = "") -> void
    {
        string h;
        var lev;

        let h = (string) spl_object_hash(backend);

        if level->length() < 1 {
            let this->globalBackends[h] = backend;
            return;
        }

        for lev in preg_split("@[,/\\|]+@", level, PREG_SPLIT_NO_EMPTY) {
            let this->backends[lev][h] = backend;
        }
    }


    public function log(string level, string message, array context = []) -> void
    {
        var backends, backend;

        let backends = this->globalBackends;
        if typeof backends == "array" {
            for backend in backends {
                backend->log(level, message, context);
            }
        }

        if fetch backends, this->backends[level] && typeof backends == "array" {
            for backend in backends {
                backend->log(level, message, context);
            }
        }
    }

}
