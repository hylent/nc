
extern zend_class_entry *nc_loader_loaderinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_LoaderInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaderinterface___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_loaderinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Loader_LoaderInterface, register, NULL)
	PHP_ABSTRACT_ME(Nc_Loader_LoaderInterface, unregister, NULL)
	PHP_ABSTRACT_ME(Nc_Loader_LoaderInterface, __invoke, arginfo_nc_loader_loaderinterface___invoke)
  PHP_FE_END
};
