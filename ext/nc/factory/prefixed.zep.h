
extern zend_class_entry *nc_factory_prefixed_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Prefixed);

PHP_METHOD(Nc_Factory_Prefixed, __construct);
PHP_METHOD(Nc_Factory_Prefixed, getClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_prefixed___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, prefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_prefixed_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_prefixed_method_entry) {
	PHP_ME(Nc_Factory_Prefixed, __construct, arginfo_nc_factory_prefixed___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Factory_Prefixed, getClassName, arginfo_nc_factory_prefixed_getclassname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
