
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Router_RouterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Router, RouterInterface, nc, router_routerinterface, nc_router_routerinterface_method_entry);

	zend_declare_class_constant_string(nc_router_routerinterface_ce, SL("DEFAULT_CONTROLLER"), "index" TSRMLS_CC);

	zend_declare_class_constant_string(nc_router_routerinterface_ce, SL("DEFAULT_ACTION"), "index" TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Router_RouterInterface, getController);

ZEPHIR_DOC_METHOD(Nc_Router_RouterInterface, getAction);

ZEPHIR_DOC_METHOD(Nc_Router_RouterInterface, getParams);

ZEPHIR_DOC_METHOD(Nc_Router_RouterInterface, __invoke);

