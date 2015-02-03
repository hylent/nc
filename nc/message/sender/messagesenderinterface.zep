namespace Nc\Message\Sender;

interface MessageSenderInterface
{
    public function send(string to, string subject, string message) -> void;
}
