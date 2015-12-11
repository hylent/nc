
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Logger_LoggerBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Logger, LoggerBackendInterface, nc, logger_loggerbackendinterface, nc_logger_loggerbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Logger_LoggerBackendInterface, log);

