namespace Nc\Router;

class SourceUriPatterns extends SourceUri
{
    const DEFAULT_PATTERN = "\w+";

    protected typePatterns;
    protected replacements;

    public function __construct(string uri, array rules = [], array typePatterns = []) -> void
    {
        var callback, prefix, aliasGroup, from, to, repls = [];

        if count(rules) > 0 {
            let this->typePatterns = typePatterns;

            let callback = [this, "onPregReplaceCallback"];

            for prefix, aliasGroup in rules {
                if unlikely typeof aliasGroup != "array" {
                    throw new Exception("Invalid alias group for prefix: " . prefix);
                }

                let prefix = (string) prefix;
                if strlen(prefix) > 0 {
                    let prefix = preg_quote(prefix, "#");
                }

                for from, to in aliasGroup {
                    let this->replacements = [];

                    let from = sprintf(
                        "#^%s%s($|[/\?])#",
                        prefix,
                        preg_replace_callback("#/\\{(\\w+)(\\:\\w+)?\\}#", callback, (string) from)
                    );

                    let to = sprintf(
                        "%s%s${%d}",
                        prefix,
                        strtr((string) to, this->replacements),
                        count(this->replacements) + 1
                    );

                    let repls[from] = to;
                }
            }

            if count(repls) > 0 {
                let uri = (string) preg_replace(array_keys(repls), array_values(repls), uri);
            }
        }

        parent::__construct(uri);
    }

    public function onPregReplaceCallback(array matches) -> string
    {
        var name, type, pattern;

        if unlikely ! fetch name, matches[1] {
            throw new Exception("Invalid matches");
        }

        let name = "{" . name . "}";
        if unlikely isset this->replacements[name] {
            throw new Exception("Duplicate name: " . name);
        }

        let this->replacements[name] = sprintf("${%d}", count(this->replacements) + 1);

        loop {
            if ! fetch type, matches[2] {
                break;
            }

            let type = substr((string) type, 1);
            if ! fetch pattern, this->typePatterns[type] {
                break;
            }

            return "/(" . pattern . ")";
        }

        return "/(" . self::DEFAULT_PATTERN . ")";
    }

}
