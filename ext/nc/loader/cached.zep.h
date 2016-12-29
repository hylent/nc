
extern zend_class_entry *nc_loader_cached_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_Cached);

PHP_METHOD(Nc_Loader_Cached, __construct);
PHP_METHOD(Nc_Loader_Cached, setLoader);
PHP_METHOD(Nc_Loader_Cached, getLoader);
PHP_METHOD(Nc_Loader_Cached, setCachePool);
PHP_METHOD(Nc_Loader_Cached, getCachePool);
PHP_METHOD(Nc_Loader_Cached, setCacheTtl);
PHP_METHOD(Nc_Loader_Cached, getCacheTtl);
PHP_METHOD(Nc_Loader_Cached, clearCache);
PHP_METHOD(Nc_Loader_Cached, findPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_cached___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, loader, Nc\\Loader\\LoaderInterface, 0)
	ZEND_ARG_OBJ_INFO(0, pool, Nc\\Cache\\CachePool, 0)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_cached_setloader, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, loader, Nc\\Loader\\LoaderInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_cached_setcachepool, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cachePool, Nc\\Cache\\CachePool, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_cached_setcachettl, 0, 0, 1)
	ZEND_ARG_INFO(0, cacheTtl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_cached_findpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_cached_method_entry) {
	PHP_ME(Nc_Loader_Cached, __construct, arginfo_nc_loader_cached___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Loader_Cached, setLoader, arginfo_nc_loader_cached_setloader, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Cached, getLoader, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Cached, setCachePool, arginfo_nc_loader_cached_setcachepool, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Cached, getCachePool, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Cached, setCacheTtl, arginfo_nc_loader_cached_setcachettl, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Cached, getCacheTtl, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Cached, clearCache, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Cached, findPath, arginfo_nc_loader_cached_findpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
