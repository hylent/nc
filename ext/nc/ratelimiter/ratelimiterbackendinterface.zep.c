
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_RateLimiter_RateLimiterBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\RateLimiter, RateLimiterBackendInterface, nc, ratelimiter_ratelimiterbackendinterface, nc_ratelimiter_ratelimiterbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_RateLimiter_RateLimiterBackendInterface, getRateLimiter);

ZEPHIR_DOC_METHOD(Nc_RateLimiter_RateLimiterBackendInterface, passRateLimits);

