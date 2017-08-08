
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
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_RateLimiter_RateLimiter) {

	ZEPHIR_REGISTER_CLASS(Nc\\RateLimiter, RateLimiter, nc, ratelimiter_ratelimiter, nc_ratelimiter_ratelimiter_method_entry, 0);

	zend_declare_property_null(nc_ratelimiter_ratelimiter_ce, SL("backend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_ratelimiter_ratelimiter_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_RateLimiter_RateLimiter, __construct) {

	zval name;
	zval *backend, backend_sub, *name_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&backend_sub);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &backend, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_update_property_zval(this_ptr, SL("backend"), backend);
	zephir_update_property_zval(this_ptr, SL("name"), &name);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_RateLimiter_RateLimiter, getBackend) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "backend");

}

PHP_METHOD(Nc_RateLimiter_RateLimiter, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

PHP_METHOD(Nc_RateLimiter_RateLimiter, pass) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *seconds_param = NULL, *times_param = NULL, _1;
	long seconds, times;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &seconds_param, &times_param);

	seconds = zephir_get_intval(seconds_param);
	times = zephir_get_intval(times_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 1, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, times);
	zephir_array_update_long(&_0, seconds, &_1, PH_COPY ZEPHIR_DEBUG_PARAMS_DUMMY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "passratelimits", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_RateLimiter_RateLimiter, passRateLimits) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rateLimits_param = NULL, _0, _1;
	zval rateLimits;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rateLimits);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rateLimits_param);

	zephir_get_arrval(&rateLimits, rateLimits_param);


	zephir_read_property(&_0, this_ptr, SL("backend"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("name"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "passratelimits", NULL, 0, &_1, &rateLimits);
	zephir_check_call_status();
	RETURN_MM();

}

