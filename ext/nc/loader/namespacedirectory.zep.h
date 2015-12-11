
extern zend_class_entry *nc_loader_namespacedirectory_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_NamespaceDirectory);

PHP_METHOD(Nc_Loader_NamespaceDirectory, __construct);
PHP_METHOD(Nc_Loader_NamespaceDirectory, __invoke);
PHP_METHOD(Nc_Loader_NamespaceDirectory, set);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, registerSelf)
	ZEND_ARG_ARRAY_INFO(0, namespaceDirectories, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory___invoke, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory_set, 0, 0, 2)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_namespacedirectory_method_entry) {
	PHP_ME(Nc_Loader_NamespaceDirectory, __construct, arginfo_nc_loader_namespacedirectory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Loader_NamespaceDirectory, __invoke, arginfo_nc_loader_namespacedirectory___invoke, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_NamespaceDirectory, set, arginfo_nc_loader_namespacedirectory_set, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
