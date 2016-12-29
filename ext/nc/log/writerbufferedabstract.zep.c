
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


ZEPHIR_INIT_CLASS(Nc_Log_WriterBufferedAbstract) {

	ZEPHIR_REGISTER_CLASS(Nc\\Log, WriterBufferedAbstract, nc, log_writerbufferedabstract, nc_log_writerbufferedabstract_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_long(nc_log_writerbufferedabstract_ce, SL("bufferSize"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_log_writerbufferedabstract_ce, SL("logs"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zephir_declare_class_constant_long(nc_log_writerbufferedabstract_ce, SL("DEFAULT_BUFFER_SIZE"), 0);

	zend_class_implements(nc_log_writerbufferedabstract_ce TSRMLS_CC, 1, nc_log_writerinterface_ce);
	return SUCCESS;

}

PHP_METHOD(Nc_Log_WriterBufferedAbstract, setBufferSize) {

	zval *bufferSize_param = NULL, _0;
	long bufferSize;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &bufferSize_param);

	bufferSize = zephir_get_intval(bufferSize_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, bufferSize);
	zephir_update_property_zval(this_ptr, SL("bufferSize"), &_0);

}

PHP_METHOD(Nc_Log_WriterBufferedAbstract, getBufferSize) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "bufferSize");

}

PHP_METHOD(Nc_Log_WriterBufferedAbstract, appendLog) {

	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *log_param = NULL, _0, _2, _3;
	zval log;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&log);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &log_param);

	zephir_get_strval(&log, log_param);


	zephir_update_property_array_append(this_ptr, SL("logs"), &log TSRMLS_CC);
	zephir_read_property(&_0, this_ptr, SL("bufferSize"), PH_NOISY_CC | PH_READONLY);
	_1 = ZEPHIR_LT_LONG(&_0, 1);
	if (!(_1)) {
		zephir_read_property(&_2, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_3, this_ptr, SL("bufferSize"), PH_NOISY_CC | PH_READONLY);
		_1 = ZEPHIR_LE_LONG(&_3, zephir_fast_count_int(&_2 TSRMLS_CC));
	}
	if (_1) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flush", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_WriterBufferedAbstract, flush) {

	zval __$null, _0, _1;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) < 1) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("logs"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "writelogs", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("logs"), &__$null);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Log_WriterBufferedAbstract, __destruct) {

	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();


	ZEPHIR_MM_GROW();


	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, this_ptr, "flush", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	zend_clear_exception(TSRMLS_C);
	RETURN_MM_NULL();

}

PHP_METHOD(Nc_Log_WriterBufferedAbstract, writeLogs) {

}

