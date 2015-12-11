namespace Nc;

class Std
{
    const CHARSET       = "UTF-8";
    const CHAR_LIST     = "0123456789abcdefghijklmnopqrstuvwxyz";

    const IGNORE_ERROR  = "Nc\\Std::ignoreError";
    const THROW_ERROR   = "Nc\\Std::throwError";

    public static function sizeToBytes(string size) -> double
    {
        var match = null;
        string unit;

        if preg_match("/^([\\d\\.]+)([KMGT])B?$/", size->upper(), match) {
            let unit = (string) match[2];
            switch unit[0] {
                case 'T':
                    return 1099511627776.0 * (double) match[1];
                case 'G':
                    return 1073741824.0 * (double) match[1];
                case 'M':
                    return 1048576.0 * (double) match[1];
                case 'K':
                    return 1024.0 * (double) match[1];
            }
        }

        return floatval(size);
    }

    public static function bytesToSize(double bytes, long decimal = 3) -> string
    {
        string size = "0";

        if decimal < 0 || decimal > 6 {
            let decimal = 3;
        }

        if bytes > 1099511627776.0 {
            return sprintf(sprintf("%%0.%dfT", decimal), bytes / 1099511627776.0);
        }
        if bytes > 1073741824.0 {
            return sprintf(sprintf("%%0.%dfG", decimal), bytes / 1073741824.0);
        }
        if bytes > 1048576.0 {
            return sprintf(sprintf("%%0.%dfM", decimal), bytes / 1048576.0);
        }
        if bytes > 1024.0 {
            return sprintf(sprintf("%%0.%dfK", decimal), bytes / 1024.0);
        }
        if bytes > 1.0 {
            return sprintf(sprintf("%%0.%dfB", decimal), bytes);
        }

        return size;
    }

    public static function pascalCase(string from) -> string
    {
        string to = "";
        char c;
        bool found = false;
        bool upper = true;

        for c in from {
            if c >= '0' && c <= '9' {
                if found {
                    let to .= c;
                }
                continue;
            }
            if c >= 'a' && c <= 'z' {
                if upper {
                    let upper = false;
                    let c -= 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if c >= 'A' && c <= 'Z' {
                if upper {
                    let upper = false;
                } else {
                    let c += 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if found {
                let upper = true;
            }
        }

        return to;
    }

    public static function camelCase(string from) -> string
    {
        string to = "";
        char c;
        bool found = false;
        bool upper = false;

        for c in from {
            if c >= '0' && c <= '9' {
                if found {
                    let to .= c;
                }
                continue;
            }
            if c >= 'a' && c <= 'z' {
                if upper {
                    let upper = false;
                    let c -= 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if c >= 'A' && c <= 'Z' {
                if upper {
                    let upper = false;
                } else {
                    let c += 32;
                }
                let to .= c;
                let found = true;
                continue;
            }
            if found {
                let upper = true;
            }
        }

        return to;
    }

    public static function normalCase(string from, string sep = "-") -> string
    {
        string to = "";
        char c;
        bool found = false;

        for c in from {
            if (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') {
                let to .= c;
                let found = true;
                continue;
            }
            if c >= 'A' && c <= 'Z' {
                if found {
                    let to .= sep;
                }
                let c += 32;
                let to .= c;
                let found = true;
                continue;
            }
        }

        return to;
    }

    public static function uuid(string salt = "") -> string
    {
        return sha1(uniqid(mt_rand(), true) . salt) . sprintf("%04x", (long) time() & 0xffff);
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

        let maxIndex = (long) mb_strlen(charList, self::CHARSET) - 1;

        while len {
            let len--;
            let result .= mb_substr(charList, mt_rand(0, maxIndex), 1, self::CHARSET);
        }

        return result;
    }

    public static function tr(string message, array context = []) -> string
    {
        var k, v, r = [];

        for k, v in context {
            let r["{" . k . "}"] = (string) v;
        }

        return strtr(message, r);
    }

    public static function valueAt(array arr, string key, var defaultValue = null, bool noException = false)
    {
        var value;

        if fetch value, arr[key] {
            return value;
        }

        if unlikely defaultValue === null && ! noException {
            throw new Exception("Missing value at: " . key);
        }

        return defaultValue;
    }

    public static function valueOf(array arr, string key, var defaultValue = null)
    {
        var parts, part, returnValue, tmpValue;

        let parts = explode(".", key);
        let returnValue = arr;

        for part in parts {
            if typeof returnValue != "array" || ! fetch tmpValue, returnValue[part] {
                return defaultValue;
            }
            let returnValue = tmpValue;
        }

        return returnValue;
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
        throw new \ErrorException(sprintf("%s (%s:%d)", s, f, l), n);
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
