
extern zend_class_entry *nc_mvc_controllerinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_ControllerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_controllerinterface___invoke, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, injector, Nc\\Di\\Injector, 0)
	ZEND_ARG_OBJ_INFO(0, context, Nc\\Mvc\\ContextAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_controllerinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Mvc_ControllerInterface, __invoke, arginfo_nc_mvc_controllerinterface___invoke)
	PHP_FE_END
};
