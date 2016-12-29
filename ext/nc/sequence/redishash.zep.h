
extern zend_class_entry *nc_sequence_redishash_ce;

ZEPHIR_INIT_CLASS(Nc_Sequence_RedisHash);

PHP_METHOD(Nc_Sequence_RedisHash, __construct);
PHP_METHOD(Nc_Sequence_RedisHash, getRedis);
PHP_METHOD(Nc_Sequence_RedisHash, getHashName);
PHP_METHOD(Nc_Sequence_RedisHash, next);
PHP_METHOD(Nc_Sequence_RedisHash, restore);
PHP_METHOD(Nc_Sequence_RedisHash, clear);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_redishash___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, hashName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_redishash_next, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_sequence_redishash_restore, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, sequence)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_sequence_redishash_method_entry) {
	PHP_ME(Nc_Sequence_RedisHash, __construct, arginfo_nc_sequence_redishash___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Sequence_RedisHash, getRedis, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_RedisHash, getHashName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_RedisHash, next, arginfo_nc_sequence_redishash_next, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_RedisHash, restore, arginfo_nc_sequence_redishash_restore, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Sequence_RedisHash, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
