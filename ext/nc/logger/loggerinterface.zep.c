
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Logger_LoggerInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Logger, LoggerInterface, nc, logger_loggerinterface, nc_logger_loggerinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Logger_LoggerInterface, log);

