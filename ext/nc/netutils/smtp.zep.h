
extern zend_class_entry *nc_netutils_smtp_ce;

ZEPHIR_INIT_CLASS(Nc_NetUtils_Smtp);

PHP_METHOD(Nc_NetUtils_Smtp, pack);
PHP_METHOD(Nc_NetUtils_Smtp, __construct);
PHP_METHOD(Nc_NetUtils_Smtp, getTcpSocketClient);
PHP_METHOD(Nc_NetUtils_Smtp, sendMessageTo);
PHP_METHOD(Nc_NetUtils_Smtp, __destruct);
PHP_METHOD(Nc_NetUtils_Smtp, cmd);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtp_pack, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, addr)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtp___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtp_sendmessageto, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
	ZEND_ARG_ARRAY_INFO(0, to, 0)
	ZEND_ARG_ARRAY_INFO(0, cc, 1)
	ZEND_ARG_ARRAY_INFO(0, bcc, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtp_cmd, 0, 0, 3)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, cmd)
	ZEND_ARG_INFO(0, expected)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_netutils_smtp_method_entry) {
	PHP_ME(Nc_NetUtils_Smtp, pack, arginfo_nc_netutils_smtp_pack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Nc_NetUtils_Smtp, __construct, arginfo_nc_netutils_smtp___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_NetUtils_Smtp, getTcpSocketClient, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_Smtp, sendMessageTo, arginfo_nc_netutils_smtp_sendmessageto, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_Smtp, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_NetUtils_Smtp, cmd, arginfo_nc_netutils_smtp_cmd, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
