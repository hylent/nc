
extern zend_class_entry *nc_cache_cachebackendabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_CacheBackendAbstract);

PHP_METHOD(Nc_Cache_CacheBackendAbstract, getPool);
PHP_METHOD(Nc_Cache_CacheBackendAbstract, storeMany);
PHP_METHOD(Nc_Cache_CacheBackendAbstract, fetchMany);
PHP_METHOD(Nc_Cache_CacheBackendAbstract, forgetMany);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendabstract_getpool, 0, 0, 1)
	ZEND_ARG_INFO(0, poolName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendabstract_storemany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendabstract_fetchmany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendabstract_forgetmany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_cachebackendabstract_method_entry) {
	PHP_ME(Nc_Cache_CacheBackendAbstract, getPool, arginfo_nc_cache_cachebackendabstract_getpool, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheBackendAbstract, storeMany, arginfo_nc_cache_cachebackendabstract_storemany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheBackendAbstract, fetchMany, arginfo_nc_cache_cachebackendabstract_fetchmany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheBackendAbstract, forgetMany, arginfo_nc_cache_cachebackendabstract_forgetmany, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
