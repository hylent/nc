
extern zend_class_entry *nc_messager_messagerinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Messager_MessagerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_messager_messagerinterface_send, 0, 0, 3)
	ZEND_ARG_INFO(0, to)
	ZEND_ARG_INFO(0, subject)
	ZEND_ARG_INFO(0, message)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_messager_messagerinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Messager_MessagerInterface, send, arginfo_nc_messager_messagerinterface_send)
	PHP_FE_END
};
