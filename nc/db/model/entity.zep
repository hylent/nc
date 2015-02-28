namespace Nc\Db\Model;

use Nc\Std;

class Entity implements \Countable, \Iterator
{
    protected model;
    protected data;
    protected internalIndex;

    final public function __construct(<Model> model, array data = []) -> void
    {
        let this->model = model;
        let this->data = data;
        let this->internalIndex = (long) count(data) - 1;
    }

    public function getModel() -> <Model>
    {
        return this->model;
    }

    public function __invoke(string relationName, var delegation = null)
    {
    }

    public function save() -> void
    {
        this->model->saveEntity(this);
    }

    public function drop() -> void
    {
        this->model->dropEntity(this);
    }

    public function isEmpty() -> boolean
    {
        return count(this->data) < 1;
    }

    public function count() -> long
    {
        return count(this->data);
    }

    public function current()
    {
        var record;

        if fetch record, this->data[this->internalIndex] {
            return record;
        }
    }

    public function key() -> long
    {
        return this->internalIndex;
    }

    public function next() -> void
    {
        let this->internalIndex++;
    }

    public function rewind() -> void
    {
        let this->internalIndex = 0;
    }

    public function valid() -> boolean
    {
        return isset this->data[this->internalIndex];
    }

    public function data() -> array
    {
        return this->data;
    }

    public function indexedData(string indexField) -> array
    {
        return Std::indexedData(this->data, indexField);
    }

    public function groupedData(string groupField) -> array
    {
        return Std::groupedData(this->data, groupField);
    }

    public function groupIndexedData(string groupField, string indexField) -> array
    {
        return Std::groupIndexedData(this->data, groupField, indexField);
    }

    public function values(string valueField) -> array
    {
        var v, a = [];

        for v in this->data {
            let a[] = v[valueField];
        }

        return a;
    }

    public function uniqueValues(string valueField) -> array
    {
        return Std::uniqueValues(this->data, valueField);
    }

    public function indexedValues(string indexField, string valueField) -> array
    {
        return Std::indexedValues(this->data, indexField, valueField);
    }

    public function groupedValues(string groupField, string valueField) -> array
    {
        return Std::groupedValues(this->data, groupField, valueField);
    }

    public function groupIndexedValues(string groupField, string indexField, string valueField) -> array
    {
        return Std::groupIndexedValues(this->data, groupField, indexField, valueField);
    }
}
