
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
#include "kernel/operators.h"
#include "kernel/time.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Std_RateLimiterRedis) {

	ZEPHIR_REGISTER_CLASS(Nc\\Std, RateLimiterRedis, nc, std_ratelimiterredis, nc_std_ratelimiterredis_method_entry, 0);

	zend_declare_property_null(nc_std_ratelimiterredis_ce, SL("redis"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_std_ratelimiterredis_ce, SL("prefix"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_std_ratelimiterredis_ce, SL("DEFAULT_PREFIX"), "ratelimiter:" TSRMLS_CC);

	zend_class_implements(nc_std_ratelimiterredis_ce TSRMLS_CC, 1, nc_std_ratelimiterinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Std_RateLimiterRedis, __construct) {

	zval *prefix = NULL;
	zval *redis, *prefix_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &redis, &prefix_param);

	if (!prefix_param) {
		ZEPHIR_INIT_VAR(prefix);
		ZVAL_STRING(prefix, "ratelimiter:", 1);
	} else {
		zephir_get_strval(prefix, prefix_param);
	}


	zephir_update_property_this(this_ptr, SL("redis"), redis TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("prefix"), prefix TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_RateLimiterRedis, passRateLimiter) {

	zend_bool _15, _16;
	int ZEPHIR_LAST_CALL_STATUS;
	long seconds, times;
	zval *identifier_param = NULL, *seconds_param = NULL, *times_param = NULL, *value = NULL, *result = NULL, *_0, *_1, _2, _3, _4, *_5 = NULL, *_7, *_10, *_11 = NULL, *_12 = NULL, *_13 = NULL, *_14 = NULL, *_8$$5, *_9$$5;
	zval *identifier = NULL, *key = NULL, *_6 = NULL;

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
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("prefix"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_time(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "%s%s:%d:%d", 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_LONG(&_3, seconds);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_DOUBLE(&_4, zephir_safe_div_zval_long(_1, seconds TSRMLS_CC));
	ZEPHIR_CALL_FUNCTION(&_5, "sprintf", NULL, 1, &_2, _0, identifier, &_3, &_4);
	zephir_check_call_status();
	zephir_get_strval(_6, _5);
	ZEPHIR_CPY_WRT(key, _6);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&value, _7, "get", NULL, 0, key);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(value)) {
		if (ZEPHIR_GE_LONG(value, times)) {
			RETURN_MM_BOOL(0);
		}
		_8$$5 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_9$$5);
		ZVAL_LONG(_9$$5, 1);
		ZEPHIR_CALL_METHOD(&value, _8$$5, "incr", NULL, 0, key, _9$$5);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(value, times)) {
			RETURN_MM_BOOL(0);
		}
		RETURN_MM_BOOL(1);
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("redis"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_11, _10, "multi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_13);
	ZVAL_LONG(_13, 1);
	ZEPHIR_CALL_METHOD(&_12, _11, "incr", NULL, 0, key, _13);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_13);
	ZVAL_LONG(_13, (seconds + 1));
	ZEPHIR_CALL_METHOD(&_14, _12, "expire", NULL, 0, key, _13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&result, _14, "exec", NULL, 0);
	zephir_check_call_status();
	_15 = Z_TYPE_P(result) == IS_ARRAY;
	if (_15) {
		ZEPHIR_OBS_NVAR(value);
		_15 = zephir_array_isset_long_fetch(&value, result, 0, 0 TSRMLS_CC);
	}
	_16 = _15;
	if (_16) {
		_16 = ZEPHIR_LE_LONG(value, times);
	}
	if (_16) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

