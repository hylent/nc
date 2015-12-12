
extern zend_class_entry *nc_router_sourceargv_ce;

ZEPHIR_INIT_CLASS(Nc_Router_SourceArgv);

PHP_METHOD(Nc_Router_SourceArgv, getSource);

ZEPHIR_INIT_FUNCS(nc_router_sourceargv_method_entry) {
	PHP_ME(Nc_Router_SourceArgv, getSource, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
