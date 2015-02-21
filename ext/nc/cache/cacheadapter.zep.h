
extern zend_class_entry *nc_cache_cacheadapter_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_CacheAdapter);

PHP_METHOD(Nc_Cache_CacheAdapter, setSerializer);
PHP_METHOD(Nc_Cache_CacheAdapter, getSerializer);
PHP_METHOD(Nc_Cache_CacheAdapter, setInteger);
PHP_METHOD(Nc_Cache_CacheAdapter, getInteger);
PHP_METHOD(Nc_Cache_CacheAdapter, deleteInteger);
PHP_METHOD(Nc_Cache_CacheAdapter, incrementInteger);
PHP_METHOD(Nc_Cache_CacheAdapter, decrementInteger);
PHP_METHOD(Nc_Cache_CacheAdapter, set);
PHP_METHOD(Nc_Cache_CacheAdapter, get);
PHP_METHOD(Nc_Cache_CacheAdapter, delete);
PHP_METHOD(Nc_Cache_CacheAdapter, multiSet);
PHP_METHOD(Nc_Cache_CacheAdapter, multiGet);
PHP_METHOD(Nc_Cache_CacheAdapter, multiDelete);
PHP_METHOD(Nc_Cache_CacheAdapter, groupSetAll);
PHP_METHOD(Nc_Cache_CacheAdapter, groupGetAll);
PHP_METHOD(Nc_Cache_CacheAdapter, groupDeleteAll);
PHP_METHOD(Nc_Cache_CacheAdapter, groupSet);
PHP_METHOD(Nc_Cache_CacheAdapter, groupGet);
PHP_METHOD(Nc_Cache_CacheAdapter, groupDelete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_setserializer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, serializer, Nc\\Serializer\\SerializerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_setinteger, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_getinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_deleteinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_incrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_decrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_multiset, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, expiredAt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_multiget, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_multidelete, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_groupsetall, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_groupgetall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_groupdeleteall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_groupset, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_groupget, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheadapter_groupdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_cacheadapter_method_entry) {
	PHP_ME(Nc_Cache_CacheAdapter, setSerializer, arginfo_nc_cache_cacheadapter_setserializer, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, getSerializer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, setInteger, arginfo_nc_cache_cacheadapter_setinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, getInteger, arginfo_nc_cache_cacheadapter_getinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, deleteInteger, arginfo_nc_cache_cacheadapter_deleteinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, incrementInteger, arginfo_nc_cache_cacheadapter_incrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, decrementInteger, arginfo_nc_cache_cacheadapter_decrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, set, arginfo_nc_cache_cacheadapter_set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, get, arginfo_nc_cache_cacheadapter_get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, delete, arginfo_nc_cache_cacheadapter_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, multiSet, arginfo_nc_cache_cacheadapter_multiset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, multiGet, arginfo_nc_cache_cacheadapter_multiget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, multiDelete, arginfo_nc_cache_cacheadapter_multidelete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, groupSetAll, arginfo_nc_cache_cacheadapter_groupsetall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, groupGetAll, arginfo_nc_cache_cacheadapter_groupgetall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, groupDeleteAll, arginfo_nc_cache_cacheadapter_groupdeleteall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, groupSet, arginfo_nc_cache_cacheadapter_groupset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, groupGet, arginfo_nc_cache_cacheadapter_groupget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAdapter, groupDelete, arginfo_nc_cache_cacheadapter_groupdelete, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
