
extern zend_class_entry *nc_queue_redis_ce;

ZEPHIR_INIT_CLASS(Nc_Queue_Redis);

PHP_METHOD(Nc_Queue_Redis, __construct);
PHP_METHOD(Nc_Queue_Redis, getRedis);
PHP_METHOD(Nc_Queue_Redis, getKeyName);
PHP_METHOD(Nc_Queue_Redis, put);
PHP_METHOD(Nc_Queue_Redis, reserve);
PHP_METHOD(Nc_Queue_Redis, delete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_redis___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, keyName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_redis_put, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_INFO(0, delay)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_redis_reserve, 0, 0, 1)
	ZEND_ARG_INFO(0, ttr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_queue_redis_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_queue_redis_method_entry) {
	PHP_ME(Nc_Queue_Redis, __construct, arginfo_nc_queue_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Queue_Redis, getRedis, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Redis, getKeyName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Redis, put, arginfo_nc_queue_redis_put, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Redis, reserve, arginfo_nc_queue_redis_reserve, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Queue_Redis, delete, arginfo_nc_queue_redis_delete, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
