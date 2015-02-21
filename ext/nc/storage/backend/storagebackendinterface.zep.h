
extern zend_class_entry *nc_storage_backend_storagebackendinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_Backend_StorageBackendInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_backend_storagebackendinterface_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, mv)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_backend_storagebackendinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_backend_storagebackendinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Storage_Backend_StorageBackendInterface, store, arginfo_nc_storage_backend_storagebackendinterface_store)
	PHP_ABSTRACT_ME(Nc_Storage_Backend_StorageBackendInterface, remove, arginfo_nc_storage_backend_storagebackendinterface_remove)
  PHP_FE_END
};
