namespace Nc\Db;

class Collection implements \Countable, \Iterator
{
    protected model;
    protected data;
    protected internalIndex = -1;
    protected indexes;

    public function __construct(<Model> model, array data) -> void
    {
        let this->model = model;
        let this->data = data;
        let this->internalIndex = count(data) - 1;
    }

    public function getModel() -> <Model>
    {
        return this->model;
    }

    public function at(long index, bool asArray = false)
    {
        var row;

        if asArray {
            if fetch row, this->data[index] {
                return row;
            }
        } else {
            if fetch row, this->data[index] {
                return this->model->newEntity(row, false, this);
            }
            throw new ModelException("Cannot find entity at: " . index);
        }
    }

    public function id(var id, bool asArray = false)
    {
        var k, v, indexes;

        if this->indexes === null {
            let indexes = [];
            for k, v in this->data {
                let indexes[join(":", this->model->pickPrimaryKeyValue(v))] = k;
            }
            let this->indexes = indexes;
        }

        let k = join(":", this->model->packPrimaryKeyValue(id));
        if unlikely ! fetch v, this->indexes[k] {
            let v = -1;
        }

        return this->at(v, asArray);
    }

    public function count() -> long
    {
        return count(this->data);
    }

    public function rewind() -> void
    {
        let this->internalIndex = 0;
    }

    public function valid() -> bool
    {
        return isset this->data[this->internalIndex];
    }

    public function current(bool asArray = false)
    {
        return this->at(this->internalIndex, asArray);
    }

    public function key() -> long
    {
        return this->internalIndex;
    }

    public function next() -> void
    {
        let this->internalIndex++;
    }

    public function data() -> array
    {
        return this->data;
    }

    public function indexedData(string indexKey) -> array
    {
        var k, v, arr = [], indexValue;

        for k, v in this->data {
            if unlikely typeof v != "array" {
                throw new ModelException("Invalid item type, array required: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new ModelException("Cannot find value of index at: " . k);
            }

            let arr[indexValue] = v;
        }

        return arr;
    }

    public function groupedData(string groupKey) -> array
    {
        var k, v, arr = [], groupValue;

        for k, v in this->data {
            if unlikely typeof v != "array" {
                throw new ModelException("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new ModelException("Cannot find value of group at: " . k);
            }

            let arr[groupValue][] = v;
        }

        return arr;
    }

    public function groupIndexedData(string groupKey, string indexKey) -> array
    {
        var k, v, arr = [], groupValue, indexValue;

        for k, v in this->data {
            if unlikely typeof v != "array" {
                throw new ModelException("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new ModelException("Cannot find value of group at: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new ModelException("Cannot find value of index at: " . k);
            }

            let arr[groupValue][indexValue] = v;
        }

        return arr;
    }

    public function values(string valueKey) -> array
    {
        var k, v, arr = [], valueValue;

        for k, v in this->data {
            if unlikely typeof v != "array" {
                throw new ModelException("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch valueValue, v[valueKey] {
                throw new ModelException("Cannot find value of value at: " . k);
            }

            let arr[] = valueValue;
        }

        return arr;
    }

    public function uniqueValues(string valueKey) -> array
    {
        return array_unique(this->values(valueKey));
    }

    public function indexedValues(string indexKey, string valueKey) -> array
    {
        var k, v, arr = [], indexValue, valueValue;

        for k, v in this->data {
            if unlikely typeof v != "array" {
                throw new ModelException("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new ModelException("Cannot find value of index at: " . k);
            }
            if unlikely ! fetch valueValue, v[valueKey] {
                throw new ModelException("Cannot find value of value at: " . k);
            }

            let arr[indexValue] = valueValue;
        }

        return arr;
    }

    public function groupedValues(string groupKey, string valueKey) -> array
    {
        var k, v, arr = [], groupValue, valueValue;

        for k, v in this->data {
            if unlikely typeof v != "array" {
                throw new ModelException("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new ModelException("Cannot find value of group at: " . k);
            }
            if unlikely ! fetch valueValue, v[valueKey] {
                throw new ModelException("Cannot find value of value at: " . k);
            }

            let arr[groupValue][] = valueValue;
        }

        return arr;
    }

    public function groupIndexedValues(string groupKey, string indexKey, string valueKey) -> array
    {
        var k, v, arr = [], groupValue, indexValue, valueValue;

        for k, v in this->data {
            if unlikely typeof v != "array" {
                throw new ModelException("Invalid item type, array required at: " . k);
            }
            if unlikely ! fetch groupValue, v[groupKey] {
                throw new ModelException("Cannot find value of group at: " . k);
            }
            if unlikely ! fetch indexValue, v[indexKey] {
                throw new ModelException("Cannot find value of index at: " . k);
            }
            if unlikely ! fetch valueValue, v[valueKey] {
                throw new ModelException("Cannot find value of value at: " . k);
            }

            let arr[groupValue][indexValue] = valueValue;
        }

        return arr;
    }

}
