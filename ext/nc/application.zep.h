
extern zend_class_entry *nc_application_ce;

ZEPHIR_INIT_CLASS(Nc_Application);

PHP_METHOD(Nc_Application, __construct);
PHP_METHOD(Nc_Application, config);
PHP_METHOD(Nc_Application, mergeConfigs);
PHP_METHOD(Nc_Application, mergeConfigsInPathIfValid);
PHP_METHOD(Nc_Application, offsetSet);
PHP_METHOD(Nc_Application, offsetGet);
PHP_METHOD(Nc_Application, offsetExists);
PHP_METHOD(Nc_Application, offsetUnset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, configs, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_config, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_mergeconfigs, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, configs, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_mergeconfigsinpathifvalid, 0, 0, 1)
	ZEND_ARG_INFO(0, path)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_offsetset, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_offsetget, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_offsetexists, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_application_offsetunset, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_application_method_entry) {
	PHP_ME(Nc_Application, __construct, arginfo_nc_application___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Application, config, arginfo_nc_application_config, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application, mergeConfigs, arginfo_nc_application_mergeconfigs, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application, mergeConfigsInPathIfValid, arginfo_nc_application_mergeconfigsinpathifvalid, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application, offsetSet, arginfo_nc_application_offsetset, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application, offsetGet, arginfo_nc_application_offsetget, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application, offsetExists, arginfo_nc_application_offsetexists, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Application, offsetUnset, arginfo_nc_application_offsetunset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
