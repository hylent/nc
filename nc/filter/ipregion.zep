namespace Nc\Filter;

use Nc\Std;

class IpRegion
{
    const UNIT = 12;

    protected dataPath;
    protected count;
    protected fileHandler;

    public static function packItem(var ip1, var ip2, long region) -> string
    {
        long vip1, vip2;

        let vip1 = (long) ip2long(long2ip(ip1));
        let vip2 = (long) ip2long(long2ip(ip2));

        return pack("NNN", vip1, vip2, region);
    }

    public function __construct(string dataPath = "ipregion.dat") -> void
    {
        long len;

        if unlikely ! file_exists(dataPath) {
            throw new Exception("Invalid data path: " . dataPath);
        }

        let len = (long) filesize(dataPath);
        if unlikely len < self::UNIT {
            throw new Exception("Invalid data file: " . dataPath);
        }

        let this->dataPath = dataPath;
        let this->count = (long) (len / self::UNIT);
    }

    public function count() -> long
    {
        return this->count;
    }

    public function search(string ip) -> long
    {
        var ipLong;

        let ipLong = ip2long(ip);
        if unlikely ipLong === false {
            throw new Exception("Invalid ip: " . ip);
        }

        return this->searchLong(ipLong);
    }

    public function searchLong(var ipLong) -> long
    {
        double ipDouble, i1, i2;
        long high, low, pos;
        var fp, a;

        let ipDouble = (double) Std::ulongToDouble(ipLong);

        let high = (long) this->count;
        let low = 0;

        if this->fileHandler {
            let fp = this->fileHandler;
        } else {
            let fp = fopen(this->dataPath, "r");
            let this->fileHandler = fp;
        }

        loop {
            let pos = (long) ((high + low) / 2);
            if pos - low < 1 {
                break;
            }

            fseek(fp, self::UNIT * pos, SEEK_SET);
            let a = unpack("Ni1/Ni2/Nr", fread(fp, self::UNIT));
            if unlikely ! isset a["i1"] || ! isset a["i2"] || ! isset a["r"] {
                throw new Exception("Cannot read valid data");
            }

            let i1 = (double) Std::ulongToDouble(a["i1"]);
            if (i1 > ipDouble) {
                let high = pos;
                continue;
            }

            let i2 = (double) Std::ulongToDouble(a["i2"]);
            if (i2 >= ipDouble) {
                return (long) a["r"];
            }

            let low = pos;
        }

        return 0;
    }

    public function __destruct() -> void
    {
        if this->fileHandler {
            fclose(this->fileHandler);
        }
    }
}
