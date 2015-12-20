
extern zend_class_entry *nc_factory_factoryabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_FactoryAbstract);

PHP_METHOD(Nc_Factory_FactoryAbstract, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryabstract___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_factoryabstract_method_entry) {
	PHP_ME(Nc_Factory_FactoryAbstract, __get, arginfo_nc_factory_factoryabstract___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
