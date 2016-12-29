
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Log_File) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Log, File, nc, log_file, nc_log_writerbufferedabstract_ce, nc_log_file_method_entry, 0);

	zend_declare_property_null(nc_log_file_ce, SL("basePath"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_file_ce, SL("suffixType"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(nc_log_file_ce, SL("SUFFIX_NONE"), 0);

	zephir_declare_class_constant_long(nc_log_file_ce, SL("SUFFIX_DAILY"), 1);

	zephir_declare_class_constant_long(nc_log_file_ce, SL("SUFFIX_HOURLY"), 2);

	zephir_declare_class_constant_string(nc_log_file_ce, SL("EOL"), "\n");

	return SUCCESS;

}

PHP_METHOD(Nc_Log_File, __construct) {

	long suffixType;
	zval *basePath_param = NULL, *suffixType_param = NULL, _0;
	zval basePath;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&basePath);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &basePath_param, &suffixType_param);

	zephir_get_strval(&basePath, basePath_param);
	if (!suffixType_param) {
		suffixType = 0;
	} else {
		suffixType = zephir_get_intval(suffixType_param);
	}


	zephir_update_property_zval(this_ptr, SL("basePath"), &basePath);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, suffixType);
	zephir_update_property_zval(this_ptr, SL("suffixType"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_File, getBasePath) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "basePath");

}

PHP_METHOD(Nc_Log_File, getSuffixType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "suffixType");

}

PHP_METHOD(Nc_Log_File, writeLogs) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *logs_param = NULL, res, _0, _1, _2, _3, _4;
	zval logs;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&logs);
	ZVAL_UNDEF(&res);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logs_param);

	zephir_get_arrval(&logs, logs_param);


	if (zephir_fast_count_int(&logs TSRMLS_CC) < 1) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\n");
	zephir_fast_join(&_1, &_2, &logs TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &_1, "\n");
	ZVAL_LONG(&_4, (8 | 2));
	ZEPHIR_CALL_FUNCTION(&res, "file_put_contents", NULL, 36, &_0, &_3, &_4);
	zephir_check_call_status();
	if (unlikely(!zephir_is_true(&res))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(nc_log_exception_ce, "Failed to write to log file", "nc/log/file.zep", 45);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_File, getPath) {

	zval path, _0, _1$$3, _2$$3, _4$$4, _5$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&path);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&path);
	zephir_read_property(&path, this_ptr, SL("basePath"), PH_NOISY_CC);
	zephir_read_property(&_0, this_ptr, SL("suffixType"), PH_NOISY_CC | PH_READONLY);
	do {
		if (ZEPHIR_IS_LONG(&_0, 1)) {
			ZEPHIR_INIT_VAR(&_1$$3);
			ZVAL_STRING(&_1$$3, ".Ymd");
			ZEPHIR_CALL_FUNCTION(&_2$$3, "date", &_3, 79, &_1$$3);
			zephir_check_call_status();
			zephir_concat_self(&path, &_2$$3 TSRMLS_CC);
			break;
		}
		if (ZEPHIR_IS_LONG(&_0, 2)) {
			ZEPHIR_INIT_VAR(&_4$$4);
			ZVAL_STRING(&_4$$4, ".YmdH");
			ZEPHIR_CALL_FUNCTION(&_5$$4, "date", &_3, 79, &_4$$4);
			zephir_check_call_status();
			zephir_concat_self(&path, &_5$$4 TSRMLS_CC);
			break;
		}
	} while(0);

	RETURN_CCTOR(path);

}

