
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Log_Backend_Nil) {

	ZEPHIR_REGISTER_CLASS(Nc\\Log\\Backend, Nil, nc, log_backend_nil, nc_log_backend_nil_method_entry, 0);

	zend_class_implements(nc_log_backend_nil_ce TSRMLS_CC, 1, nc_log_backend_logbackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Log_Backend_Nil, processLogs) {

	zval *logs_param = NULL;
	zval *logs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logs_param);

	zephir_get_arrval(logs, logs_param);


	RETURN_MM_NULL();

}

