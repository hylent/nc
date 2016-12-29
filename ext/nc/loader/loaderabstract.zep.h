
extern zend_class_entry *nc_loader_loaderabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_LoaderAbstract);

PHP_METHOD(Nc_Loader_LoaderAbstract, register);
PHP_METHOD(Nc_Loader_LoaderAbstract, unregister);
PHP_METHOD(Nc_Loader_LoaderAbstract, __invoke);
PHP_METHOD(Nc_Loader_LoaderAbstract, getLoadedNamePaths);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaderabstract_register, 0, 0, 0)
	ZEND_ARG_INFO(0, prepend)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaderabstract___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_loaderabstract_method_entry) {
	PHP_ME(Nc_Loader_LoaderAbstract, register, arginfo_nc_loader_loaderabstract_register, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_LoaderAbstract, unregister, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_LoaderAbstract, __invoke, arginfo_nc_loader_loaderabstract___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_LoaderAbstract, getLoadedNamePaths, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
