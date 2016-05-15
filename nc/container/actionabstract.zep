namespace Nc\Container;

abstract class ActionAbstract
{
    public static function camelCase(string input, boolean upper = false) -> string
    {
        string output = "";
        char c;

        for c in input {
            if c >= 'a' && c <= 'z' {
                if upper {
                    let upper = false;
                    let c -= 32;
                }
                let output .= c;
                continue;
            }

            if c >= 'A' && c <= 'Z' {
                if upper {
                    let upper = false;
                } else {
                    let c += 32;
                }
                let output .= c;
                continue;
            }

            if c >= '0' && c <= '9' {
                if upper {
                    let upper = false;
                }
                let output .= c;
                continue;
            }

            let upper = true;
        }

        return output;
    }

    public static function run(<ContainerInterface> container, var args = null) -> void
    {
        while args && typeof args == "array" {
            let args = call_user_func_array(container->__get(self::camelCase(array_shift(args))), args);
        }
    }

    public function __invoke()
    {
        var args, s, method = "any";

        let args = func_get_args();
        if fetch s, args[0] {
            let s = (string) s;
            if strlen(s) > 0 {
                let s = "on" . self::camelCase(s, true);
                if method_exists(this, s) {
                    let method = s;
                    array_shift(args);
                }
            }
        }

        return call_user_func_array([this, method], args);
    }

    protected function any()
    {
        throw new Exception("Unaccomplished");
    }

}
