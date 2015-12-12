
extern zend_class_entry *nc_router_action_ce;

ZEPHIR_INIT_CLASS(Nc_Router_Action);

PHP_METHOD(Nc_Router_Action, __construct);
PHP_METHOD(Nc_Router_Action, getActionFactory);
PHP_METHOD(Nc_Router_Action, setDefaultAction);
PHP_METHOD(Nc_Router_Action, getDefaultAction);
PHP_METHOD(Nc_Router_Action, route);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_action___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, actionFactory, Nc\\Factory\\FactoryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_action_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAction)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_router_action_method_entry) {
	PHP_ME(Nc_Router_Action, __construct, arginfo_nc_router_action___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Router_Action, getActionFactory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_Action, setDefaultAction, arginfo_nc_router_action_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_Action, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_Action, route, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
