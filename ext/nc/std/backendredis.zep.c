
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Std_BackendRedis) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, BackendRedis, nc, std_backendredis, nc_std_backendredis_method_entry, 0);

	zend_declare_property_null(nc_std_backendredis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_std_backendredis_ce TSRMLS_CC, 1, nc_std_ratelimiterbackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_BackendRedis, __construct) {

	zval *redis;

	zephir_fetch_params(0, 1, 0, &redis);



	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);

}

PHP_METHOD(Nc_Std_BackendRedis, rateLimiter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *identifier_param = NULL;
	zval *identifier = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	object_init_ex(return_value, nc_std_ratelimiter_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 118, this_ptr, identifier);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Std_BackendRedis, passRateLimiter) {

	zend_bool _14, _15;
	int ZEPHIR_LAST_CALL_STATUS;
	long seconds, times;
	zval *identifier_param = NULL, *seconds_param = NULL, *times_param = NULL, *value = NULL, *result = NULL, *_0, _1, _2, _3, *_4 = NULL, *_6, *_9, *_10 = NULL, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_7$$5, *_8$$5;
	zval *identifier = NULL, *key = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &identifier_param, &seconds_param, &times_param);

	zephir_get_strval(identifier, identifier_param);
	seconds = zephir_get_intval(seconds_param);
	times = zephir_get_intval(times_param);


	if (seconds < 1) {
		seconds = 1;
	}
	if (times < 1) {
		times = 1;
	}
	ZEPHIR_INIT_VAR(_0);
	zephir_time(_0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "%s:%d:%d", 0);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_LONG(&_2, seconds);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_DOUBLE(&_3, zephir_safe_div_zval_long(_0, seconds TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 1, &_1, identifier, &_2, &_3);
	zephir_check_call_status();
	zephir_get_strval(_5, _4);
	ZEPHIR_CPY_WRT(key, _5);
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _6, "get", NULL, 0, key);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		if (ZEPHIR_GE_LONG(value, times)) {
			RETURN_MM_BOOL(0);
		}
		_7$$5 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8$$5);
		ZVAL_LONG(_8$$5, 1);
		ZEPHIR_CALL_METHOD(&value, _7$$5, "incr", NULL, 0, key, _8$$5);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(value, times)) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_10, _9, "multi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	ZVAL_LONG(_12, 1);
	ZEPHIR_CALL_METHOD(&_11, _10, "incr", NULL, 0, key, _12);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_12);
	ZVAL_LONG(_12, (seconds + 1));
	ZEPHIR_CALL_METHOD(&_13, _11, "expire", NULL, 0, key, _12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _13, "exec", NULL, 0);
	zephir_check_call_status();
	_14 = Z_TYPE_P(result) == IS_ARRAY;
	if (_14) {
		ZEPHIR_OBS_NVAR(value);
		_14 = zephir_array_isset_long_fetch(&value, result, 0, 0 TSRMLS_CC);
	}
	_15 = _14;
	if (_15) {
		_15 = ZEPHIR_LE_LONG(value, times);
	}
	if (_15) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

