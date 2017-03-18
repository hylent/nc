
extern zend_class_entry *nc_mvc_contextcli_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_ContextCli);

PHP_METHOD(Nc_Mvc_ContextCli, __construct);
PHP_METHOD(Nc_Mvc_ContextCli, getRoutingNames);
PHP_METHOD(Nc_Mvc_ContextCli, getParamMap);
PHP_METHOD(Nc_Mvc_ContextCli, getParam);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contextcli_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_contextcli_method_entry) {
	PHP_ME(Nc_Mvc_ContextCli, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Mvc_ContextCli, getRoutingNames, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextCli, getParamMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextCli, getParam, arginfo_nc_mvc_contextcli_getparam, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
