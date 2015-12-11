
extern zend_class_entry *nc_upload_fastdfs_ce;

ZEPHIR_INIT_CLASS(Nc_Upload_Fastdfs);

PHP_METHOD(Nc_Upload_Fastdfs, __construct);
PHP_METHOD(Nc_Upload_Fastdfs, store);
PHP_METHOD(Nc_Upload_Fastdfs, remove);
PHP_METHOD(Nc_Upload_Fastdfs, exists);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_fastdfs___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, prefixGroups, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_fastdfs_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_fastdfs_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_fastdfs_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_upload_fastdfs_method_entry) {
	PHP_ME(Nc_Upload_Fastdfs, __construct, arginfo_nc_upload_fastdfs___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Upload_Fastdfs, store, arginfo_nc_upload_fastdfs_store, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Upload_Fastdfs, remove, arginfo_nc_upload_fastdfs_remove, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Upload_Fastdfs, exists, arginfo_nc_upload_fastdfs_exists, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
