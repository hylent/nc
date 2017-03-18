
extern zend_class_entry *nc_config_filesystemabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Config_FileSystemAbstract);

PHP_METHOD(Nc_Config_FileSystemAbstract, __construct);
PHP_METHOD(Nc_Config_FileSystemAbstract, __isset);
PHP_METHOD(Nc_Config_FileSystemAbstract, __get);
PHP_METHOD(Nc_Config_FileSystemAbstract, get);
PHP_METHOD(Nc_Config_FileSystemAbstract, loadAll);
PHP_METHOD(Nc_Config_FileSystemAbstract, readFromPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_config_filesystemabstract___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, baseDirectory)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_config_filesystemabstract___isset, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_config_filesystemabstract___get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_config_filesystemabstract_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_config_filesystemabstract_readfrompath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_config_filesystemabstract_method_entry) {
	PHP_ME(Nc_Config_FileSystemAbstract, __construct, arginfo_nc_config_filesystemabstract___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Config_FileSystemAbstract, __isset, arginfo_nc_config_filesystemabstract___isset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Config_FileSystemAbstract, __get, arginfo_nc_config_filesystemabstract___get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Config_FileSystemAbstract, get, arginfo_nc_config_filesystemabstract_get, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Config_FileSystemAbstract, loadAll, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Config_FileSystemAbstract, readFromPath, arginfo_nc_config_filesystemabstract_readfrompath, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_FE_END
};
