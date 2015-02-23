
extern zend_class_entry *nc_router_routerinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Router_RouterInterface);

ZEPHIR_INIT_FUNCS(nc_router_routerinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Router_RouterInterface, getController, NULL)
	PHP_ABSTRACT_ME(Nc_Router_RouterInterface, getAction, NULL)
	PHP_ABSTRACT_ME(Nc_Router_RouterInterface, getParams, NULL)
	PHP_ABSTRACT_ME(Nc_Router_RouterInterface, __invoke, NULL)
  PHP_FE_END
};
