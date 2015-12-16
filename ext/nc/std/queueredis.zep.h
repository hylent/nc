
extern zend_class_entry *nc_std_queueredis_ce;

ZEPHIR_INIT_CLASS(Nc_Std_QueueRedis);

PHP_METHOD(Nc_Std_QueueRedis, __construct);
PHP_METHOD(Nc_Std_QueueRedis, pushQueue);
PHP_METHOD(Nc_Std_QueueRedis, popQueue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_queueredis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_queueredis_pushqueue, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_queueredis_popqueue, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_queueredis_method_entry) {
	PHP_ME(Nc_Std_QueueRedis, __construct, arginfo_nc_std_queueredis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_QueueRedis, pushQueue, arginfo_nc_std_queueredis_pushqueue, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_QueueRedis, popQueue, arginfo_nc_std_queueredis_popqueue, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
