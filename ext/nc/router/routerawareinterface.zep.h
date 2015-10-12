
extern zend_class_entry *nc_router_routerawareinterface_ce;

ZEPHIR_INIT_CLASS(Nc_Router_RouterAwareInterface);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_routerawareinterface_setrouter, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, router, Nc\\Router\\RouterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_router_routerawareinterface_method_entry) {
	PHP_ABSTRACT_ME(Nc_Router_RouterAwareInterface, setRouter, arginfo_nc_router_routerawareinterface_setrouter)
	PHP_ABSTRACT_ME(Nc_Router_RouterAwareInterface, getRouter, NULL)
	PHP_FE_END
};
