
extern zend_class_entry *nc_di_creatorclassmapper_ce;

ZEPHIR_INIT_CLASS(Nc_Di_CreatorClassMapper);

PHP_METHOD(Nc_Di_CreatorClassMapper, __construct);
PHP_METHOD(Nc_Di_CreatorClassMapper, getValidClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorclassmapper___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, classMapper, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorclassmapper_getvalidclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_creatorclassmapper_method_entry) {
	PHP_ME(Nc_Di_CreatorClassMapper, __construct, arginfo_nc_di_creatorclassmapper___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Di_CreatorClassMapper, getValidClassName, arginfo_nc_di_creatorclassmapper_getvalidclassname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
