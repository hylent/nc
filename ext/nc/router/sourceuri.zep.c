
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(Nc_Router_SourceUri) {

	ZEPHIR_REGISTER_CLASS(Nc\\Router, SourceUri, nc, router_sourceuri, nc_router_sourceuri_method_entry, 0);

	zend_declare_property_null(nc_router_sourceuri_ce, SL("uri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_router_sourceuri_ce TSRMLS_CC, 1, nc_router_sourceinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Router_SourceUri, __construct) {

	zval *uri_param = NULL;
	zval *uri = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uri_param);

	zephir_get_strval(uri, uri_param);


	zephir_update_property_this(this_ptr, SL("uri"), uri TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_SourceUri, getSource) {

	zval *_2 = NULL, *_5 = NULL;
	zval *m = NULL, *_0, *_1, _3, *_4, _6, _7;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_property_this(&_1, this_ptr, SL("uri"), PH_NOISY_CC);
	zephir_get_strval(_2, _1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "#^([^\\?]+)#", 0);
	zephir_preg_match(_0, &_3, _2, m, 0, 0 , 0  TSRMLS_CC);
	if (!(zephir_is_true(_0))) {
		array_init(return_value);
		RETURN_MM();
	}
	ZEPHIR_OBS_VAR(_4);
	zephir_array_fetch_long(&_4, m, 1, PH_NOISY, "nc/router/sourceuri.zep", 20 TSRMLS_CC);
	zephir_get_strval(_5, _4);
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "#/+#", 0);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_RETURN_CALL_FUNCTION("preg_split", NULL, 26, &_6, _5, ZEPHIR_GLOBAL(global_null), &_7);
	zephir_check_call_status();
	RETURN_MM();

}

