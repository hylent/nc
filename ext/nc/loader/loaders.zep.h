
extern zend_class_entry *nc_loader_loaders_ce;

ZEPHIR_INIT_CLASS(Nc_Loader_Loaders);

PHP_METHOD(Nc_Loader_Loaders, offsetSet);
PHP_METHOD(Nc_Loader_Loaders, offsetGet);
PHP_METHOD(Nc_Loader_Loaders, offsetExists);
PHP_METHOD(Nc_Loader_Loaders, offsetUnset);
PHP_METHOD(Nc_Loader_Loaders, findPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaders_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, loader)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaders_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaders_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaders_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_loader_loaders_findpath, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_loader_loaders_method_entry) {
	PHP_ME(Nc_Loader_Loaders, offsetSet, arginfo_nc_loader_loaders_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Loaders, offsetGet, arginfo_nc_loader_loaders_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Loaders, offsetExists, arginfo_nc_loader_loaders_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Loaders, offsetUnset, arginfo_nc_loader_loaders_offsetunset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Loader_Loaders, findPath, arginfo_nc_loader_loaders_findpath, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
