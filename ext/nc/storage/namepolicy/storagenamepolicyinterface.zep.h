
extern zend_class_entry *nc_storage_namepolicy_storagenamepolicyinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_NamePolicy_StorageNamePolicyInterface);

ZEPHIR_INIT_FUNCS(nc_storage_namepolicy_storagenamepolicyinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Storage_NamePolicy_StorageNamePolicyInterface, generateName, NULL)
  PHP_FE_END
};