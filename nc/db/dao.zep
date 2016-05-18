namespace Nc\Db;

class Dao extends DaoBase
{
    public function delete(array where = []) -> void
    {
        this->db->delete(this->table, array_merge(this->condition, where));
    }

    public function insert(array data)
    {
        var k, v, primaryKey;

        for k, v in this->condition {
            if strpos(k, "$") === false {
                let data[k] = v;
            }
        }

        let primaryKey = this->primaryKey;

        if typeof primaryKey == "array" {
            for k in primaryKey {
                if unlikely ! fetch v, data[k] || v === null {
                    throw new DaoException(sprintf(
                        "Missing primary key value of %s",
                        k
                    ));
                }
            }

            this->db->insert(this->table, data);
            return true;
        }

        let k = (string) primaryKey;

        if fetch v, data[k] && v !== null {
            this->db->insert(this->table, data);
            return v;
        }

        return this->db->insert(this->table, data, k);
    }

    public function update(array data, array where = []) -> void
    {
        this->db->update(this->table, data, array_merge(this->condition, where));
    }

    public function upsert(array data) -> void
    {
        var k, v;

        for k, v in this->condition {
            if strpos(k, "$") === false {
                let data[k] = v;
            }
        }

        this->db->upsert(this->table, data, this->primaryKey);
    }

}
