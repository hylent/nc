
extern zend_class_entry *nc_storage_ftp_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_Ftp);

PHP_METHOD(Nc_Storage_Ftp, __construct);
PHP_METHOD(Nc_Storage_Ftp, getInternalHandler);
PHP_METHOD(Nc_Storage_Ftp, store);
PHP_METHOD(Nc_Storage_Ftp, remove);
PHP_METHOD(Nc_Storage_Ftp, exists);
PHP_METHOD(Nc_Storage_Ftp, __destruct);
PHP_METHOD(Nc_Storage_Ftp, mkDirIfNotExists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_ftp___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_ftp_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_ftp_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_ftp_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_ftp_mkdirifnotexists, 0, 0, 1)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_ftp_method_entry) {
	PHP_ME(Nc_Storage_Ftp, __construct, arginfo_nc_storage_ftp___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Storage_Ftp, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Ftp, store, arginfo_nc_storage_ftp_store, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Ftp, remove, arginfo_nc_storage_ftp_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Ftp, exists, arginfo_nc_storage_ftp_exists, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Ftp, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_Storage_Ftp, mkDirIfNotExists, arginfo_nc_storage_ftp_mkdirifnotexists, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
