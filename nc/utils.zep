namespace Nc;

class Utils
{
    public static function crc16(string str) -> long
    {
        return nc_utils_crc16(str);
    }

    public static function serial() -> long
    {
        return nc_utils_serial();
    }

}
