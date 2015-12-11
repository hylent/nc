
extern zend_class_entry *nc_netutils_socketclient_ce;

ZEPHIR_INIT_CLASS(Nc_NetUtils_SocketClient);

PHP_METHOD(Nc_NetUtils_SocketClient, __construct);
PHP_METHOD(Nc_NetUtils_SocketClient, __destruct);
PHP_METHOD(Nc_NetUtils_SocketClient, getInternalHandler);
PHP_METHOD(Nc_NetUtils_SocketClient, setTcpNodelay);
PHP_METHOD(Nc_NetUtils_SocketClient, setBlocking);
PHP_METHOD(Nc_NetUtils_SocketClient, setTimeout);
PHP_METHOD(Nc_NetUtils_SocketClient, enableCrypto);
PHP_METHOD(Nc_NetUtils_SocketClient, write);
PHP_METHOD(Nc_NetUtils_SocketClient, readLine);
PHP_METHOD(Nc_NetUtils_SocketClient, readAll);
PHP_METHOD(Nc_NetUtils_SocketClient, readLength);
PHP_METHOD(Nc_NetUtils_SocketClient, readMaxLength);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, connectTimeout)
	ZEND_ARG_INFO(0, persistent)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient_settcpnodelay, 0, 0, 1)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient_setblocking, 0, 0, 1)
	ZEND_ARG_INFO(0, on)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient_settimeout, 0, 0, 1)
	ZEND_ARG_INFO(0, timeout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient_enablecrypto, 0, 0, 1)
	ZEND_ARG_INFO(0, cryptoType)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient_write, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient_readlength, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_socketclient_readmaxlength, 0, 0, 1)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_netutils_socketclient_method_entry) {
	PHP_ME(Nc_NetUtils_SocketClient, __construct, arginfo_nc_netutils_socketclient___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_NetUtils_SocketClient, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_NetUtils_SocketClient, getInternalHandler, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, setTcpNodelay, arginfo_nc_netutils_socketclient_settcpnodelay, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, setBlocking, arginfo_nc_netutils_socketclient_setblocking, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, setTimeout, arginfo_nc_netutils_socketclient_settimeout, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, enableCrypto, arginfo_nc_netutils_socketclient_enablecrypto, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, write, arginfo_nc_netutils_socketclient_write, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, readLine, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, readAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, readLength, arginfo_nc_netutils_socketclient_readlength, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SocketClient, readMaxLength, arginfo_nc_netutils_socketclient_readmaxlength, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
