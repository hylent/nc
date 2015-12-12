
extern zend_class_entry *nc_factory_factoryinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_FactoryInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryinterface___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryinterface___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryinterface_newproduction, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_factoryinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Factory_FactoryInterface, __isset, arginfo_nc_factory_factoryinterface___isset)
	PHP_ABSTRACT_ME(Nc_Factory_FactoryInterface, __get, arginfo_nc_factory_factoryinterface___get)
	PHP_ABSTRACT_ME(Nc_Factory_FactoryInterface, newProduction, arginfo_nc_factory_factoryinterface_newproduction)
	PHP_FE_END
};
