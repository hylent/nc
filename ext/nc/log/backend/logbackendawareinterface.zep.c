
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Log_Backend_LogBackendAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Log\\Backend, LogBackendAwareInterface, nc, log_backend_logbackendawareinterface, nc_log_backend_logbackendawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Log_Backend_LogBackendAwareInterface, setLogBackend);

ZEPHIR_DOC_METHOD(Nc_Log_Backend_LogBackendAwareInterface, getLogBackend);

