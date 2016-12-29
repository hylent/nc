
extern zend_class_entry *nc_factory_factoryabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_FactoryAbstract);

PHP_METHOD(Nc_Factory_FactoryAbstract, onCreated);
PHP_METHOD(Nc_Factory_FactoryAbstract, __isset);
PHP_METHOD(Nc_Factory_FactoryAbstract, __get);
PHP_METHOD(Nc_Factory_FactoryAbstract, create);
PHP_METHOD(Nc_Factory_FactoryAbstract, createInternally);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryabstract_oncreated, 0, 0, 0)
	ZEND_ARG_INFO(0, onCreated)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryabstract___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryabstract___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryabstract_create, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, shared)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factoryabstract_createinternally, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_factoryabstract_method_entry) {
	PHP_ME(Nc_Factory_FactoryAbstract, onCreated, arginfo_nc_factory_factoryabstract_oncreated, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_FactoryAbstract, __isset, arginfo_nc_factory_factoryabstract___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_FactoryAbstract, __get, arginfo_nc_factory_factoryabstract___get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_FactoryAbstract, create, arginfo_nc_factory_factoryabstract_create, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_FactoryAbstract, createInternally, arginfo_nc_factory_factoryabstract_createinternally, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
