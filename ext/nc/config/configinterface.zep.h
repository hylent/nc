
extern zend_class_entry *nc_config_configinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Config_ConfigInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_config_configinterface_get, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_config_configinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Config_ConfigInterface, get, arginfo_nc_config_configinterface_get)
	PHP_FE_END
};
