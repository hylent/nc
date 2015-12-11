
extern zend_class_entry *nc_netutils_smtpmailer_ce;

ZEPHIR_INIT_CLASS(Nc_NetUtils_SmtpMailer);

PHP_METHOD(Nc_NetUtils_SmtpMailer, __construct);
PHP_METHOD(Nc_NetUtils_SmtpMailer, getSocket);
PHP_METHOD(Nc_NetUtils_SmtpMailer, sendMessageTo);
PHP_METHOD(Nc_NetUtils_SmtpMailer, __destruct);
PHP_METHOD(Nc_NetUtils_SmtpMailer, cmd);
PHP_METHOD(Nc_NetUtils_SmtpMailer, pack);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtpmailer___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtpmailer_sendmessageto, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, message, 0)
	ZEND_ARG_ARRAY_INFO(0, to, 0)
	ZEND_ARG_ARRAY_INFO(0, cc, 1)
	ZEND_ARG_ARRAY_INFO(0, bcc, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtpmailer_cmd, 0, 0, 3)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, cmd)
	ZEND_ARG_INFO(0, expected)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_netutils_smtpmailer_pack, 0, 0, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, addr)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_netutils_smtpmailer_method_entry) {
	PHP_ME(Nc_NetUtils_SmtpMailer, __construct, arginfo_nc_netutils_smtpmailer___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_NetUtils_SmtpMailer, getSocket, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SmtpMailer, sendMessageTo, arginfo_nc_netutils_smtpmailer_sendmessageto, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_NetUtils_SmtpMailer, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_NetUtils_SmtpMailer, cmd, arginfo_nc_netutils_smtpmailer_cmd, ZEND_ACC_PROTECTED)
	PHP_ME(Nc_NetUtils_SmtpMailer, pack, arginfo_nc_netutils_smtpmailer_pack, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
