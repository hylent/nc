
extern zend_class_entry *nc_router_sourceinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Router_SourceInterface);

ZEPHIR_INIT_FUNCS(nc_router_sourceinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Router_SourceInterface, getSource, NULL)
	PHP_FE_END
};
