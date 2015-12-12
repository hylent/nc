namespace Nc\Data;

class SingleValue extends DataAbstract
{
    public function set(var value) -> void
    {
        this->backend->setSingleValue(this->identifier, value);
    }

    public function get()
    {
        return this->backend->getSingleValue(this->identifier);
    }

    public function delete() -> void
    {
        this->backend->deleteSingleValue(this->identifier);
    }

}
