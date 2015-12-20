
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
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Logger_File) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Logger, File, nc, logger_file, nc_logger_loggerabstract_ce, nc_logger_file_method_entry, 0);

	zend_declare_property_null(nc_logger_file_ce, SL("logs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_logger_file_ce, SL("path"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(nc_logger_file_ce, SL("chunkSize"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(nc_logger_file_ce, SL("EOL"), "\n" TSRMLS_CC);

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

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *context = NULL;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, *_0 = NULL, *_2, *_3, *_5, *_6;
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


	ZEPHIR_CALL_CE_STATIC(&_0, nc_logger_loggerabstract_ce, "stringifylog", &_1, 81, level, message, context);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_CONCAT_VS(_2, _0, "\n");
	zephir_update_property_array_append(this_ptr, SL("logs"), _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("chunkSize"), PH_NOISY_CC);
	_4 = ZEPHIR_GT_LONG(_3, 0);
	if (_4) {
		_5 = zephir_fetch_nproperty_this(this_ptr, SL("logs"), PH_NOISY_CC);
		_6 = zephir_fetch_nproperty_this(this_ptr, SL("chunkSize"), PH_NOISY_CC);
		_4 = ZEPHIR_LE_LONG(_6, zephir_fast_count_int(_5 TSRMLS_CC));
	}
	if (_4) {
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
	ZEPHIR_CALL_FUNCTION(&_5, "file_put_contents", NULL, 82, _1, _2, &_4);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_6$$4);
		object_init_ex(_6$$4, nc_logger_exception_ce);
		_7$$4 = zephir_fetch_nproperty_this(this_ptr, SL("path"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8$$4);
		ZEPHIR_CONCAT_SV(_8$$4, "Cannot append logs to file: ", _7$$4);
		ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 2, _8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$4, "nc/logger/file.zep", 42 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("logs"), ZEPHIR_GLOBAL(global_null) TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Logger_File, __destruct) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("chunkSize"), PH_NOISY_CC);
	if (ZEPHIR_LT_LONG(_0, 0)) {
		RETURN_MM_NULL();
	}

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flush", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_NULL();

}

