namespace Nc\Db\Model\Relation;

use Nc\Db\Model\Entity;

interface DbModelRelationInterface
{
    public function setEntity(<Entity> entity) -> void;
    public function __invoke() -> <Entity>;
}
