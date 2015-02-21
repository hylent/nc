
extern zend_class_entry *nc_cache_file_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_File);

PHP_METHOD(Nc_Cache_File, __construct);
PHP_METHOD(Nc_Cache_File, flush);
PHP_METHOD(Nc_Cache_File, rawSet);
PHP_METHOD(Nc_Cache_File, rawGet);
PHP_METHOD(Nc_Cache_File, rawDelete);
PHP_METHOD(Nc_Cache_File, set);
PHP_METHOD(Nc_Cache_File, get);
PHP_METHOD(Nc_Cache_File, getPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_file___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, directory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_file_rawset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_file_rawget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_file_rawdelete, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_file_set, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_file_get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_file_getpath, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_file_method_entry) {
	PHP_ME(Nc_Cache_File, __construct, arginfo_nc_cache_file___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Cache_File, flush, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_File, rawSet, arginfo_nc_cache_file_rawset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_File, rawGet, arginfo_nc_cache_file_rawget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_File, rawDelete, arginfo_nc_cache_file_rawdelete, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_File, set, arginfo_nc_cache_file_set, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_File, get, arginfo_nc_cache_file_get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_File, getPath, arginfo_nc_cache_file_getpath, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
