
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


ZEPHIR_INIT_CLASS(Nc_Std_RateLimiter) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Std, RateLimiter, nc, std_ratelimiter, nc_std_stdabstract_ce, nc_std_ratelimiter_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Std_RateLimiter, __construct) {

	zval *identifier = NULL;
	zval *backend, *identifier_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &backend, &identifier_param);

	zephir_get_strval(identifier, identifier_param);


	zephir_update_property_this(this_ptr, SL("backend"), backend TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("identifier"), identifier TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Std_RateLimiter, pass) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *seconds_param = NULL, *times_param = NULL, *_0, *_1, *_2, *_3;
	long seconds, times;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &seconds_param, &times_param);

	seconds = zephir_get_intval(seconds_param);
	times = zephir_get_intval(times_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, seconds);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, times);
	ZEPHIR_RETURN_CALL_METHOD(_0, "passratelimiter", NULL, 0, _1, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

