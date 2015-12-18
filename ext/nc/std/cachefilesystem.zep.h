
extern zend_class_entry *nc_std_cachefilesystem_ce;

ZEPHIR_INIT_CLASS(Nc_Std_CacheFileSystem);

PHP_METHOD(Nc_Std_CacheFileSystem, __construct);
PHP_METHOD(Nc_Std_CacheFileSystem, setCache);
PHP_METHOD(Nc_Std_CacheFileSystem, getCache);
PHP_METHOD(Nc_Std_CacheFileSystem, deleteCache);
PHP_METHOD(Nc_Std_CacheFileSystem, packData);
PHP_METHOD(Nc_Std_CacheFileSystem, path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystem___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, baseDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystem_setcache, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystem_getcache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystem_deletecache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystem_packdata, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystem_path, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, mkdirIfNeeded)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_cachefilesystem_method_entry) {
	PHP_ME(Nc_Std_CacheFileSystem, __construct, arginfo_nc_std_cachefilesystem___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_CacheFileSystem, setCache, arginfo_nc_std_cachefilesystem_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheFileSystem, getCache, arginfo_nc_std_cachefilesystem_getcache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheFileSystem, deleteCache, arginfo_nc_std_cachefilesystem_deletecache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheFileSystem, packData, arginfo_nc_std_cachefilesystem_packdata, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Std_CacheFileSystem, path, arginfo_nc_std_cachefilesystem_path, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
