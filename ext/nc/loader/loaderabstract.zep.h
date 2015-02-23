
extern zend_class_entry *nc_loader_loaderabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_LoaderAbstract);

PHP_METHOD(Nc_Loader_LoaderAbstract, register);
PHP_METHOD(Nc_Loader_LoaderAbstract, unregister);

ZEPHIR_INIT_FUNCS(nc_loader_loaderabstract_method_entry) {
	PHP_ME(Nc_Loader_LoaderAbstract, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_LoaderAbstract, unregister, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
