
extern zend_class_entry *nc_cache_memcache_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_Memcache);

PHP_METHOD(Nc_Cache_Memcache, __construct);
PHP_METHOD(Nc_Cache_Memcache, flush);
PHP_METHOD(Nc_Cache_Memcache, rawSet);
PHP_METHOD(Nc_Cache_Memcache, rawGet);
PHP_METHOD(Nc_Cache_Memcache, rawDelete);
PHP_METHOD(Nc_Cache_Memcache, setInteger);
PHP_METHOD(Nc_Cache_Memcache, getInteger);
PHP_METHOD(Nc_Cache_Memcache, incrementInteger);
PHP_METHOD(Nc_Cache_Memcache, decrementInteger);
PHP_METHOD(Nc_Cache_Memcache, multiGet);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_rawset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_rawget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_rawdelete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_setinteger, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_getinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_incrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_decrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_memcache_multiget, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_memcache_method_entry) {
	PHP_ME(Nc_Cache_Memcache, __construct, arginfo_nc_cache_memcache___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Cache_Memcache, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, rawSet, arginfo_nc_cache_memcache_rawset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, rawGet, arginfo_nc_cache_memcache_rawget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, rawDelete, arginfo_nc_cache_memcache_rawdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, setInteger, arginfo_nc_cache_memcache_setinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, getInteger, arginfo_nc_cache_memcache_getinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, incrementInteger, arginfo_nc_cache_memcache_incrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, decrementInteger, arginfo_nc_cache_memcache_decrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Memcache, multiGet, arginfo_nc_cache_memcache_multiget, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
