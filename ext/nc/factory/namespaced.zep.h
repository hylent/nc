
extern zend_class_entry *nc_factory_namespaced_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Namespaced);

PHP_METHOD(Nc_Factory_Namespaced, __construct);
PHP_METHOD(Nc_Factory_Namespaced, getClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_namespaced___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, ns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_namespaced_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_namespaced_method_entry) {
	PHP_ME(Nc_Factory_Namespaced, __construct, arginfo_nc_factory_namespaced___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Factory_Namespaced, getClassName, arginfo_nc_factory_namespaced_getclassname, ZEND_ACC_PROTECTED)
	PHP_FE_END
};