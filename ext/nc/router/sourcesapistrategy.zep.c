
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
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Router_SourceSapiStrategy) {

	ZEPHIR_REGISTER_CLASS(Nc\\Router, SourceSapiStrategy, nc, router_sourcesapistrategy, nc_router_sourcesapistrategy_method_entry, 0);

	zend_class_implements(nc_router_sourcesapistrategy_ce TSRMLS_CC, 1, nc_router_sourceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Router_SourceSapiStrategy, getSource) {

	zval *_0, *_2, *_1$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "PHP_SAPI");
	if (ZEPHIR_IS_STRING(_0, "cli")) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, nc_router_sourceargv_ce);
		if (zephir_has_constructor(_1$$3 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_RETURN_CALL_METHOD(_1$$3, "getsource", NULL, 107);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, nc_router_sourcerequesturi_ce);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 108);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_2, "getsource", NULL, 109);
	zephir_check_call_status();
	RETURN_MM();

}

