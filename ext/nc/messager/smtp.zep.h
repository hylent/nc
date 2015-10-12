
extern zend_class_entry *nc_messager_smtp_ce;

ZEPHIR_INIT_CLASS(Nc_Messager_Smtp);

PHP_METHOD(Nc_Messager_Smtp, __construct);
PHP_METHOD(Nc_Messager_Smtp, __destruct);
PHP_METHOD(Nc_Messager_Smtp, send);
PHP_METHOD(Nc_Messager_Smtp, doCommand);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_messager_smtp___construct, 0, 0, 5)
	ZEND_ARG_INFO(0, host)
	ZEND_ARG_INFO(0, port)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_INFO(0, passwd)
	ZEND_ARG_INFO(0, from)
	ZEND_ARG_INFO(0, sender)
	ZEND_ARG_INFO(0, preSubject)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_messager_smtp_send, 0, 0, 3)
	ZEND_ARG_INFO(0, to)
	ZEND_ARG_INFO(0, subject)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_messager_smtp_docommand, 0, 0, 3)
	ZEND_ARG_INFO(0, step)
	ZEND_ARG_INFO(0, command)
	ZEND_ARG_INFO(0, validResult)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_messager_smtp_method_entry) {
	PHP_ME(Nc_Messager_Smtp, __construct, arginfo_nc_messager_smtp___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Messager_Smtp, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(Nc_Messager_Smtp, send, arginfo_nc_messager_smtp_send, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Messager_Smtp, doCommand, arginfo_nc_messager_smtp_docommand, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
