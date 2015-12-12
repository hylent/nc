namespace Nc\Data;

interface SingleValueBackendInterface
{
    public function setSingleValue(string identifier, var value) -> void;
    public function getSingleValue(string identifier);
    public function deleteSingleValue(string identifier) -> void;

}
