
extern zend_class_entry *nc_di_creatorclassprefix_ce;

ZEPHIR_INIT_CLASS(Nc_Di_CreatorClassPrefix);

PHP_METHOD(Nc_Di_CreatorClassPrefix, __construct);
PHP_METHOD(Nc_Di_CreatorClassPrefix, getValidClassName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorclassprefix___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, classPrefix)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorclassprefix_getvalidclassname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_creatorclassprefix_method_entry) {
	PHP_ME(Nc_Di_CreatorClassPrefix, __construct, arginfo_nc_di_creatorclassprefix___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Di_CreatorClassPrefix, getValidClassName, arginfo_nc_di_creatorclassprefix_getvalidclassname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
