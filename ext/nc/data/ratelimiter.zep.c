
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Data_RateLimiter) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Data, RateLimiter, nc, data_ratelimiter, nc_data_dataabstract_ce, nc_data_ratelimiter_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(Nc_Data_RateLimiter, pass) {

	int ZEPHIR_LAST_CALL_STATUS;
	long seconds, times;
	zval *item_param = NULL, *seconds_param = NULL, *times_param = NULL, *_0, *_1, *_2, *_3;
	zval *item = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &item_param, &seconds_param, &times_param);

	zephir_get_strval(item, item_param);
	seconds = zephir_get_intval(seconds_param);
	times = zephir_get_intval(times_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("backend"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("identifier"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, seconds);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, times);
	ZEPHIR_RETURN_CALL_METHOD(_0, "passratelimiter", NULL, 0, _1, item, _2, _3);
	zephir_check_call_status();
	RETURN_MM();

}

