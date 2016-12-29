
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Nc_Log_Nil) {

	ZEPHIR_REGISTER_CLASS(Nc\\Log, Nil, nc, log_nil, nc_log_nil_method_entry, 0);

	zend_class_implements(nc_log_nil_ce TSRMLS_CC, 1, nc_log_writerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Log_Nil, appendLog) {

	zval *log_param = NULL;
	zval log;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&log);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &log_param);

	zephir_get_strval(&log, log_param);


	RETURN_MM_NULL();

}

