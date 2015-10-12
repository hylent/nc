
extern zend_class_entry *nc_cache_cacheinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_CacheInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_rawset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_rawget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_rawdelete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_setinteger, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_getinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_deleteinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_incrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_decrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_multiset, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_multiget, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_multidelete, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_groupsetall, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_groupgetall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_groupdeleteall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_groupset, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_groupget, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheinterface_groupdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_cacheinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, flush, NULL)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, rawSet, arginfo_nc_cache_cacheinterface_rawset)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, rawGet, arginfo_nc_cache_cacheinterface_rawget)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, rawDelete, arginfo_nc_cache_cacheinterface_rawdelete)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, setInteger, arginfo_nc_cache_cacheinterface_setinteger)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, getInteger, arginfo_nc_cache_cacheinterface_getinteger)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, deleteInteger, arginfo_nc_cache_cacheinterface_deleteinteger)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, incrementInteger, arginfo_nc_cache_cacheinterface_incrementinteger)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, decrementInteger, arginfo_nc_cache_cacheinterface_decrementinteger)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, set, arginfo_nc_cache_cacheinterface_set)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, get, arginfo_nc_cache_cacheinterface_get)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, delete, arginfo_nc_cache_cacheinterface_delete)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, multiSet, arginfo_nc_cache_cacheinterface_multiset)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, multiGet, arginfo_nc_cache_cacheinterface_multiget)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, multiDelete, arginfo_nc_cache_cacheinterface_multidelete)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, groupSetAll, arginfo_nc_cache_cacheinterface_groupsetall)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, groupGetAll, arginfo_nc_cache_cacheinterface_groupgetall)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, groupDeleteAll, arginfo_nc_cache_cacheinterface_groupdeleteall)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, groupSet, arginfo_nc_cache_cacheinterface_groupset)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, groupGet, arginfo_nc_cache_cacheinterface_groupget)
	PHP_ABSTRACT_ME(Nc_Cache_CacheInterface, groupDelete, arginfo_nc_cache_cacheinterface_groupdelete)
	PHP_FE_END
};
