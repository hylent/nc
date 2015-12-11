namespace Nc\Image;

abstract class ImageAbstract
{
    public width;
    public height;

    protected backend;

    public function __construct(<ImageBackendAbstract> backend) -> void
    {
        let this->backend = backend;
    }

    public function __destruct() -> void
    {
        this->backend->destroy(this);
    }

}
