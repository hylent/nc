
extern zend_class_entry *nc_std_cachefilesystemabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Std_CacheFileSystemAbstract);

PHP_METHOD(Nc_Std_CacheFileSystemAbstract, __construct);
PHP_METHOD(Nc_Std_CacheFileSystemAbstract, setCache);
PHP_METHOD(Nc_Std_CacheFileSystemAbstract, getCache);
PHP_METHOD(Nc_Std_CacheFileSystemAbstract, deleteCache);
PHP_METHOD(Nc_Std_CacheFileSystemAbstract, packData);
PHP_METHOD(Nc_Std_CacheFileSystemAbstract, path);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemabstract___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, baseDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemabstract_setcache, 0, 0, 2)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemabstract_getcache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemabstract_deletecache, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemabstract_packdata, 0, 0, 2)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, lifetime)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_std_cachefilesystemabstract_path, 0, 0, 1)
	ZEND_ARG_INFO(0, identifier)
	ZEND_ARG_INFO(0, mkdirIfNeeded)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_std_cachefilesystemabstract_method_entry) {
	PHP_ME(Nc_Std_CacheFileSystemAbstract, __construct, arginfo_nc_std_cachefilesystemabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Std_CacheFileSystemAbstract, setCache, arginfo_nc_std_cachefilesystemabstract_setcache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheFileSystemAbstract, getCache, arginfo_nc_std_cachefilesystemabstract_getcache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheFileSystemAbstract, deleteCache, arginfo_nc_std_cachefilesystemabstract_deletecache, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Std_CacheFileSystemAbstract, packData, arginfo_nc_std_cachefilesystemabstract_packdata, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Std_CacheFileSystemAbstract, path, arginfo_nc_std_cachefilesystemabstract_path, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
