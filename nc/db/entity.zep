namespace Nc\Db;

class Entity
{
    protected model;
    protected row;
    protected isNew;
    protected updates;
    protected collection;

    public function __construct(<Model> model, array row, bool isNew) -> void
    {
        let this->model = model;
        let this->row = row;
        let this->isNew = isNew;
    }

    public function getModel() -> <Model>
    {
        return this->model;
    }

    public function asArray() -> array
    {
        return this->row;
    }

    public function isNew() -> bool
    {
        return this->isNew;
    }

    public function isDirty() -> bool
    {
        return count(this->updates) > 0;
    }

    public function setCollection(<Collection> collection = null) -> void
    {
        let this->collection = collection;
    }

    public function hasCollection() -> bool
    {
        return this->collection !== null;
    }

    public function getCollection() -> <Collection>
    {
        return this->collection;
    }

    public function primaryKeyValue() -> array
    {
        return this->model->pickPrimaryKeyValue(this->row);
    }

    public function set(array updates) -> <Entity>
    {
        var k, v;

        for k, v in updates {
            let this->row[k] = v;

            if ! this->isNew {
                let this->updates[k] = v;
            }
        }

        return this;
    }

    public function __set(string name, var value) -> void
    {
        let this->row[name] = value;

        if ! this->isNew {
            let this->updates[name] = value;
        }
    }

    public function __get(string name)
    {
        var value;

        if fetch value, this->row[name] {
            return value;
        }
    }

    public function save() -> void
    {
        var k, v, row;

        if this->isNew {
            let row = this->model->insert(this->row);
            let this->isNew = false;
        } else {
            if unlikely count(this->updates) < 1 {
                let this->updates = [];
            }

            let row = this->model->update(
                this->updates,
                this->primaryKeyValue()
            );

            let this->updates = [];
        }

        for k, v in row {
            let this->row[k] = v;
        }
    }

    public function drop() -> void
    {
        this->model->delete(
            this->primaryKeyValue()
        );
    }

}
