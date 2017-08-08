
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/file.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(Nc_Log_StdErr) {

	ZEPHIR_REGISTER_CLASS(Nc\\Log, StdErr, nc, log_stderr, nc_log_stderr_method_entry, 0);

	zend_declare_property_null(nc_log_stderr_ce, SL("fp"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_log_stderr_ce TSRMLS_CC, 1, nc_log_writerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Log_StdErr, __construct) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "php://stderr");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "w");
	ZEPHIR_CALL_FUNCTION(&_2, "fopen", NULL, 99, &_0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("fp"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_StdErr, appendLog) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *log_param = NULL, _0, _1, _2, _3, _4$$3, _5$$3;
	zval log;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &log_param);

	zephir_get_strval(&log, log_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("fp"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VV(&_3, &log, &_2);
	zephir_fwrite(&_0, &_1, &_3 TSRMLS_CC);
	if (UNEXPECTED(ZEPHIR_IS_FALSE_IDENTICAL(&_0))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, nc_log_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "appendLog");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 3, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "nc/log/stderr.zep", 15 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

