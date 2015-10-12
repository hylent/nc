
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Log_Backend_LogBackendInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Log\\Backend, LogBackendInterface, nc, log_backend_logbackendinterface, nc_log_backend_logbackendinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Log_Backend_LogBackendInterface, processLogs);

