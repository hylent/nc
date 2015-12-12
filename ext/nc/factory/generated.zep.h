
extern zend_class_entry *nc_factory_generated_ce;

ZEPHIR_INIT_CLASS(Nc_Factory_Generated);

PHP_METHOD(Nc_Factory_Generated, __construct);
PHP_METHOD(Nc_Factory_Generated, getClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_generated___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, classNameGenerator, Closure, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_factory_generated_getclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_factory_generated_method_entry) {
	PHP_ME(Nc_Factory_Generated, __construct, arginfo_nc_factory_generated___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Factory_Generated, getClassName, arginfo_nc_factory_generated_getclassname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
