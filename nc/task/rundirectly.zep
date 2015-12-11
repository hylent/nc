namespace Nc\Task;

class RunDirectly extends TaskManagerAbstract
{
    public function produce(array task) -> void
    {
        this->runTask(task);
    }

    public function consume() -> null|array
    {
        return;
    }

}
