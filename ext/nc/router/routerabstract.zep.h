
extern zend_class_entry *nc_router_routerabstract_ce;

ZEPHIR_INIT_CLASS(Nc_Router_RouterAbstract);

PHP_METHOD(Nc_Router_RouterAbstract, getController);
PHP_METHOD(Nc_Router_RouterAbstract, getAction);
PHP_METHOD(Nc_Router_RouterAbstract, getParams);

ZEPHIR_INIT_FUNCS(nc_router_routerabstract_method_entry) {
	PHP_ME(Nc_Router_RouterAbstract, getController, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_RouterAbstract, getAction, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_RouterAbstract, getParams, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
