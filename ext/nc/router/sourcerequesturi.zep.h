
extern zend_class_entry *nc_router_sourcerequesturi_ce;

ZEPHIR_INIT_CLASS(Nc_Router_SourceRequestUri);

PHP_METHOD(Nc_Router_SourceRequestUri, __construct);

ZEPHIR_INIT_FUNCS(nc_router_sourcerequesturi_method_entry) {
	PHP_ME(Nc_Router_SourceRequestUri, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
