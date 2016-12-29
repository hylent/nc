
extern zend_class_entry *nc_netutils_tcpsocketclient_ce;

ZEPHIR_INIT_CLASS(Nc_NetUtils_TcpSocketClient);

PHP_METHOD(Nc_NetUtils_TcpSocketClient, __construct);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, __destruct);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, getInternalHandler);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, setTcpNodelay);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, setBlocking);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, setTimeout);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, enableCrypto);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, write);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, readLine);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, readAll);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, readLength);
PHP_METHOD(Nc_NetUtils_TcpSocketClient, readMaxLength);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, options, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient_settcpnodelay, 0, 0, 1)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient_setblocking, 0, 0, 1)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient_settimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient_enablecrypto, 0, 0, 1)
	ZEND_ARG_INFO(0, cryptoType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient_readlength, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_tcpsocketclient_readmaxlength, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_netutils_tcpsocketclient_method_entry) {
	PHP_ME(Nc_NetUtils_TcpSocketClient, __construct, arginfo_nc_netutils_tcpsocketclient___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_NetUtils_TcpSocketClient, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_NetUtils_TcpSocketClient, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, setTcpNodelay, arginfo_nc_netutils_tcpsocketclient_settcpnodelay, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, setBlocking, arginfo_nc_netutils_tcpsocketclient_setblocking, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, setTimeout, arginfo_nc_netutils_tcpsocketclient_settimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, enableCrypto, arginfo_nc_netutils_tcpsocketclient_enablecrypto, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, write, arginfo_nc_netutils_tcpsocketclient_write, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, readLine, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, readAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, readLength, arginfo_nc_netutils_tcpsocketclient_readlength, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_TcpSocketClient, readMaxLength, arginfo_nc_netutils_tcpsocketclient_readmaxlength, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
