
extern zend_class_entry *nc_sequence_redis_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_Redis);

PHP_METHOD(Nc_Sequence_Redis, __construct);
PHP_METHOD(Nc_Sequence_Redis, getRedis);
PHP_METHOD(Nc_Sequence_Redis, getPrefix);
PHP_METHOD(Nc_Sequence_Redis, next);
PHP_METHOD(Nc_Sequence_Redis, restore);
PHP_METHOD(Nc_Sequence_Redis, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_redis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_redis_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_redis_restore, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_redis_method_entry) {
	PHP_ME(Nc_Sequence_Redis, __construct, arginfo_nc_sequence_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Sequence_Redis, getRedis, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Redis, getPrefix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Redis, next, arginfo_nc_sequence_redis_next, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Redis, restore, arginfo_nc_sequence_redis_restore, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_Redis, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
