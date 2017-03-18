
extern zend_class_entry *nc_di_injectedsetupmethodinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Di_InjectedSetupMethodInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_injectedsetupmethodinterface_setupbyinjector, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, injector, Nc\\Di\\Injector, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_injectedsetupmethodinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Di_InjectedSetupMethodInterface, setupByInjector, arginfo_nc_di_injectedsetupmethodinterface_setupbyinjector)
	PHP_FE_END
};
