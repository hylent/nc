
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_RateLimiter_RateLimiterBackendAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\RateLimiter, RateLimiterBackendAbstract, nc, ratelimiter_ratelimiterbackendabstract, nc_ratelimiter_ratelimiterbackendabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_class_implements(nc_ratelimiter_ratelimiterbackendabstract_ce TSRMLS_CC, 1, nc_ratelimiter_ratelimiterbackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_RateLimiter_RateLimiterBackendAbstract, getRateLimiter) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	object_init_ex(return_value, nc_ratelimiter_ratelimiter_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 19, this_ptr, &name);
	zephir_check_call_status();
	RETURN_MM();

}

