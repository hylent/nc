
extern zend_class_entry *nc_router_sourceuripatterns_ce;

ZEPHIR_INIT_CLASS(Nc_Router_SourceUriPatterns);

PHP_METHOD(Nc_Router_SourceUriPatterns, __construct);
PHP_METHOD(Nc_Router_SourceUriPatterns, onPregReplaceCallback);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_sourceuripatterns___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_ARRAY_INFO(0, rules, 1)
	ZEND_ARG_ARRAY_INFO(0, typePatterns, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_sourceuripatterns_onpregreplacecallback, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, matches, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_router_sourceuripatterns_method_entry) {
	PHP_ME(Nc_Router_SourceUriPatterns, __construct, arginfo_nc_router_sourceuripatterns___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Router_SourceUriPatterns, onPregReplaceCallback, arginfo_nc_router_sourceuripatterns_onpregreplacecallback, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
