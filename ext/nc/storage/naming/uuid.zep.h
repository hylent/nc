
extern zend_class_entry *nc_storage_naming_uuid_ce;

ZEPHIR_INIT_CLASS(Nc_Storage_Naming_Uuid);

PHP_METHOD(Nc_Storage_Naming_Uuid, generateName);

ZEPHIR_INIT_FUNCS(nc_storage_naming_uuid_method_entry) {
	PHP_ME(Nc_Storage_Naming_Uuid, generateName, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
