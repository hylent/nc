
extern zend_class_entry *nc_log_redislist_ce;

ZEPHIR_INIT_CLASS(Nc_Log_RedisList);

PHP_METHOD(Nc_Log_RedisList, __construct);
PHP_METHOD(Nc_Log_RedisList, getRedis);
PHP_METHOD(Nc_Log_RedisList, getKeyName);
PHP_METHOD(Nc_Log_RedisList, getTtl);
PHP_METHOD(Nc_Log_RedisList, retrieveLogs);
PHP_METHOD(Nc_Log_RedisList, writeLogs);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_redislist___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, redis)
	ZEND_ARG_INFO(0, keyName)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_redislist_retrievelogs, 0, 0, 0)
	ZEND_ARG_INFO(0, maxLogs)
	ZEND_ARG_INFO(0, blocking)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_log_redislist_writelogs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, logs, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_log_redislist_method_entry) {
	PHP_ME(Nc_Log_RedisList, __construct, arginfo_nc_log_redislist___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Log_RedisList, getRedis, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_RedisList, getKeyName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_RedisList, getTtl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_RedisList, retrieveLogs, arginfo_nc_log_redislist_retrievelogs, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Log_RedisList, writeLogs, arginfo_nc_log_redislist_writelogs, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
