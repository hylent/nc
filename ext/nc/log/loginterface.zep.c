
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(Nc_Log_LogInterface) {

	ZEPHIR_REGISTER_INTERFACE(Nc\\Log, LogInterface, nc, log_loginterface, nc_log_loginterface_method_entry);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("EMERGENCY"), "emergency" TSRMLS_CC);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("ALERT"), "alert" TSRMLS_CC);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("CRITICAL"), "critical" TSRMLS_CC);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("ERROR"), "error" TSRMLS_CC);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("WARNING"), "warning" TSRMLS_CC);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("NOTICE"), "notice" TSRMLS_CC);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("INFO"), "info" TSRMLS_CC);

	zend_declare_class_constant_string(nc_log_loginterface_ce, SL("DEBUG"), "debug" TSRMLS_CC);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, emergency);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, alert);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, critical);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, error);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, warning);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, notice);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, info);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, debug);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, log);

ZEPHIR_DOC_METHOD(Nc_Log_LogInterface, flush);

