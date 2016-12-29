
extern zend_class_entry *nc_cache_filesystem_ce;

ZEPHIR_INIT_CLASS(Nc_Cache_FileSystem);

PHP_METHOD(Nc_Cache_FileSystem, rmDirRecursively);
PHP_METHOD(Nc_Cache_FileSystem, __construct);
PHP_METHOD(Nc_Cache_FileSystem, getBaseDirectory);
PHP_METHOD(Nc_Cache_FileSystem, getMode);
PHP_METHOD(Nc_Cache_FileSystem, clear);
PHP_METHOD(Nc_Cache_FileSystem, store);
PHP_METHOD(Nc_Cache_FileSystem, fetch);
PHP_METHOD(Nc_Cache_FileSystem, forget);
PHP_METHOD(Nc_Cache_FileSystem, getDir);
PHP_METHOD(Nc_Cache_FileSystem, getPath);
PHP_METHOD(Nc_Cache_FileSystem, packData);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_rmdirrecursively, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, baseDirectory)
	ZEND_ARG_INFO(0, mode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_clear, 0, 0, 0)
	ZEND_ARG_INFO(0, poolName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_store, 0, 0, 3)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_fetch, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_forget, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_getdir, 0, 0, 1)
	ZEND_ARG_INFO(0, poolName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_getpath, 0, 0, 2)
	ZEND_ARG_INFO(0, poolName)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, mkDirIfNeeded)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_cache_filesystem_packdata, 0, 0, 2)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, ttl)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_cache_filesystem_method_entry) {
	PHP_ME(Nc_Cache_FileSystem, rmDirRecursively, arginfo_nc_cache_filesystem_rmdirrecursively, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Cache_FileSystem, __construct, arginfo_nc_cache_filesystem___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Cache_FileSystem, getBaseDirectory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_FileSystem, getMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_FileSystem, clear, arginfo_nc_cache_filesystem_clear, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_FileSystem, store, arginfo_nc_cache_filesystem_store, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_FileSystem, fetch, arginfo_nc_cache_filesystem_fetch, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_FileSystem, forget, arginfo_nc_cache_filesystem_forget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Cache_FileSystem, getDir, arginfo_nc_cache_filesystem_getdir, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Cache_FileSystem, getPath, arginfo_nc_cache_filesystem_getpath, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Cache_FileSystem, packData, arginfo_nc_cache_filesystem_packdata, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
