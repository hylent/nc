
extern zend_class_entry *nc_cache_apc_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_Apc);

PHP_METHOD(Nc_Cache_Apc, __construct);
PHP_METHOD(Nc_Cache_Apc, flush);
PHP_METHOD(Nc_Cache_Apc, rawSet);
PHP_METHOD(Nc_Cache_Apc, rawGet);
PHP_METHOD(Nc_Cache_Apc, rawDelete);
PHP_METHOD(Nc_Cache_Apc, incrementInteger);
PHP_METHOD(Nc_Cache_Apc, decrementInteger);
PHP_METHOD(Nc_Cache_Apc, multiSet);
PHP_METHOD(Nc_Cache_Apc, multiGet);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apc_rawset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apc_rawget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apc_rawdelete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apc_incrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apc_decrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apc_multiset, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, expiredAt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_apc_multiget, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_apc_method_entry) {
	PHP_ME(Nc_Cache_Apc, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Cache_Apc, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apc, rawSet, arginfo_nc_cache_apc_rawset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apc, rawGet, arginfo_nc_cache_apc_rawget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apc, rawDelete, arginfo_nc_cache_apc_rawdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apc, incrementInteger, arginfo_nc_cache_apc_incrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apc, decrementInteger, arginfo_nc_cache_apc_decrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apc, multiSet, arginfo_nc_cache_apc_multiset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Apc, multiGet, arginfo_nc_cache_apc_multiget, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
