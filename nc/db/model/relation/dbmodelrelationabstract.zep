namespace Nc\Db\Model\Relation;

abstract class DbModelRelationAbstract implements DbModelRelationInterface
{
    protected entity;

    public function setEntity(<Entity> entity) -> void
    {
        let this->entity = entity;
    }
}
