
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Std_RateLimiterInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Std, RateLimiterInterface, nc, std_ratelimiterinterface, nc_std_ratelimiterinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Std_RateLimiterInterface, passRateLimiter);

