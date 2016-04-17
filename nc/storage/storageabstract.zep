namespace Nc\Storage;

abstract class StorageAbstract implements StorageInterface, UriGeneratorInterface
{
    protected uriGenerator;

    public static function uuid(string salt = "") -> string
    {
        return sha1(uniqid(mt_rand(), true) . salt) . sprintf("%04x", (long) time() & 0xffff);
    }

    public function setUriGenerator(<UriGeneratorInterface> uriGenerator = null) -> void
    {
        let this->uriGenerator = uriGenerator;
    }

    public function getUriGenerator() -> <UriGeneratorInterface>
    {
        return this->uriGenerator;
    }

    public function generateUri(string src, string pre, string ext) -> string
    {
        var uriGenerator;
        string uri = "/", uuid;

        let uriGenerator = this->uriGenerator;
        if typeof uriGenerator == "object" && (uriGenerator instanceof UriGeneratorInterface) {
            return uriGenerator->generateUri(src, pre, ext);
        }

        if pre->length() > 0 {
            if unlikely ! preg_match("#^(\\w+/)*\\w*$#", pre) {
                throw new Exception(sprintf("Invalid uri prefix '%s'", pre));
            }
            let uri .= pre;
        }

        let uuid = (string) self::uuid(src . ext);

        let uri .= uuid[0];
        let uri .= uuid[1];
        let uri .= '/';
        let uri .= uuid[2];
        let uri .= uuid[3];
        let uri .= '/';
        let uri .= uuid;

        if ext->length() > 0 {
            let uri .= "." . ext;
        }

        return uri;
    }

}
