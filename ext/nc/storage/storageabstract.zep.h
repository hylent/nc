
extern zend_class_entry *nc_storage_storageabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_StorageAbstract);

PHP_METHOD(Nc_Storage_StorageAbstract, setStorageNaming);
PHP_METHOD(Nc_Storage_StorageAbstract, getStorageNaming);
PHP_METHOD(Nc_Storage_StorageAbstract, generateUri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_storageabstract_setstoragenaming, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storageNaming, Nc\\Storage\\Naming\\StorageNamingInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_storageabstract_generateuri, 0, 0, 3)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_storageabstract_method_entry) {
	PHP_ME(Nc_Storage_StorageAbstract, setStorageNaming, arginfo_nc_storage_storageabstract_setstoragenaming, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_StorageAbstract, getStorageNaming, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_StorageAbstract, generateUri, arginfo_nc_storage_storageabstract_generateuri, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
