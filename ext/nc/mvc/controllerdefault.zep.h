
extern zend_class_entry *nc_mvc_controllerdefault_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_ControllerDefault);

PHP_METHOD(Nc_Mvc_ControllerDefault, __invoke);
PHP_METHOD(Nc_Mvc_ControllerDefault, initialize);
PHP_METHOD(Nc_Mvc_ControllerDefault, execute);
PHP_METHOD(Nc_Mvc_ControllerDefault, onReturn);
PHP_METHOD(Nc_Mvc_ControllerDefault, onException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_controllerdefault___invoke, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, injector, Nc\\Di\\Injector, 0)
	ZEND_ARG_OBJ_INFO(0, context, Nc\\Mvc\\ContextAbstract, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_controllerdefault_onreturn, 0, 0, 1)
	ZEND_ARG_INFO(0, re)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_controllerdefault_onexception, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, ex, Exception, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_controllerdefault_method_entry) {
	PHP_ME(Nc_Mvc_ControllerDefault, __invoke, arginfo_nc_mvc_controllerdefault___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ControllerDefault, initialize, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Mvc_ControllerDefault, execute, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Mvc_ControllerDefault, onReturn, arginfo_nc_mvc_controllerdefault_onreturn, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_Mvc_ControllerDefault, onException, arginfo_nc_mvc_controllerdefault_onexception, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
