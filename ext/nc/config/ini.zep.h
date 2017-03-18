
extern zend_class_entry *nc_config_ini_ce;

ZEPHIR_INIT_CLASS(Nc_Config_Ini);

PHP_METHOD(Nc_Config_Ini, readFromPath);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_config_ini_readfrompath, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_config_ini_method_entry) {
	PHP_ME(Nc_Config_Ini, readFromPath, arginfo_nc_config_ini_readfrompath, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
