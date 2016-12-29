
extern zend_class_entry *nc_cache_apcu_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_Apcu);

PHP_METHOD(Nc_Cache_Apcu, __construct);
PHP_METHOD(Nc_Cache_Apcu, clear);
PHP_METHOD(Nc_Cache_Apcu, store);
PHP_METHOD(Nc_Cache_Apcu, storeMany);
PHP_METHOD(Nc_Cache_Apcu, fetch);
PHP_METHOD(Nc_Cache_Apcu, fetchMany);
PHP_METHOD(Nc_Cache_Apcu, forget);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apcu_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, poolName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apcu_store, 0, 0, 3)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apcu_storemany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apcu_fetch, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apcu_fetchmany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apcu_forget, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_apcu_method_entry) {
	PHP_ME(Nc_Cache_Apcu, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Cache_Apcu, clear, arginfo_nc_cache_apcu_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apcu, store, arginfo_nc_cache_apcu_store, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apcu, storeMany, arginfo_nc_cache_apcu_storemany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apcu, fetch, arginfo_nc_cache_apcu_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apcu, fetchMany, arginfo_nc_cache_apcu_fetchmany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apcu, forget, arginfo_nc_cache_apcu_forget, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
