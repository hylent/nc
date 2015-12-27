
extern zend_class_entry *nc_router_controlleraction_ce;

ZEPHIR_INIT_CLASS(Nc_Router_ControllerAction);

PHP_METHOD(Nc_Router_ControllerAction, __construct);
PHP_METHOD(Nc_Router_ControllerAction, getControllerFactory);
PHP_METHOD(Nc_Router_ControllerAction, setDefaultController);
PHP_METHOD(Nc_Router_ControllerAction, getDefaultController);
PHP_METHOD(Nc_Router_ControllerAction, setDefaultAction);
PHP_METHOD(Nc_Router_ControllerAction, getDefaultAction);
PHP_METHOD(Nc_Router_ControllerAction, setActionSuffix);
PHP_METHOD(Nc_Router_ControllerAction, getActionSuffix);
PHP_METHOD(Nc_Router_ControllerAction, route);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_controlleraction___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, controllerFactory, Nc\\Factory\\FactoryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_controlleraction_setdefaultcontroller, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultController)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_controlleraction_setdefaultaction, 0, 0, 1)
	ZEND_ARG_INFO(0, defaultAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_controlleraction_setactionsuffix, 0, 0, 1)
	ZEND_ARG_INFO(0, actionSuffix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_controlleraction_route, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_router_controlleraction_method_entry) {
	PHP_ME(Nc_Router_ControllerAction, __construct, arginfo_nc_router_controlleraction___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Router_ControllerAction, getControllerFactory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_ControllerAction, setDefaultController, arginfo_nc_router_controlleraction_setdefaultcontroller, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_ControllerAction, getDefaultController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_ControllerAction, setDefaultAction, arginfo_nc_router_controlleraction_setdefaultaction, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_ControllerAction, getDefaultAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_ControllerAction, setActionSuffix, arginfo_nc_router_controlleraction_setactionsuffix, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_ControllerAction, getActionSuffix, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_ControllerAction, route, arginfo_nc_router_controlleraction_route, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
