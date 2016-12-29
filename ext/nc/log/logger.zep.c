
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
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/operators.h"
#include "kernel/math.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Log_Logger) {

	ZEPHIR_REGISTER_CLASS(Nc\\Log, Logger, nc, log_logger, nc_log_logger_method_entry, 0);

	zend_declare_property_null(nc_log_logger_ce, SL("logId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_logger_ce, SL("fallbackWriter"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_logger_ce, SL("writers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_logger_ce, SL("mainLogs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("EMERGENCY"), "emergency");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("ALERT"), "alert");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("CRITICAL"), "critical");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("ERROR"), "error");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("WARNING"), "warning");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("NOTICE"), "notice");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("INFO"), "info");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("DEBUG"), "debug");

	zephir_declare_class_constant_string(nc_log_logger_ce, SL("MAIN"), "main");

	zend_class_implements(nc_log_logger_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Nc_Log_Logger, generateLogId) {

	long mt0 = 0;
	double mt = 0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval __$true, _0, _1, _2, _3, _4, _5, _6;
	ZEPHIR_INIT_THIS();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, &__$true TSRMLS_CC);
	mt = zephir_get_doubleval(&_0);
	mt0 = (long) (mt);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, 9999);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "%010d%06d%04d");
	ZVAL_LONG(&_4, mt0);
	ZVAL_DOUBLE(&_5, (1000000.0 * ((mt -  (double) mt0))));
	ZVAL_LONG(&_6, zephir_mt_rand(zephir_get_intval(&_1), zephir_get_intval(&_2) TSRMLS_CC));
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 6, &_3, &_4, &_5, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(Nc_Log_Logger, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *logId_param = NULL, _0, _1$$4;
	zval logId;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&logId);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &logId_param);

	if (!logId_param) {
		ZEPHIR_INIT_VAR(&logId);
		ZVAL_STRING(&logId, "");
	} else {
		zephir_get_strval(&logId, logId_param);
	}


	if (zephir_fast_strlen_ev(&logId) > 0) {
		zephir_update_property_zval(this_ptr, SL("logId"), &logId);
	} else {
		ZEPHIR_CALL_SELF(&_1$$4, "generatelogid", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("logId"), &_1$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, getLogId) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "logId");

}

PHP_METHOD(Nc_Log_Logger, setFallbackWriter) {

	zval *writer = NULL, writer_sub, __$null;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&writer_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 0, 1, &writer);

	if (!writer) {
		writer = &writer_sub;
		writer = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("fallbackWriter"), writer);

}

PHP_METHOD(Nc_Log_Logger, getFallbackWriter) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "fallbackWriter");

}

PHP_METHOD(Nc_Log_Logger, offsetSet) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *level_param = NULL, *writer, writer_sub, _1$$3;
	zval level, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&writer_sub);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &level_param, &writer);

	zephir_get_strval(&level, level_param);


	_0 = Z_TYPE_P(writer) != IS_OBJECT;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(writer, nc_log_writerinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_log_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Invalid writer: ", &level);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/log/logger.zep", 66 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("writers"), &level, writer TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, offsetGet) {

	zval *level_param = NULL, writer, _0;
	zval level;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&writer);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	zephir_read_property(&_0, this_ptr, SL("writers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&writer, &_0, &level, 1 TSRMLS_CC)) {
		RETURN_CTOR(writer);
	}
	RETURN_MM_MEMBER(this_ptr, "fallbackWriter");

}

PHP_METHOD(Nc_Log_Logger, offsetExists) {

	zval *level_param = NULL, _0;
	zval level;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	zephir_read_property(&_0, this_ptr, SL("writers"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &level));

}

PHP_METHOD(Nc_Log_Logger, offsetUnset) {

	zval *level_param = NULL, _0;
	zval level;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &level_param);

	zephir_get_strval(&level, level_param);


	zephir_read_property(&_0, this_ptr, SL("writers"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &level, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, emergency) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "emergency");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, alert) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "alert");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, critical) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "critical");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, error) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "error");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, warning) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "warning");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, notice) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "notice");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, info) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "info");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, debug) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *message_param = NULL, *context_param = NULL, _0;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &message_param, &context_param);

	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "debug");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_0, &message, &context);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, log) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, writer, _0, _1;
	zval level, message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&writer);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);

	zephir_get_strval(&level, level_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	ZEPHIR_OBS_VAR(&writer);
	zephir_read_property(&_0, this_ptr, SL("writers"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_fetch(&writer, &_0, &level, 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(&writer);
		zephir_read_property(&writer, this_ptr, SL("fallbackWriter"), PH_NOISY_CC);
	}
	if (Z_TYPE_P(&writer) == IS_NULL) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "stringifylog", NULL, 0, &level, &message, &context);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &writer, "appendlog", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, main) {

	zend_bool duplicate;
	zval *key_param = NULL, *value, value_sub, *duplicate_param = NULL, mainLog, _0, _1;
	zval key;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&mainLog);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &duplicate_param);

	zephir_get_strval(&key, key_param);
	if (!duplicate_param) {
		duplicate = 0;
	} else {
		duplicate = zephir_get_boolval(duplicate_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_1, 256);
	zephir_json_encode(&_0, value, zephir_get_intval(&_1) );
	ZEPHIR_INIT_VAR(&mainLog);
	ZEPHIR_CONCAT_VSVS(&mainLog, &key, "[", &_0, "]");
	if (duplicate) {
		zephir_update_property_array_append(this_ptr, SL("mainLogs"), &mainLog TSRMLS_CC);
	} else {
		zephir_update_property_array(this_ptr, SL("mainLogs"), &key, &mainLog TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Logger, __destruct) {

	zval _0, _1$$4, _2$$4, _3$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("mainLogs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) < 1) {
		RETURN_MM_NULL();
	}

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_read_property(&_2$$4, this_ptr, SL("mainLogs"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_join_str(&_1$$4, SL(" "), &_2$$4 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZVAL_STRING(&_3$$4, "main");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "log", NULL, 0, &_3$$4, &_1$$4);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_NULL();

}

PHP_METHOD(Nc_Log_Logger, stringifyLog) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval context;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, m, k, v, r, _5, _6, _7, *_0$$3, _4$$4;
	zval level, message, _3$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&level);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&m);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&r);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&context);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &level_param, &message_param, &context_param);

	zephir_get_strval(&level, level_param);
	zephir_get_strval(&message, message_param);
	if (!context_param) {
		ZEPHIR_INIT_VAR(&context);
		array_init(&context);
	} else {
		zephir_get_arrval(&context, context_param);
	}


	if (zephir_fast_count_int(&context TSRMLS_CC) > 0) {
		ZEPHIR_INIT_VAR(&r);
		array_init(&r);
		zephir_is_iterable(&context, 0, "nc/log/logger.zep", 185);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&context), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&k, _2$$3);
			} else {
				ZVAL_LONG(&k, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _0$$3);
			zephir_get_strval(&_3$$4, &v);
			ZEPHIR_INIT_LNVAR(_4$$4);
			ZEPHIR_CONCAT_SVS(&_4$$4, "{", &k, "}");
			zephir_array_update_zval(&r, &_4$$4, &_3$$4, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&v);
		ZEPHIR_INIT_NVAR(&k);
		ZEPHIR_CALL_FUNCTION(&m, "strtr", NULL, 78, &message, &r);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&m, &message);
	}
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "c");
	ZEPHIR_CALL_FUNCTION(&_6, "date", NULL, 79, &_5);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("logId"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "[%s] [%s] [%s] %s");
	ZEPHIR_RETURN_CALL_FUNCTION("sprintf", NULL, 6, &_5, &_6, &_7, &level, &m);
	zephir_check_call_status();
	RETURN_MM();

}

