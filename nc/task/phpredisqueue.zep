namespace Nc\Task;

class PhpRedisQueue extends TaskManagerAbstract
{
    protected redis;
    protected queueKey;

    public function __construct(var redis, string queueKey) -> void
    {
        let this->redis = redis;
        let this->queueKey = queueKey;
    }

    public function getPhpRedis()
    {
        return this->redis;
    }

    public function produce(array task) -> void
    {
        if unlikely ! this->redis->lpush(this->queueKey, this->serializeTask(task)) {
            throw new Exception("Fail when redis lpush");
        }
    }

    public function consume() -> null|array
    {
        var task;

        let task = this->redis->rpop(this->queueKey);
        if ! task {
            return;
        }

        let task = this->unserializeTask(task);
        if unlikely typeof task != "array" {
            throw new Exception("Invalid task from redis");
        }

        return task;
    }

}
