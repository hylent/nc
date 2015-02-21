
extern zend_class_entry *nc_storage_backend_storagebackendadapter_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_Backend_StorageBackendAdapter);

PHP_METHOD(Nc_Storage_Backend_StorageBackendAdapter, setStorageNamePolicy);
PHP_METHOD(Nc_Storage_Backend_StorageBackendAdapter, getStorageNamePolicy);
PHP_METHOD(Nc_Storage_Backend_StorageBackendAdapter, generateUri);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_backend_storagebackendadapter_setstoragenamepolicy, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, storageNamePolicy, Nc\\Storage\\NamePolicy\\StorageNamePolicyInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_backend_storagebackendadapter_generateuri, 0, 0, 3)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, extension)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_backend_storagebackendadapter_method_entry) {
	PHP_ME(Nc_Storage_Backend_StorageBackendAdapter, setStorageNamePolicy, arginfo_nc_storage_backend_storagebackendadapter_setstoragenamepolicy, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Backend_StorageBackendAdapter, getStorageNamePolicy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Storage_Backend_StorageBackendAdapter, generateUri, arginfo_nc_storage_backend_storagebackendadapter_generateuri, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
