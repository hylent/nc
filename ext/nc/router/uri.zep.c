
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
#include "kernel/string.h"
#include "kernel/memory.h"
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

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_7 = NULL, *_11 = NULL, *_14 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, _12;
	long len;
	zval *uri_param = NULL, *baseUri_param = NULL, *m = NULL, *params = NULL, *_0 = NULL, *_1, _3 = zval_used_for_init, *_4 = NULL, *_8, _10, *_13, *_15 = NULL;
	zval *uri = NULL, *baseUri = NULL, *_2, *_6 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &uri_param, &baseUri_param);

	zephir_get_strval(uri, uri_param);
	zephir_get_strval(baseUri, baseUri_param);
	ZEPHIR_INIT_VAR(m);
	ZVAL_NULL(m);


	len = zephir_fast_strlen_ev(baseUri);
	if (len > 0) {
		ZEPHIR_INIT_VAR(_0);
		zephir_fast_strpos(_0, uri, baseUri, 0 );
		if (unlikely(!ZEPHIR_IS_LONG_IDENTICAL(_0, 0))) {
			ZEPHIR_INIT_VAR(_1);
			object_init_ex(_1, nc_router_exception_ce);
			ZEPHIR_INIT_VAR(_2);
			ZEPHIR_CONCAT_SV(_2, "Invalid base uri: ", baseUri);
			ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, _2);
			zephir_check_call_status();
			zephir_throw_exception_debug(_1, "nc/router/uri.zep", 15 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_LONG(&_3, len);
		ZEPHIR_CALL_FUNCTION(&_4, "substr", &_5, uri, &_3);
		zephir_check_call_status();
		zephir_get_strval(_6, _4);
		ZEPHIR_CPY_WRT(uri, _6);
	}
	zephir_update_property_this(this_ptr, SL("baseUri"), baseUri TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "/^([^\\.\\?]+)/", ZEPHIR_TEMP_PARAM_COPY);
	Z_SET_ISREF_P(m);
	ZEPHIR_CALL_FUNCTION(&_4, "preg_match", &_7, _0, uri, m);
	zephir_check_temp_parameter(_0);
	Z_UNSET_ISREF_P(m);
	zephir_check_call_status();
	if (zephir_is_true(_4)) {
		ZEPHIR_OBS_VAR(_8);
		zephir_array_fetch_long(&_8, m, 1, PH_NOISY, "nc/router/uri.zep", 23 TSRMLS_CC);
		zephir_get_strval(_9, _8);
		ZEPHIR_SINIT_NVAR(_3);
		ZVAL_STRING(&_3, "#/+#", 0);
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_LONG(&_10, 1);
		ZEPHIR_CALL_FUNCTION(&params, "preg_split", &_11, &_3, _9, ZEPHIR_GLOBAL(global_null), &_10);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(params);
		array_init(params);
	}
	do {
		_12 = zephir_fast_count_int(params TSRMLS_CC);
		if (_12 == 0) {
			ZEPHIR_INIT_ZVAL_NREF(_13);
			ZVAL_STRING(_13, "index", 1);
			zephir_update_property_this(this_ptr, SL("controller"), _13 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_13);
			ZVAL_STRING(_13, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _13 TSRMLS_CC);
			break;
		}
		if (_12 == 1) {
			Z_SET_ISREF_P(params);
			ZEPHIR_CALL_FUNCTION(&_4, "array_shift", &_14, params);
			Z_UNSET_ISREF_P(params);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("controller"), _4 TSRMLS_CC);
			ZEPHIR_INIT_ZVAL_NREF(_13);
			ZVAL_STRING(_13, "index", 1);
			zephir_update_property_this(this_ptr, SL("action"), _13 TSRMLS_CC);
			break;
		}
		Z_SET_ISREF_P(params);
		ZEPHIR_CALL_FUNCTION(&_4, "array_shift", &_14, params);
		Z_UNSET_ISREF_P(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("controller"), _4 TSRMLS_CC);
		Z_SET_ISREF_P(params);
		ZEPHIR_CALL_FUNCTION(&_15, "array_shift", &_14, params);
		Z_UNSET_ISREF_P(params);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("action"), _15 TSRMLS_CC);
		break;
	} while(0);

	zephir_update_property_this(this_ptr, SL("params"), params TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Router_Uri, getBaseUri) {


	RETURN_MEMBER(this_ptr, "baseUri");

}

PHP_METHOD(Nc_Router_Uri, __invoke) {

	zend_bool _1, _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *args = NULL, *controller, *action, *_2, *_4;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&args, "func_get_args", &_0);
	zephir_check_call_status();
	if (zephir_fast_count_int(args TSRMLS_CC) == 0) {
		RETURN_MM_MEMBER(this_ptr, "baseUri");
	}
	ZEPHIR_OBS_VAR(controller);
	_1 = zephir_array_isset_long_fetch(&controller, args, 0, 0 TSRMLS_CC);
	if (_1) {
		_1 = Z_TYPE_P(controller) == IS_NULL;
	}
	if (_1) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("controller"), PH_NOISY_CC);
		zephir_array_update_long(&args, 0, &_2, PH_COPY | PH_SEPARATE, "nc/router/uri.zep", 62);
	}
	ZEPHIR_OBS_VAR(action);
	_3 = zephir_array_isset_long_fetch(&action, args, 1, 0 TSRMLS_CC);
	if (_3) {
		_3 = Z_TYPE_P(action) == IS_NULL;
	}
	if (_3) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("action"), PH_NOISY_CC);
		zephir_array_update_long(&args, 1, &_2, PH_COPY | PH_SEPARATE, "nc/router/uri.zep", 65);
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("baseUri"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_fast_join_str(_4, SL("/"), args TSRMLS_CC);
	ZEPHIR_CONCAT_VV(return_value, _2, _4);
	RETURN_MM();

}

