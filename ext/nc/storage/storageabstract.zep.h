
extern zend_class_entry *nc_storage_storageabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_StorageAbstract);

PHP_METHOD(Nc_Storage_StorageAbstract, uuid);
PHP_METHOD(Nc_Storage_StorageAbstract, setUriGenerator);
PHP_METHOD(Nc_Storage_StorageAbstract, getUriGenerator);
PHP_METHOD(Nc_Storage_StorageAbstract, generateUri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_storageabstract_uuid, 0, 0, 0)
	ZEND_ARG_INFO(0, salt)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_storageabstract_seturigenerator, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, uriGenerator, Nc\\Storage\\UriGeneratorInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_storageabstract_generateuri, 0, 0, 3)
	ZEND_ARG_INFO(0, src)
	ZEND_ARG_INFO(0, pre)
	ZEND_ARG_INFO(0, ext)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_storageabstract_method_entry) {
	PHP_ME(Nc_Storage_StorageAbstract, uuid, arginfo_nc_storage_storageabstract_uuid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Storage_StorageAbstract, setUriGenerator, arginfo_nc_storage_storageabstract_seturigenerator, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_StorageAbstract, getUriGenerator, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_StorageAbstract, generateUri, arginfo_nc_storage_storageabstract_generateuri, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
