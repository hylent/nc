namespace Nc\Message\Sender;

interface MessageSenderAwareInterface
{
    public function setMessageSender(<MessageSenderInterface> messageSender) -> void;
    public function getMessageSender() -> <MessageSenderInterface>;
}
