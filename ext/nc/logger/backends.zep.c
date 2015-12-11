
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/hash.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Logger_Backends) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Logger, Backends, nc, logger_backends, nc_logger_loggerabstract_ce, nc_logger_backends_method_entry, 0);

	zend_declare_property_null(nc_logger_backends_ce, SL("globalBackends"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_logger_backends_ce, SL("backends"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Logger_Backends, addBackend) {

	HashTable *_7;
	HashPosition _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *level = NULL, *h = NULL, *_1 = NULL;
	zval *backend, *level_param = NULL, *lev = NULL, *_0 = NULL, *_2 = NULL, _3, _4, *_5 = NULL, **_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &backend, &level_param);

	if (!level_param) {
		ZEPHIR_INIT_VAR(level);
		ZVAL_STRING(level, "", 1);
	} else {
		zephir_get_strval(level, level_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "spl_object_hash", NULL, 79, backend);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	ZEPHIR_CPY_WRT(h, _1);
	if (zephir_fast_strlen_ev(level) < 1) {
		zephir_update_property_array(this_ptr, SL("globalBackends"), h, backend TSRMLS_CC);
		RETURN_MM_NULL();
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "@[,/\\|]+@", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 1);
	ZEPHIR_CALL_FUNCTION(&_5, "preg_split", NULL, 80, &_3, level, &_4);
	zephir_check_call_status();
	zephir_is_iterable(_5, &_7, &_6, 0, 0, "nc/logger/backends.zep", 23);
	for (
	  ; zephir_hash_get_current_data_ex(_7, (void**) &_8, &_6) == SUCCESS
	  ; zephir_hash_move_forward_ex(_7, &_6)
	) {
		ZEPHIR_GET_HVALUE(lev, _8);
		zephir_update_property_array_multi(this_ptr, SL("backends"), &backend TSRMLS_CC, SL("zz"), 2, lev, h);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Logger_Backends, log) {

	HashTable *_1$$3, *_6$$5;
	HashPosition _0$$3, _5$$5;
	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *context = NULL;
	zval *level_param = NULL, *message_param = NULL, *context_param = NULL, *backends = NULL, *backend = NULL, *_3, **_2$$3, **_7$$5;
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


	ZEPHIR_OBS_VAR(backends);
	zephir_read_property_this(&backends, this_ptr, SL("globalBackends"), PH_NOISY_CC);
	if (Z_TYPE_P(backends) == IS_ARRAY) {
		zephir_is_iterable(backends, &_1$$3, &_0$$3, 0, 0, "nc/logger/backends.zep", 35);
		for (
		  ; zephir_hash_get_current_data_ex(_1$$3, (void**) &_2$$3, &_0$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_1$$3, &_0$$3)
		) {
			ZEPHIR_GET_HVALUE(backend, _2$$3);
			ZEPHIR_CALL_METHOD(NULL, backend, "log", NULL, 0, level, message, context);
			zephir_check_call_status();
		}
	}
	ZEPHIR_OBS_NVAR(backends);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("backends"), PH_NOISY_CC);
	_4 = zephir_array_isset_fetch(&backends, _3, level, 0 TSRMLS_CC);
	if (_4) {
		_4 = Z_TYPE_P(backends) == IS_ARRAY;
	}
	if (_4) {
		zephir_is_iterable(backends, &_6$$5, &_5$$5, 0, 0, "nc/logger/backends.zep", 41);
		for (
		  ; zephir_hash_get_current_data_ex(_6$$5, (void**) &_7$$5, &_5$$5) == SUCCESS
		  ; zephir_hash_move_forward_ex(_6$$5, &_5$$5)
		) {
			ZEPHIR_GET_HVALUE(backend, _7$$5);
			ZEPHIR_CALL_METHOD(NULL, backend, "log", NULL, 0, level, message, context);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

