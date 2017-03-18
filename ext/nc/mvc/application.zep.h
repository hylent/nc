
extern zend_class_entry *nc_mvc_application_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_Application);

PHP_METHOD(Nc_Mvc_Application, autoloadCompareFunction);
PHP_METHOD(Nc_Mvc_Application, __construct);
PHP_METHOD(Nc_Mvc_Application, __destruct);
PHP_METHOD(Nc_Mvc_Application, autoload);
PHP_METHOD(Nc_Mvc_Application, __invoke);
PHP_METHOD(Nc_Mvc_Application, onSwooleRequest);
PHP_METHOD(Nc_Mvc_Application, route);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_application_autoloadcomparefunction, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_application___construct, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, autoloads, 0)
	ZEND_ARG_ARRAY_INFO(0, routingRules, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_application_autoload, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_application___invoke, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, context, Nc\\Mvc\\ContextAbstract, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_application_onswoolerequest, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, req, Swoole_Http_Request, 0)
	ZEND_ARG_OBJ_INFO(0, resp, Swoole_Http_Response, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_application_route, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, context, Nc\\Mvc\\ContextAbstract, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_application_method_entry) {
	PHP_ME(Nc_Mvc_Application, autoloadCompareFunction, arginfo_nc_mvc_application_autoloadcomparefunction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_Mvc_Application, __construct, arginfo_nc_mvc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Mvc_Application, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_Mvc_Application, autoload, arginfo_nc_mvc_application_autoload, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_Application, __invoke, arginfo_nc_mvc_application___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_Application, onSwooleRequest, arginfo_nc_mvc_application_onswoolerequest, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_Application, route, arginfo_nc_mvc_application_route, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
