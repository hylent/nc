
extern zend_class_entry *nc_upload_storageabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Upload_StorageAbstract);

PHP_METHOD(Nc_Upload_StorageAbstract, setUriGenerator);
PHP_METHOD(Nc_Upload_StorageAbstract, getUriGenerator);
PHP_METHOD(Nc_Upload_StorageAbstract, store);
PHP_METHOD(Nc_Upload_StorageAbstract, remove);
PHP_METHOD(Nc_Upload_StorageAbstract, exists);
PHP_METHOD(Nc_Upload_StorageAbstract, generateUri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_storageabstract_seturigenerator, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, uriGenerator, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_storageabstract_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, flag)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_storageabstract_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_storageabstract_exists, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_upload_storageabstract_generateuri, 0, 0, 3)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, prefix)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_upload_storageabstract_method_entry) {
	PHP_ME(Nc_Upload_StorageAbstract, setUriGenerator, arginfo_nc_upload_storageabstract_seturigenerator, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Upload_StorageAbstract, getUriGenerator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Upload_StorageAbstract, store, arginfo_nc_upload_storageabstract_store, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Upload_StorageAbstract, remove, arginfo_nc_upload_storageabstract_remove, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Upload_StorageAbstract, exists, arginfo_nc_upload_storageabstract_exists, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Upload_StorageAbstract, generateUri, arginfo_nc_upload_storageabstract_generateuri, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
