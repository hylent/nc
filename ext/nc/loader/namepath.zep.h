
extern zend_class_entry *nc_loader_namepath_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_NamePath);

PHP_METHOD(Nc_Loader_NamePath, __construct);
PHP_METHOD(Nc_Loader_NamePath, setNamePaths);
PHP_METHOD(Nc_Loader_NamePath, setNamePath);
PHP_METHOD(Nc_Loader_NamePath, hasName);
PHP_METHOD(Nc_Loader_NamePath, findPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namepath___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, namePaths, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namepath_setnamepaths, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, namePaths, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namepath_setnamepath, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namepath_hasname, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_namepath_findpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_namepath_method_entry) {
	PHP_ME(Nc_Loader_NamePath, __construct, arginfo_nc_loader_namepath___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Loader_NamePath, setNamePaths, arginfo_nc_loader_namepath_setnamepaths, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_NamePath, setNamePath, arginfo_nc_loader_namepath_setnamepath, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_NamePath, hasName, arginfo_nc_loader_namepath_hasname, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_NamePath, findPath, arginfo_nc_loader_namepath_findpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
