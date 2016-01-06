namespace Nc\Storage;

use Nc\Std;

abstract class StorageAbstract
{
    const COPY                  = 0;
    const MOVE                  = 1;
    const MOVE_UPLOADED_FILE    = 2;

    protected uriGenerator;

    public function setUriGenerator(<\Closure> uriGenerator) -> void
    {
        let this->uriGenerator = uriGenerator;
    }

    public function getUriGenerator() -> <\Closure>
    {
        return this->uriGenerator;
    }

    public function generateUri(string source, string prefix, string extension) -> string
    {
        string uri = "/", uuid;

        if this->uriGenerator {
            return call_user_func(this->uriGenerator, source, prefix, extension);
        }

        if prefix->length() > 0 {
            if unlikely ! preg_match("#^(\\w+/)*\\w*$#", prefix) {
                throw new Exception("Invalid prefix: " . prefix);
            }
            let uri .= prefix;
        }

        let uuid = (string) Std::uuid(source . extension);

        let uri .= uuid[0];
        let uri .= uuid[1];
        let uri .= '/';
        let uri .= uuid[2];
        let uri .= uuid[3];
        let uri .= '/';
        let uri .= uuid;

        if extension->length() > 0 {
            let uri .= "." . extension;
        }

        return uri;
    }

    abstract public function store(string source, string prefix = "", string extension = "", long flag = 0) -> string;
    abstract public function remove(string uri) -> bool;
    abstract public function exists(string uri) -> bool;

}
