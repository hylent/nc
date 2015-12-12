
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Data_RateLimiterBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Data, RateLimiterBackendInterface, nc, data_ratelimiterbackendinterface, nc_data_ratelimiterbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Data_RateLimiterBackendInterface, passRateLimiter);

