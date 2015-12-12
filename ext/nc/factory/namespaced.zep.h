
extern zend_class_entry *nc_factory_namespaced_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Namespaced);

PHP_METHOD(Nc_Factory_Namespaced, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_namespaced___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, ns)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_namespaced_method_entry) {
	PHP_ME(Nc_Factory_Namespaced, __construct, arginfo_nc_factory_namespaced___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
