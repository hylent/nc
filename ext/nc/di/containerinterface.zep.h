
extern zend_class_entry *nc_di_containerinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Di_ContainerInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_containerinterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_containerinterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_containerinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Di_ContainerInterface, __isset, arginfo_nc_di_containerinterface___isset)
	PHP_ABSTRACT_ME(Nc_Di_ContainerInterface, __get, arginfo_nc_di_containerinterface___get)
	PHP_FE_END
};
