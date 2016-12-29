
extern zend_class_entry *nc_cache_cachebackendinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_CacheBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_getpool, 0, 0, 1)
	ZEND_ARG_INFO(0, poolName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, poolName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_store, 0, 0, 3)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_storemany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_fetch, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_fetchmany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_forget, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachebackendinterface_forgetmany, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_cachebackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, getPool, arginfo_nc_cache_cachebackendinterface_getpool)
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, clear, arginfo_nc_cache_cachebackendinterface_clear)
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, store, arginfo_nc_cache_cachebackendinterface_store)
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, storeMany, arginfo_nc_cache_cachebackendinterface_storemany)
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, fetch, arginfo_nc_cache_cachebackendinterface_fetch)
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, fetchMany, arginfo_nc_cache_cachebackendinterface_fetchmany)
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, forget, arginfo_nc_cache_cachebackendinterface_forget)
	PHP_ABSTRACT_ME(Nc_Cache_CacheBackendInterface, forgetMany, arginfo_nc_cache_cachebackendinterface_forgetmany)
	PHP_FE_END
};
