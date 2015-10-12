
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Log_LogAwareInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Log, LogAwareInterface, nc, log_logawareinterface, nc_log_logawareinterface_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Log_LogAwareInterface, setLog);

ZEPHIR_DOC_METHOD(Nc_Log_LogAwareInterface, getLog);

