
extern zend_class_entry *nc_application_controllerabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Application_ControllerAbstract);

PHP_METHOD(Nc_Application_ControllerAbstract, dispatch);
PHP_METHOD(Nc_Application_ControllerAbstract, __construct);
PHP_METHOD(Nc_Application_ControllerAbstract, __invoke);
PHP_METHOD(Nc_Application_ControllerAbstract, getServer);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstract_dispatch, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, controllerFactory, Nc\\Factory\\FactoryInterface, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstract___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Nc\\Factory\\FactoryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstract___invoke, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_controllerabstract_getserver, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_application_controllerabstract_method_entry) {
	PHP_ME(Nc_Application_ControllerAbstract, dispatch, arginfo_nc_application_controllerabstract_dispatch, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Application_ControllerAbstract, __construct, arginfo_nc_application_controllerabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Application_ControllerAbstract, __invoke, arginfo_nc_application_controllerabstract___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application_ControllerAbstract, getServer, arginfo_nc_application_controllerabstract_getserver, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
