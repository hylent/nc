
extern zend_class_entry *nc_std_cacheapc_ce;

ZEPHIR_INIT_CLASS(Nc_Std_CacheApc);

PHP_METHOD(Nc_Std_CacheApc, __construct);
PHP_METHOD(Nc_Std_CacheApc, setCache);
PHP_METHOD(Nc_Std_CacheApc, getCache);
PHP_METHOD(Nc_Std_CacheApc, deleteCache);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cacheapc___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cacheapc_setcache, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cacheapc_getcache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cacheapc_deletecache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_cacheapc_method_entry) {
	PHP_ME(Nc_Std_CacheApc, __construct, arginfo_nc_std_cacheapc___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_CacheApc, setCache, arginfo_nc_std_cacheapc_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheApc, getCache, arginfo_nc_std_cacheapc_getcache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheApc, deleteCache, arginfo_nc_std_cacheapc_deletecache, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
