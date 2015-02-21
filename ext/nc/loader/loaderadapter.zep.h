
extern zend_class_entry *nc_loader_loaderadapter_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_LoaderAdapter);

PHP_METHOD(Nc_Loader_LoaderAdapter, register);
PHP_METHOD(Nc_Loader_LoaderAdapter, unregister);

ZEPHIR_INIT_FUNCS(nc_loader_loaderadapter_method_entry) {
	PHP_ME(Nc_Loader_LoaderAdapter, register, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_LoaderAdapter, unregister, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
