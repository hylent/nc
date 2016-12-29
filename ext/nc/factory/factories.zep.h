
extern zend_class_entry *nc_factory_factories_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Factories);

PHP_METHOD(Nc_Factory_Factories, offsetSet);
PHP_METHOD(Nc_Factory_Factories, offsetGet);
PHP_METHOD(Nc_Factory_Factories, offsetExists);
PHP_METHOD(Nc_Factory_Factories, offsetUnset);
PHP_METHOD(Nc_Factory_Factories, __isset);
PHP_METHOD(Nc_Factory_Factories, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factories_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, factory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factories_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factories_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factories_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factories___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_factories___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_factories_method_entry) {
	PHP_ME(Nc_Factory_Factories, offsetSet, arginfo_nc_factory_factories_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Factories, offsetGet, arginfo_nc_factory_factories_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Factories, offsetExists, arginfo_nc_factory_factories_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Factories, offsetUnset, arginfo_nc_factory_factories_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Factories, __isset, arginfo_nc_factory_factories___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Factories, __get, arginfo_nc_factory_factories___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
