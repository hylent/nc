namespace Nc\Task;

interface TaskExecutorInterface
{
    public function executeTask(array task);

    public function onTaskReturn(array task, var re) -> void;
    public function onTaskException(array task, <\Exception> ex) -> void;

}
