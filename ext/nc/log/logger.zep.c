
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
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Log_Logger) {

	ZEPHIR_REGISTER_CLASS(Nc\\Log, Logger, nc, log_logger, nc_log_logger_method_entry, 0);

	zend_declare_property_null(nc_log_logger_ce, SL("logBackend"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_logger_ce, SL("logs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_log_logger_ce TSRMLS_CC, 1, nc_log_loginterface_ce);
	zend_class_implements(nc_log_logger_ce TSRMLS_CC, 1, nc_log_backend_logbackendawareinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Log_Logger, setLogBackend) {

	zval *logBackend;

	zephir_fetch_params(0, 1, 0, &logBackend);



	zephir_update_property_this(this_ptr, SL("logBackend"), logBackend TSRMLS_CC);

}

PHP_METHOD(Nc_Log_Logger, getLogBackend) {

	

	RETURN_MEMBER(this_ptr, "logBackend");

}

PHP_METHOD(Nc_Log_Logger, emergency) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "emergency", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, alert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "alert", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, critical) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "critical", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "error", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "warning", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "notice", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, info) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "info", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *message_param = NULL, *context_param = NULL, *_0;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	} else {
		zephir_get_arrval(context, context_param);
	}


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "debug", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, _0, message, context);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, log) {

	zval *context = NULL, *_0;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL;
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


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 2, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("message"), &message, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("context"), &context, PH_COPY | PH_SEPARATE);
	zephir_update_property_array_multi(this_ptr, SL("logs"), &_0 TSRMLS_CC, SL("za"), 2, level);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, flush) {

	zval *_0, *_1, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("logBackend"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "processlogs", NULL, 0, _2);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("logs"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flush", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_NULL();

}

