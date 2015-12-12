
extern zend_class_entry *nc_router_sourcesapistrategy_ce;

ZEPHIR_INIT_CLASS(Nc_Router_SourceSapiStrategy);

PHP_METHOD(Nc_Router_SourceSapiStrategy, getSource);

ZEPHIR_INIT_FUNCS(nc_router_sourcesapistrategy_method_entry) {
	PHP_ME(Nc_Router_SourceSapiStrategy, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
