namespace Nc\Messager;

interface MessagerInterface
{
    public function send(string to, string subject, string message) -> void;
}
