
extern zend_class_entry *nc_cache_redis_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_Redis);

PHP_METHOD(Nc_Cache_Redis, __construct);
PHP_METHOD(Nc_Cache_Redis, flush);
PHP_METHOD(Nc_Cache_Redis, rawSet);
PHP_METHOD(Nc_Cache_Redis, rawGet);
PHP_METHOD(Nc_Cache_Redis, rawDelete);
PHP_METHOD(Nc_Cache_Redis, incrementInteger);
PHP_METHOD(Nc_Cache_Redis, decrementInteger);
PHP_METHOD(Nc_Cache_Redis, multiGet);
PHP_METHOD(Nc_Cache_Redis, multiDelete);
PHP_METHOD(Nc_Cache_Redis, groupSetAll);
PHP_METHOD(Nc_Cache_Redis, groupGetAll);
PHP_METHOD(Nc_Cache_Redis, groupDeleteAll);
PHP_METHOD(Nc_Cache_Redis, groupSet);
PHP_METHOD(Nc_Cache_Redis, groupGet);
PHP_METHOD(Nc_Cache_Redis, groupDelete);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, db)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_rawset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_rawget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_rawdelete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_incrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_decrementinteger, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, step)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_multiget, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_multidelete, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_groupsetall, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_groupgetall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_groupdeleteall, 0, 0, 1)
	ZEND_ARG_INFO(0, group)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_groupset, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keyValues, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_groupget, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_redis_groupdelete, 0, 0, 2)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_ARRAY_INFO(0, keys, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_redis_method_entry) {
	PHP_ME(Nc_Cache_Redis, __construct, arginfo_nc_cache_redis___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Cache_Redis, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, rawSet, arginfo_nc_cache_redis_rawset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, rawGet, arginfo_nc_cache_redis_rawget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, rawDelete, arginfo_nc_cache_redis_rawdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, incrementInteger, arginfo_nc_cache_redis_incrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, decrementInteger, arginfo_nc_cache_redis_decrementinteger, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, multiGet, arginfo_nc_cache_redis_multiget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, multiDelete, arginfo_nc_cache_redis_multidelete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, groupSetAll, arginfo_nc_cache_redis_groupsetall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, groupGetAll, arginfo_nc_cache_redis_groupgetall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, groupDeleteAll, arginfo_nc_cache_redis_groupdeleteall, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, groupSet, arginfo_nc_cache_redis_groupset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, groupGet, arginfo_nc_cache_redis_groupget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_Redis, groupDelete, arginfo_nc_cache_redis_groupdelete, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
