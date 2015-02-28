namespace Nc\Db\Model;

use Nc\Db\Query\DbQueryAbstract;

class Model
{
    protected modelFactory;
    protected name;
    protected table;
    protected id;

    protected relations;
    protected validations;

    final public function __construct(<ModelFactory> modelFactory, string name, string table, var id = "id") -> void
    {
        let this->modelFactory = modelFactory;
        let this->name = name;
        let this->table = table;
        let this->id = id;
    }

    public function getModelFactory() -> <ModelFactory>
    {
        return this->modelFactory;
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function getTable() -> string
    {
        return this->table;
    }

    public function getId()
    {
        return this->id;
    }

    public function getQuery() -> <DbQueryAbstract>
    {
        return this->modelFactory->getDb()->__invoke(this->table, this->name);
    }

    public function setRelation(string relationName, <DbModelRelationInterface> relation) -> void
    {
        let this->relations[relationName] = relation;
    }

    public function getRelation(string relationName) -> <DbModelRelationInterface>
    {
        var relation;

        if unlikely ! fetch relation, this->relations[relationName] {
            throw new Exception("Cannot find relation: " . relationName);
        }

        return relation;
    }

    public function insert(array record)
    {
        return this->getQuery()->insert(record, this->id);
    }

    public function find(var idValue)
    {
        var data, record;

        let data = this->selectMany([idValue]);
        if fetch record, data[0] {
            return record;
        }
    }

    public function select(var idValue) -> array
    {
        return this->selectMany([idValue]);
    }

    public function selectMany(array idValues) -> array
    {
        return this->getQuery()->$in(this->id, idValues)->select();
    }

    public function selectWhere(var where) -> array
    {
        return this->getQuery()->where(where)->select();
    }

    public function delete(var idValue) -> boolean
    {
        return this->deleteMany([idValue]);
    }

    public function deleteMany(array idValues) -> boolean
    {
        return this->getQuery()->$in(this->id, idValues)->delete();
    }

    public function deleteWhere(var where) -> boolean
    {
        return this->getQuery()->where(where)->delete();
    }

    public function update(var idValue, array record) -> boolean
    {
        return this->updateMany([idValue], record);
    }

    public function updateMany(array idValues, array record) -> boolean
    {
        return this->getQuery()->$in(this->id, idValues)->update(record);
    }

    public function updateWhere(var where, array record) -> boolean
    {
        return this->getQuery()->where(where)->update(record);
    }

    public function entity(array $data = []) -> <Entity>
    {
        return new Entity(this, data);
    }

    public function all() -> <Entity>
    {
        var data;

        let data = this->getQuery()->select();
        return this->entity(data);
    }

    public function id(var idValue) -> <Entity>
    {
        var data;

        let data = this->getQuery()->eq(this->id, idValue)->select();
        return this->entity(data);
    }

    public function ids(array idValues) -> <Entity>
    {
        var data;

        let data = this->getQuery()->$in(this->id, idValues)->select();
        return this->entity(data);
    }

    public function delegation(var delegation) -> <Entity>
    {
        var query, data;

        let query = this->getQuery();
        if delegation {
            call_user_func(delegation, query, this);
        }

        let data = query->select();
        return this->entity(data);
    }

    public function delegations(array delegations) -> <Entity>
    {
        var query, delegation, data;

        let query = this->getQuery();
        for delegation in delegations {
            if delegation {
                call_user_func(delegation, query, this);
            }
        }

        let data = query->select();
        return this->entity(data);
    }

    public function saveEntity(<Entity> entity) -> void
    {
        return;
    }

    public function dropEntity(<Entity> entity) -> void
    {
        var idValues;

        let idValues = entity->uniqueValues(this->id);
        let result = this->getQuery()->$in(this->id, idValues)->delete();

        if unlikely ! result {
            throw new Exception("Cannot drop entity");
        }
    }
}
