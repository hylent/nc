
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Nc_Router_RouterAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Router, RouterAbstract, nc, router_routerabstract, nc_router_routerabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(nc_router_routerabstract_ce, SL("controller"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_router_routerabstract_ce, SL("action"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_router_routerabstract_ce, SL("params"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_router_routerabstract_ce TSRMLS_CC, 1, nc_router_routerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Router_RouterAbstract, getController) {


	RETURN_MEMBER(this_ptr, "controller");

}

PHP_METHOD(Nc_Router_RouterAbstract, getAction) {


	RETURN_MEMBER(this_ptr, "action");

}

PHP_METHOD(Nc_Router_RouterAbstract, getParams) {


	RETURN_MEMBER(this_ptr, "params");

}

