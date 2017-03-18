
extern zend_class_entry *nc_mvc_contexthttpswoole_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_ContextHttpSwoole);

PHP_METHOD(Nc_Mvc_ContextHttpSwoole, __construct);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getRoutingNames);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getSwooleRequest);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getSwooleResponse);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, getRawInput);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, status);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, cookie);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, header);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, sendFile);
PHP_METHOD(Nc_Mvc_ContextHttpSwoole, output);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttpswoole___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, swooleRequest, Swoole_Http_Request, 0)
	ZEND_ARG_OBJ_INFO(0, swooleResponse, Swoole_Http_Response, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttpswoole_status, 0, 0, 1)
	ZEND_ARG_INFO(0, status)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttpswoole_cookie, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttpswoole_header, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttpswoole_sendfile, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contexthttpswoole_output, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_contexthttpswoole_method_entry) {
	PHP_ME(Nc_Mvc_ContextHttpSwoole, __construct, arginfo_nc_mvc_contexthttpswoole___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, getRoutingNames, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, getSwooleRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, getSwooleResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, getRawInput, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, status, arginfo_nc_mvc_contexthttpswoole_status, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, cookie, arginfo_nc_mvc_contexthttpswoole_cookie, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, header, arginfo_nc_mvc_contexthttpswoole_header, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, sendFile, arginfo_nc_mvc_contexthttpswoole_sendfile, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextHttpSwoole, output, arginfo_nc_mvc_contexthttpswoole_output, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
