
extern zend_class_entry *nc_cache_cacheawareinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_CacheAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheawareinterface_setcache, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, cache, Nc\\Cache\\CacheInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_cacheawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Cache_CacheAwareInterface, setCache, arginfo_nc_cache_cacheawareinterface_setcache)
	PHP_ABSTRACT_ME(Nc_Cache_CacheAwareInterface, getCache, NULL)
	PHP_FE_END
};
