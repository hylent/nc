
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Nc_Logger_LogClosure) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Logger, LogClosure, nc, logger_logclosure, nc_logger_loggerabstract_ce, nc_logger_logclosure_method_entry, 0);

	zend_declare_property_null(nc_logger_logclosure_ce, SL("logClosure"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Logger_LogClosure, __construct) {

	zval *logClosure;

	zephir_fetch_params(0, 1, 0, &logClosure);



	zephir_update_property_this(this_ptr, SL("logClosure"), logClosure TSRMLS_CC);

}

PHP_METHOD(Nc_Logger_LogClosure, log) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, *_0;
	zval *level = NULL, *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);

	zephir_get_strval(level, level_param);
	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("logClosure"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "call_user_func", NULL, 17, _0, level, message, context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

