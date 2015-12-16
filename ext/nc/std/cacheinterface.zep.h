
extern zend_class_entry *nc_std_cacheinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Std_CacheInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cacheinterface_setcache, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cacheinterface_getcache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cacheinterface_deletecache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_cacheinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Std_CacheInterface, setCache, arginfo_nc_std_cacheinterface_setcache)
	PHP_ABSTRACT_ME(Nc_Std_CacheInterface, getCache, arginfo_nc_std_cacheinterface_getcache)
	PHP_ABSTRACT_ME(Nc_Std_CacheInterface, deleteCache, arginfo_nc_std_cacheinterface_deletecache)
	PHP_FE_END
};
