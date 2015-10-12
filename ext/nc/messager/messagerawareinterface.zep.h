
extern zend_class_entry *nc_messager_messagerawareinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Messager_MessagerAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_messager_messagerawareinterface_setmessager, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, messager, Nc\\Messager\\MessagerInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_messager_messagerawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Messager_MessagerAwareInterface, setMessager, arginfo_nc_messager_messagerawareinterface_setmessager)
	PHP_ABSTRACT_ME(Nc_Messager_MessagerAwareInterface, getMessager, NULL)
	PHP_FE_END
};
