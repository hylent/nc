namespace Nc\Messager;

interface MessagerAwareInterface
{
    public function setMessager(<MessagerInterface> messager) -> void;
    public function getMessager() -> <MessagerInterface>;
}
