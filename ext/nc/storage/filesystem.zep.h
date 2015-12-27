
extern zend_class_entry *nc_storage_filesystem_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_FileSystem);

PHP_METHOD(Nc_Storage_FileSystem, __construct);
PHP_METHOD(Nc_Storage_FileSystem, store);
PHP_METHOD(Nc_Storage_FileSystem, remove);
PHP_METHOD(Nc_Storage_FileSystem, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_filesystem___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, baseDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_filesystem_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_filesystem_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_filesystem_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_filesystem_method_entry) {
	PHP_ME(Nc_Storage_FileSystem, __construct, arginfo_nc_storage_filesystem___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Storage_FileSystem, store, arginfo_nc_storage_filesystem_store, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_FileSystem, remove, arginfo_nc_storage_filesystem_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_FileSystem, exists, arginfo_nc_storage_filesystem_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
