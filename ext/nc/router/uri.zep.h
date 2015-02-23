
extern zend_class_entry *nc_router_uri_ce;

ZEPHIR_INIT_CLASS(Nc_Router_Uri);

PHP_METHOD(Nc_Router_Uri, __construct);
PHP_METHOD(Nc_Router_Uri, getBaseUri);
PHP_METHOD(Nc_Router_Uri, __invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_nc_router_uri___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, baseUri)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(nc_router_uri_method_entry) {
	PHP_ME(Nc_Router_Uri, __construct, arginfo_nc_router_uri___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Nc_Router_Uri, getBaseUri, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Nc_Router_Uri, __invoke, NULL, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
