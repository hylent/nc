
extern zend_class_entry *nc_mvc_contextabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Mvc_ContextAbstract);

PHP_METHOD(Nc_Mvc_ContextAbstract, getRoutingNames);
PHP_METHOD(Nc_Mvc_ContextAbstract, getServerVar);
PHP_METHOD(Nc_Mvc_ContextAbstract, getArgVector);
PHP_METHOD(Nc_Mvc_ContextAbstract, getParamMap);
PHP_METHOD(Nc_Mvc_ContextAbstract, getParam);
PHP_METHOD(Nc_Mvc_ContextAbstract, getRequestTime);
PHP_METHOD(Nc_Mvc_ContextAbstract, getRequestTimeFloat);
PHP_METHOD(Nc_Mvc_ContextAbstract, output);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contextabstract_getservervar, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contextabstract_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_mvc_contextabstract_output, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_mvc_contextabstract_method_entry) {
	PHP_ME(Nc_Mvc_ContextAbstract, getRoutingNames, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextAbstract, getServerVar, arginfo_nc_mvc_contextabstract_getservervar, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextAbstract, getArgVector, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextAbstract, getParamMap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextAbstract, getParam, arginfo_nc_mvc_contextabstract_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextAbstract, getRequestTime, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextAbstract, getRequestTimeFloat, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Mvc_ContextAbstract, output, arginfo_nc_mvc_contextabstract_output, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
