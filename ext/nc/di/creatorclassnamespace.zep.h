
extern zend_class_entry *nc_di_creatorclassnamespace_ce;

ZEPHIR_INIT_CLASS(Nc_Di_CreatorClassNamespace);

PHP_METHOD(Nc_Di_CreatorClassNamespace, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_di_creatorclassnamespace___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, classNamespace)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_di_creatorclassnamespace_method_entry) {
	PHP_ME(Nc_Di_CreatorClassNamespace, __construct, arginfo_nc_di_creatorclassnamespace___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
