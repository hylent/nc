
extern zend_class_entry *nc_cache_cacheabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_CacheAbstract);

PHP_METHOD(Nc_Cache_CacheAbstract, setSerializer);
PHP_METHOD(Nc_Cache_CacheAbstract, getSerializer);
PHP_METHOD(Nc_Cache_CacheAbstract, setInteger);
PHP_METHOD(Nc_Cache_CacheAbstract, getInteger);
PHP_METHOD(Nc_Cache_CacheAbstract, deleteInteger);
PHP_METHOD(Nc_Cache_CacheAbstract, incrementInteger);
PHP_METHOD(Nc_Cache_CacheAbstract, decrementInteger);
PHP_METHOD(Nc_Cache_CacheAbstract, set);
PHP_METHOD(Nc_Cache_CacheAbstract, get);
PHP_METHOD(Nc_Cache_CacheAbstract, delete);
PHP_METHOD(Nc_Cache_CacheAbstract, multiSet);
PHP_METHOD(Nc_Cache_CacheAbstract, multiGet);
PHP_METHOD(Nc_Cache_CacheAbstract, multiDelete);
PHP_METHOD(Nc_Cache_CacheAbstract, groupSetAll);
PHP_METHOD(Nc_Cache_CacheAbstract, groupGetAll);
PHP_METHOD(Nc_Cache_CacheAbstract, groupDeleteAll);
PHP_METHOD(Nc_Cache_CacheAbstract, groupSet);
PHP_METHOD(Nc_Cache_CacheAbstract, groupGet);
PHP_METHOD(Nc_Cache_CacheAbstract, groupDelete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_setserializer, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, serializer, Nc\\Serializer\\SerializerInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_setinteger, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_getinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_deleteinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_incrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_decrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_delete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_multiset, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
	ZEND_ARG_INFO(0, expiredAt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_multiget, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_multidelete, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_groupsetall, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_groupgetall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_groupdeleteall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_groupset, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_groupget, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_cacheabstract_groupdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_cacheabstract_method_entry) {
	PHP_ME(Nc_Cache_CacheAbstract, setSerializer, arginfo_nc_cache_cacheabstract_setserializer, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, getSerializer, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, setInteger, arginfo_nc_cache_cacheabstract_setinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, getInteger, arginfo_nc_cache_cacheabstract_getinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, deleteInteger, arginfo_nc_cache_cacheabstract_deleteinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, incrementInteger, arginfo_nc_cache_cacheabstract_incrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, decrementInteger, arginfo_nc_cache_cacheabstract_decrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, set, arginfo_nc_cache_cacheabstract_set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, get, arginfo_nc_cache_cacheabstract_get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, delete, arginfo_nc_cache_cacheabstract_delete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, multiSet, arginfo_nc_cache_cacheabstract_multiset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, multiGet, arginfo_nc_cache_cacheabstract_multiget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, multiDelete, arginfo_nc_cache_cacheabstract_multidelete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, groupSetAll, arginfo_nc_cache_cacheabstract_groupsetall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, groupGetAll, arginfo_nc_cache_cacheabstract_groupgetall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, groupDeleteAll, arginfo_nc_cache_cacheabstract_groupdeleteall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, groupSet, arginfo_nc_cache_cacheabstract_groupset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, groupGet, arginfo_nc_cache_cacheabstract_groupget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_CacheAbstract, groupDelete, arginfo_nc_cache_cacheabstract_groupdelete, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
