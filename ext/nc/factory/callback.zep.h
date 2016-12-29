
extern zend_class_entry *nc_factory_callback_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Callback);

PHP_METHOD(Nc_Factory_Callback, __invoke);
PHP_METHOD(Nc_Factory_Callback, __isset);
PHP_METHOD(Nc_Factory_Callback, createInternally);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_callback___invoke, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_callback___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_callback_createinternally, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_callback_method_entry) {
	PHP_ME(Nc_Factory_Callback, __invoke, arginfo_nc_factory_callback___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Callback, __isset, arginfo_nc_factory_callback___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Factory_Callback, createInternally, arginfo_nc_factory_callback_createinternally, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
