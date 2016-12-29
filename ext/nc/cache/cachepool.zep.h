
extern zend_class_entry *nc_cache_cachepool_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_CachePool);

PHP_METHOD(Nc_Cache_CachePool, __construct);
PHP_METHOD(Nc_Cache_CachePool, getBackend);
PHP_METHOD(Nc_Cache_CachePool, getName);
PHP_METHOD(Nc_Cache_CachePool, clear);
PHP_METHOD(Nc_Cache_CachePool, store);
PHP_METHOD(Nc_Cache_CachePool, storeMany);
PHP_METHOD(Nc_Cache_CachePool, fetch);
PHP_METHOD(Nc_Cache_CachePool, fetchMany);
PHP_METHOD(Nc_Cache_CachePool, forget);
PHP_METHOD(Nc_Cache_CachePool, forgetMany);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachepool___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, backend, Nc\\Cache\\CacheBackendInterface, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachepool_store, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachepool_storemany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachepool_fetch, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachepool_fetchmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachepool_forget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cachepool_forgetmany, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_cachepool_method_entry) {
	PHP_ME(Nc_Cache_CachePool, __construct, arginfo_nc_cache_cachepool___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Cache_CachePool, getBackend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, clear, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, store, arginfo_nc_cache_cachepool_store, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, storeMany, arginfo_nc_cache_cachepool_storemany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, fetch, arginfo_nc_cache_cachepool_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, fetchMany, arginfo_nc_cache_cachepool_fetchmany, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, forget, arginfo_nc_cache_cachepool_forget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CachePool, forgetMany, arginfo_nc_cache_cachepool_forgetmany, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
