
extern zend_class_entry *nc_loader_classpath_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_ClassPath);

PHP_METHOD(Nc_Loader_ClassPath, __construct);
PHP_METHOD(Nc_Loader_ClassPath, __invoke);
PHP_METHOD(Nc_Loader_ClassPath, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_classpath___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, classPaths, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_classpath___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, className)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_classpath_set, 0, 0, 2)
	ZEND_ARG_INFO(0, className)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_classpath_method_entry) {
	PHP_ME(Nc_Loader_ClassPath, __construct, arginfo_nc_loader_classpath___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Loader_ClassPath, __invoke, arginfo_nc_loader_classpath___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_ClassPath, set, arginfo_nc_loader_classpath_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
