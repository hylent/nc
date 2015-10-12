
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Router_Uri) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Router, Uri, nc, router_uri, nc_router_routerabstract_ce, nc_router_uri_method_entry, 0);

	zend_declare_property_null(nc_router_uri_ce, SL("baseUri"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Router_Uri, __construct) {

	long len = 0;
	zephir_fcall_cache_entry *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _12;
	zval *uri_param = NULL, *baseUri_param = NULL, *m = NULL, *params = NULL, *_6, _7, *_0$$3, _3$$3, *_4$$3, *_1$$4, *_8$$5, _10$$5, _11$$5, *_13$$7, *_14$$8 = NULL, *_16$$8, *_17$$9 = NULL, *_18$$9 = NULL;
	zval *uri = NULL, *baseUri = NULL, *_5$$3 = NULL, *_2$$4, *_9$$5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &uri_param, &baseUri_param);

	zephir_get_strval(uri, uri_param);
	zephir_get_strval(baseUri, baseUri_param);


	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);
	len = zephir_fast_strlen_ev(baseUri);
	if (len > 0) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_strpos(_0$$3, uri, baseUri, 0 );
		if (unlikely(!ZEPHIR_IS_LONG_IDENTICAL(_0$$3, 0))) {
			ZEPHIR_INIT_VAR(_1$$4);
			object_init_ex(_1$$4, nc_router_exception_ce);
			ZEPHIR_INIT_VAR(_2$$4);
			ZEPHIR_CONCAT_SV(_2$$4, "Invalid base uri: ", baseUri);
			ZEPHIR_CALL_METHOD(NULL, _1$$4, "__construct", NULL, 2, _2$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1$$4, "nc/router/uri.zep", 15 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_3$$3);
		ZVAL_LONG(&_3$$3, len);
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_substr(_4$$3, uri, zephir_get_intval(&_3$$3), 0, ZEPHIR_SUBSTR_NO_LENGTH);
		zephir_get_strval(_5$$3, _4$$3);
		ZEPHIR_CPY_WRT(uri, _5$$3);
	}
	zephir_update_property_this(this_ptr, SL("baseUri"), baseUri TSRMLS_CC);
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "/^([^\\.\\?]+)/", 0);
	zephir_preg_match(_6, &_7, uri, m, 0, 0 , 0  TSRMLS_CC);
	if (zephir_is_true(_6)) {
		ZEPHIR_OBS_VAR(_8$$5);
		zephir_array_fetch_long(&_8$$5, m, 1, PH_NOISY, "nc/router/uri.zep", 23 TSRMLS_CC);
		zephir_get_strval(_9$$5, _8$$5);
		ZEPHIR_SINIT_VAR(_10$$5);
		ZVAL_STRING(&_10$$5, "#/+#", 0);
		ZEPHIR_SINIT_VAR(_11$$5);
		ZVAL_LONG(&_11$$5, 1);
		ZEPHIR_CALL_FUNCTION(&params, "preg_split", NULL, 5, &_10$$5, _9$$5, ZEPHIR_GLOBAL(global_null), &_11$$5);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(params);
		array_init(params);
	}
	do {
		_12 = zephir_fast_count_int(params TSRMLS_CC);
		if (_12 == 0) {
			ZEPHIR_INIT_ZVAL_NREF(_13$$7);
			ZVAL_STRING(_13$$7, "index", 1);
			zephir_update_property_this(this_ptr, SL("controller"), _13$$7 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_13$$7);
			ZVAL_STRING(_13$$7, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _13$$7 TSRMLS_CC);
			break;
		}
		if (_12 == 1) {
			ZEPHIR_MAKE_REF(params);
			ZEPHIR_CALL_FUNCTION(&_14$$8, "array_shift", &_15, 12, params);
			ZEPHIR_UNREF(params);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("controller"), _14$$8 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_16$$8);
			ZVAL_STRING(_16$$8, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _16$$8 TSRMLS_CC);
			break;
		}
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_17$$9, "array_shift", &_15, 12, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("controller"), _17$$9 TSRMLS_CC);
		ZEPHIR_MAKE_REF(params);
		ZEPHIR_CALL_FUNCTION(&_18$$9, "array_shift", &_15, 12, params);
		ZEPHIR_UNREF(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("action"), _18$$9 TSRMLS_CC);
		break;
	} while(0);

	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_Uri, getBaseUri) {

	

	RETURN_MEMBER(this_ptr, "baseUri");

}

PHP_METHOD(Nc_Router_Uri, __invoke) {

	zend_bool _0, _2;
	zval *args = NULL, *controller = NULL, *action = NULL, *_4, *_5, *_1$$4, *_3$$5;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", NULL, 13);
	zephir_check_call_status();
	if (zephir_fast_count_int(args TSRMLS_CC) == 0) {
		RETURN_MM_MEMBER(this_ptr, "baseUri");
	}
	ZEPHIR_OBS_VAR(controller);
	_0 = zephir_array_isset_long_fetch(&controller, args, 0, 0 TSRMLS_CC);
	if (_0) {
		_0 = Z_TYPE_P(controller) == IS_NULL;
	}
	if (_0) {
		_1$$4 = zephir_fetch_nproperty_this(this_ptr, SL("controller"), PH_NOISY_CC);
		zephir_array_update_long(&args, 0, &_1$$4, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	ZEPHIR_OBS_VAR(action);
	_2 = zephir_array_isset_long_fetch(&action, args, 1, 0 TSRMLS_CC);
	if (_2) {
		_2 = Z_TYPE_P(action) == IS_NULL;
	}
	if (_2) {
		_3$$5 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
		zephir_array_update_long(&args, 1, &_3$$5, PH_COPY | PH_SEPARATE ZEPHIR_DEBUG_PARAMS_DUMMY);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("baseUri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_5);
	zephir_fast_join_str(_5, SL("/"), args TSRMLS_CC);
	ZEPHIR_CONCAT_VV(return_value, _4, _5);
	RETURN_MM();

}

