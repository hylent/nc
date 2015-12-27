
extern zend_class_entry *nc_router_routerabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Router_RouterAbstract);

PHP_METHOD(Nc_Router_RouterAbstract, getId);
PHP_METHOD(Nc_Router_RouterAbstract, route);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_routerabstract_route, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_router_routerabstract_method_entry) {
	PHP_ME(Nc_Router_RouterAbstract, getId, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_RouterAbstract, route, arginfo_nc_router_routerabstract_route, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
