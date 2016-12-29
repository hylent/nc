
extern zend_class_entry *nc_loader_namespacedirectory_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_NamespaceDirectory);

PHP_METHOD(Nc_Loader_NamespaceDirectory, __construct);
PHP_METHOD(Nc_Loader_NamespaceDirectory, setNamespaceDirectories);
PHP_METHOD(Nc_Loader_NamespaceDirectory, setNamespaceDirectory);
PHP_METHOD(Nc_Loader_NamespaceDirectory, hasNamespace);
PHP_METHOD(Nc_Loader_NamespaceDirectory, findPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, namespaceDirectories, 1)
	ZEND_ARG_INFO(0, delimiter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory_setnamespacedirectories, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namespaceDirectories, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory_setnamespacedirectory, 0, 0, 2)
	ZEND_ARG_INFO(0, ns)
	ZEND_ARG_INFO(0, dir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory_hasnamespace, 0, 0, 1)
	ZEND_ARG_INFO(0, ns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namespacedirectory_findpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_namespacedirectory_method_entry) {
	PHP_ME(Nc_Loader_NamespaceDirectory, __construct, arginfo_nc_loader_namespacedirectory___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Loader_NamespaceDirectory, setNamespaceDirectories, arginfo_nc_loader_namespacedirectory_setnamespacedirectories, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_NamespaceDirectory, setNamespaceDirectory, arginfo_nc_loader_namespacedirectory_setnamespacedirectory, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_NamespaceDirectory, hasNamespace, arginfo_nc_loader_namespacedirectory_hasnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_NamespaceDirectory, findPath, arginfo_nc_loader_namespacedirectory_findpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
