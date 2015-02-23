namespace Nc;

class Std
{
    const CHAR_LIST = "0123456789abcdefghijklmnopqrstuvwxyz";

    const IGNORE_ERROR = "Nc\\Std::ignoreError";
    const THROW_ERROR = "Nc\\Std::throwError";

    public static function sizeToByte(string size) -> double
    {
        var match = null;

        if preg_match("/^([\\d\\.]+)([KMGT])B?$/", size->upper(), match) {
            switch match[2] {
                case "T":
                    return 1099511627776.0 * (double) match[1];
                case "G":
                    return 1073741824.0 * (double) match[1];
                case "M":
                    return 1048576.0 * (double) match[1];
                case "K":
                    return 1024.0 * (double) match[1];
            }
        }

        return floatval(size);
    }

    public static function uuid(string salt = "") -> string
    {
        return md5(uniqid(mt_rand(), true) . salt);
    }

    public static function randString(long len, string charList = "") -> string
    {
        string result = "";
        long maxIndex;

        if unlikely len < 1 {
            return "";
        }

        if charList->length() < 1 {
            let charList = self::CHAR_LIST;
        }

        let maxIndex = (long) mb_strlen(charList, "utf-8") - 1;

        while len {
            let len--;
            let result .= mb_substr(charList, mt_rand(0, maxIndex), 1, "utf-8");
        }

        return result;
    }

    public static function camelCase(string from, boolean upper = false) -> string
    {
        string to = "";
        var c;

        for c in str_split(from) {
            if c == " " || c == "_" || c == "-" {
                let upper = true;
                continue;
            }

            if upper {
                let to .= strtoupper(c);
                let upper = false;
                continue;
            }

            let to .= strtolower(c);
        }

        return to;
    }

    public static function uncamelCase(string from, string sep = "-") -> string
    {
        return strtolower(preg_replace("/([A-Z])/", sep . "$1", lcfirst(from)));
    }

    public static function valueOfArray(array data, string key, var defaultValue = null)
    {
        var parts, part, value, tmpValue;

        let parts = explode(".", key);
        let value = data;

        for part in parts {
            if typeof value != "array" || ! fetch tmpValue, value[part] {
                return defaultValue;
            }
            let value = tmpValue;
        }

        return value;
    }

    public static function indexedData(array data, string indexKey) -> array
    {
        var k, v, arr = [], indexValue;

        for k, v in data {
            if unlikely typeof v != "array" {
                throw new Exception("Invalid item type, array required: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new Exception("Cannot find value of index at: " . k);
            }

            let arr[indexValue] = v;
        }

        return arr;
    }

    public static function indexedValues(array data, string indexKey, string valueKey) -> array
    {
        var k, v, arr = [], indexValue, valueValue;

        for k, v in data {
            if unlikely typeof v != "array" {
                throw new Exception("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new Exception("Cannot find value of index at: " . k);
            }
            if unlikely ! fetch valueValue, v[valueKey] {
                throw new Exception("Cannot find value of value at: " . k);
            }

            let arr[indexValue] = valueValue;
        }

        return arr;
    }

    public static function groupedData(array data, string groupKey) -> array
    {
        var k, v, arr = [], groupValue;

        for k, v in data {
            if unlikely typeof v != "array" {
                throw new Exception("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new Exception("Cannot find value of group at: " . k);
            }

            let arr[groupValue][] = v;
        }

        return arr;
    }

    public static function groupedValues(array data, string groupKey, string valueKey) -> array
    {
        var k, v, arr = [], groupValue, valueValue;

        for k, v in data {
            if unlikely typeof v != "array" {
                throw new Exception("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new Exception("Cannot find value of group at: " . k);
            }
            if unlikely ! fetch valueValue, v[valueKey] {
                throw new Exception("Cannot find value of value at: " . k);
            }

            let arr[groupValue][] = valueValue;
        }

        return arr;
    }

    public static function groupIndexedData(array data, string groupKey, string indexKey) -> array
    {
        var k, v, arr = [], groupValue, indexValue;

        for k, v in data {
            if unlikely typeof v != "array" {
                throw new Exception("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new Exception("Cannot find value of group at: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new Exception("Cannot find value of index at: " . k);
            }

            let arr[groupValue][indexValue] = v;
        }

        return arr;
    }

    public static function groupIndexedValues(array data, string groupKey, string indexKey, string valueKey) -> array
    {
        var k, v, arr = [], groupValue, indexValue, valueValue;

        for k, v in data {
            if unlikely typeof v != "array" {
                throw new Exception("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new Exception("Cannot find value of group at: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new Exception("Cannot find value of index at: " . k);
            }
            if unlikely ! fetch valueValue, v[valueKey] {
                throw new Exception("Cannot find value of value at: " . k);
            }

            let arr[groupValue][indexValue] = valueValue;
        }

        return arr;
    }

    public static function uniqueValues(array data, string uniqueKey) -> array
    {
        var k, v, arr = [], uniqueValue;

        for k, v in data {
            if unlikely typeof v != "array" {
                throw new Exception("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch uniqueValue, v[uniqueKey] {
                throw new Exception("Cannot find value of unique at: " . k);
            }

            let arr[uniqueValue] = null;
        }

        return array_keys(arr);
    }

    public static function newInstanceOf(string className, array args = null)
    {
        long c;
        var a;

        let c = count(args);
        if c < 1 {
            return new {className}();
        }
        if c > 5 {
            return (new \ReflectionClass(className))->newInstanceArgs(args);
        }

        let a = array_values(args);
        switch c {
            case 1:
                return new {className}(a[0]);
            case 2:
                return new {className}(a[0], a[1]);
            case 3:
                return new {className}(a[0], a[1], a[2]);
            case 4:
                return new {className}(a[0], a[1], a[2], a[3]);
            case 5:
                return new {className}(a[0], a[1], a[2], a[3], a[4]);
        }

        throw new Exception("Fail to fetch a new instance of class: " . className);
    }

    public static function ignoreError(long n, string s, string f, string l, array context = null) -> void
    {
        return;
    }

    public static function throwError(long n, string s, string f, string l, array context = null) -> void
    {
        throw new \ErrorException(s . " (" . f . ":" . l . ")", n);
    }

    public static function outputScript(string path, array data) -> void
    {
        if unlikely ! file_exists(path) {
            throw new Exception("Cannot find script path: " . path);
        }

        extract(data, EXTR_PREFIX_INVALID, "");
        require path;
    }

    public static function renderScript(string path, array data) -> string
    {
        var ex;

        ob_start();
        ob_implicit_flush(false);

        try {
            self::outputScript(path, data);
            return ob_get_clean();
        } catch \Exception, ex {
            ob_end_clean();
            throw ex;
        }

        return "";
    }
}
