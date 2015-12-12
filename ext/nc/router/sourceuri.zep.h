
extern zend_class_entry *nc_router_sourceuri_ce;

ZEPHIR_INIT_CLASS(Nc_Router_SourceUri);

PHP_METHOD(Nc_Router_SourceUri, __construct);
PHP_METHOD(Nc_Router_SourceUri, getSource);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_sourceuri___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, uri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_router_sourceuri_method_entry) {
	PHP_ME(Nc_Router_SourceUri, __construct, arginfo_nc_router_sourceuri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Router_SourceUri, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
