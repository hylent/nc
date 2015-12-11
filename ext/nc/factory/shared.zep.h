
extern zend_class_entry *nc_factory_shared_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Shared);

PHP_METHOD(Nc_Factory_Shared, __construct);
PHP_METHOD(Nc_Factory_Shared, getFactory);
PHP_METHOD(Nc_Factory_Shared, __isset);
PHP_METHOD(Nc_Factory_Shared, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_shared___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, factory, Nc\\Factory\\FactoryInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_shared___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_shared___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_shared_method_entry) {
	PHP_ME(Nc_Factory_Shared, __construct, arginfo_nc_factory_shared___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Factory_Shared, getFactory, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Shared, __isset, arginfo_nc_factory_shared___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Shared, __get, arginfo_nc_factory_shared___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
