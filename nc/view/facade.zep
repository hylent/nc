namespace Nc\View;

use Nc\Factory\Namespaced;

class Facade implements \ArrayAccess
{
    protected options;
    protected data;
    protected view;

    public function __construct(array options = [], array data = [], var view = null) -> void
    {
        let this->options = options;
        let this->data = data;
        let this->view = view;
    }

    public function content(var content = null, var contentType = null) -> void
    {
        let this->view = __FUNCTION__;

        if content !== null {
            let this->options["content"] = content;
        }
        if contentType !== null {
            let this->options["contentType"] = contentType;
        }
    }

    public function httpResponse(var httpResponseCode = null, var httpResponseContent = null) -> void
    {
        let this->view = __FUNCTION__;

        if httpResponseCode !== null {
            let this->options["httpResponseCode"] = httpResponseCode;
        }
        if httpResponseContent !== null {
            let this->options["httpResponseContent"] = httpResponseContent;
        }
    }

    public function json(var jsonCallback = null, var jsonCors = null) -> void
    {
        let this->view = __FUNCTION__;

        if jsonCallback !== null {
            let this->options["jsonCallback"] = jsonCallback;
        }
        if jsonCors !== null {
            let this->options["jsonCors"] = jsonCors;
        }
    }

    public function nil() -> void
    {
        let this->view = __FUNCTION__;
    }

    public function readFile(var readFile = null) -> void
    {
        let this->view = __FUNCTION__;

        if readFile !== null {
            let this->options["readFile"] = readFile;
        }
    }

    public function redirect(var redirectUrl = null, var redirectDataAsQueries = null) -> void
    {
        let this->view = __FUNCTION__;

        if redirectUrl !== null {
            let this->options["redirectUrl"] = redirectUrl;
        }
        if redirectDataAsQueries !== null {
            let this->options["redirectDataAsQueries"] = redirectDataAsQueries;
        }
    }

    public function tpl(var tplId = null, var layoutId = null) -> void
    {
        let this->view = __FUNCTION__;

        if tplId !== null {
            let this->options["tplId"] = tplId;
        }
        if layoutId !== null {
            let this->options["layoutId"] = layoutId;
        }
    }

    public function setView(var view) -> void
    {
        let this->view = view;
    }

    public function getView()
    {
        return this->view;
    }

    public function __invoke() -> void
    {
        var view;

        loop {
            let view = this->view;

            if typeof view == "object" {
                if (view instanceof \Closure) {
                    let view = {view}();
                }
                break;
            }

            let view = (string) view;

            if strpos(view, "\\") === false {
                let view = (new Namespaced(__NAMESPACE__))->__get(view);
                break;
            }

            let view = (new Namespaced(""))->__get(view);
            break;
        }

        if unlikely typeof view != "object" || ! (view instanceof ViewInterface) {
            throw new Exception("Invalid view");
        }

        view->run(this->data, this->options);
    }

    public function setOptions(array options) -> void
    {
        var k, v;

        for k, v in options {
            let this->options[k] = v;
        }
    }

    public function getOptions() -> array
    {
        return this->options;
    }

    public function __set(string key, var value) -> void
    {
        let this->options[key] = value;
    }

    public function __get(string key)
    {
        var value;

        if fetch value, this->options[key] {
            return value;
        }
    }

    public function __isset(string key) -> bool
    {
        return isset this->options[key];
    }

    public function __unset(string key) -> void
    {
        unset this->options[key];
    }

    public function setData(array data) -> void
    {
        var k, v;

        for k, v in data {
            let this->data[k] = v;
        }
    }

    public function getData() -> array
    {
        return this->data;
    }

    public function offsetSet(string key, var value) -> void
    {
        let this->data[key] = value;
    }

    public function offsetGet(string key)
    {
        var value;

        if fetch value, this->data[key] {
            return value;
        }
    }

    public function offsetExists(string key) -> bool
    {
        return isset this->data[key];
    }

    public function offsetUnset(string key) -> void
    {
        unset this->data[key];
    }

}
