
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(Nc_Logger_File) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Logger, File, nc, logger_file, nc_logger_loggerabstract_ce, nc_logger_file_method_entry, 0);

	zend_declare_property_null(nc_logger_file_ce, SL("logs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_logger_file_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_logger_file_ce, SL("chunkSize"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Logger_File, __construct) {

	zval *path_param = NULL;
	zval *path = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &path_param);

	zephir_get_strval(path, path_param);


	zephir_update_property_this(this_ptr, SL("path"), path TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Logger_File, setChunkSize) {

	zval *chunkSize_param = NULL, *_0;
	long chunkSize;

	zephir_fetch_params(0, 1, 0, &chunkSize_param);

	chunkSize = zephir_get_intval(chunkSize_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, chunkSize);
	zephir_update_property_this(this_ptr, SL("chunkSize"), _0 TSRMLS_CC);

}

PHP_METHOD(Nc_Logger_File, getChunkSize) {

	

	RETURN_MEMBER(this_ptr, "chunkSize");

}

PHP_METHOD(Nc_Logger_File, log) {

	zend_bool _6;
	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2 = NULL, *_4 = NULL, *_5, *_7, *_8;
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


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "c", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 81, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_2, nc_std_ce, "tr", &_3, 82, message, context);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "[%s] [%s] %s\n", 0);
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 1, &_0, _1, level, _2);
	zephir_check_call_status();
	zephir_update_property_array_append(this_ptr, SL("logs"), _4 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("chunkSize"), PH_NOISY_CC);
	_6 = ZEPHIR_GT_LONG(_5, -1);
	if (_6) {
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("chunkSize"), PH_NOISY_CC);
		_6 = ZEPHIR_LT_LONG(_8, zephir_fast_count_int(_7 TSRMLS_CC));
	}
	if (_6) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flush", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Logger_File, flush) {

	zval *_0, *_1, *_2, *_3, _4, *_5 = NULL, *_6$$4, *_7$$4, *_8$$4;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
	if (!(zephir_is_true(_0))) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
	zephir_fast_join_str(_2, SL(""), _3 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, (2 | 8));
	ZEPHIR_CALL_FUNCTION(&_5, "file_put_contents", NULL, 83, _1, _2, &_4);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, nc_logger_exception_ce);
		_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SV(_8$$4, "Cannot append logs to file: ", _7$$4);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "nc/logger/file.zep", 47 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("logs"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Logger_File, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flush", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_NULL();

}

