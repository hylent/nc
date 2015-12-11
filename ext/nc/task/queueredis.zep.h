
extern zend_class_entry *nc_task_queueredis_ce;

ZEPHIR_INIT_CLASS(Nc_Task_QueueRedis);

PHP_METHOD(Nc_Task_QueueRedis, __construct);
PHP_METHOD(Nc_Task_QueueRedis, produce);
PHP_METHOD(Nc_Task_QueueRedis, consume);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_queueredis___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, queueKey)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_task_queueredis_produce, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, task, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_task_queueredis_method_entry) {
	PHP_ME(Nc_Task_QueueRedis, __construct, arginfo_nc_task_queueredis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Task_QueueRedis, produce, arginfo_nc_task_queueredis_produce, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Task_QueueRedis, consume, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
