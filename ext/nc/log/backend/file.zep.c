
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/hash.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Log_Backend_File) {

	ZEPHIR_REGISTER_CLASS(Nc\\Log\\Backend, File, nc, log_backend_file, nc_log_backend_file_method_entry, 0);

	zend_declare_property_null(nc_log_backend_file_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_backend_file_ce, SL("logLevels"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_log_backend_file_ce TSRMLS_CC, 1, nc_log_backend_logbackendinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Log_Backend_File, __construct) {

	zval *logLevels = NULL;
	zval *path_param = NULL, *logLevels_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &path_param, &logLevels_param);

	zephir_get_strval(path, path_param);
	if (!logLevels_param) {
	ZEPHIR_INIT_VAR(logLevels);
	array_init(logLevels);
	} else {
		zephir_get_arrval(logLevels, logLevels_param);
	}


	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("logLevels"), logLevels TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_Backend_File, processLogs) {

	zephir_nts_static zephir_fcall_cache_entry *_14 = NULL, *_15 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_11 = NULL;
	zend_bool _4;
	HashTable *_1, *_7;
	HashPosition _0, _6;
	zval *logs_param = NULL, *level = NULL, *logItems = NULL, *log = NULL, *content, **_2, *_3, *_5, **_8, _9 = zval_used_for_init, *_10 = NULL, *_12, *_13 = NULL;
	zval *logs = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logs_param);

	zephir_get_arrval(logs, logs_param);
	ZEPHIR_INIT_VAR(content);
	ZVAL_STRING(content, "", 1);


	zephir_is_iterable(logs, &_1, &_0, 0, 0, "nc/log/backend/file.zep", 28);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(level, _1, _0);
		ZEPHIR_GET_HVALUE(logItems, _2);
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("logLevels"), PH_NOISY_CC);
		_4 = zephir_is_true(_3);
		if (_4) {
			_5 = zephir_fetch_nproperty_this(this_ptr, SL("logLevels"), PH_NOISY_CC);
			_4 = !(zephir_fast_in_array(level, _5 TSRMLS_CC));
		}
		if (_4) {
			continue;
		}
		zephir_is_iterable(logItems, &_7, &_6, 0, 0, "nc/log/backend/file.zep", 26);
		for (
		  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
		  ; zephir_hash_move_forward_ex(_7, &_6)
		) {
			ZEPHIR_GET_HVALUE(log, _8);
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_STRING(&_9, "c", 0);
			ZEPHIR_CALL_FUNCTION(&_10, "date", &_11, &_9);
			zephir_check_call_status();
			zephir_array_fetch_string(&_12, log, SL("message"), PH_NOISY | PH_READONLY, "nc/log/backend/file.zep", 24 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_9);
			ZVAL_STRING(&_9, "[%s] %s\n", 0);
			ZEPHIR_CALL_FUNCTION(&_13, "sprintf", &_14, &_9, _10, level, _12);
			zephir_check_call_status();
			zephir_concat_self(&content, _13 TSRMLS_CC);
		}
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_LONG(&_9, (2 | 8));
	ZEPHIR_CALL_FUNCTION(&_10, "file_put_contents", &_15, _3, content, &_9);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_10))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_log_backend_exception_ce, "Cannot append logs to file", "nc/log/backend/file.zep", 29);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

