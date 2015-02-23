
extern zend_class_entry *nc_storage_storageinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_StorageInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_storageinterface_store, 0, 0, 1)
	ZEND_ARG_INFO(0, source)
	ZEND_ARG_INFO(0, group)
	ZEND_ARG_INFO(0, extension)
	ZEND_ARG_INFO(0, rm)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_storage_storageinterface_remove, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_storage_storageinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Storage_StorageInterface, store, arginfo_nc_storage_storageinterface_store)
	PHP_ABSTRACT_ME(Nc_Storage_StorageInterface, remove, arginfo_nc_storage_storageinterface_remove)
  PHP_FE_END
};
