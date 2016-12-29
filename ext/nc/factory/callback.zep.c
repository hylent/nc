
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(Nc_Factory_Callback) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Factory, Callback, nc, factory_callback, nc_factory_factoryabstract_ce, nc_factory_callback_method_entry, 0);

	zend_declare_property_null(nc_factory_callback_ce, SL("callbacks"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Factory_Callback, __invoke) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *callback, callback_sub, _0$$3, _1$$3, _2$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &callback);

	zephir_get_strval(&name, name_param);


	if (unlikely(!(zephir_is_callable(callback TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Invalid callback '%s'");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "sprintf", NULL, 6, &_1$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "nc/factory/callback.zep", 13 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("callbacks"), &name, callback TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Callback, __isset) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *name_param = NULL, _0, _3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_CALL_PARENT(&_0, nc_factory_callback_ce, this_ptr, "__isset", &_1, 22, &name);
	zephir_check_call_status();
	_2 = zephir_is_true(&_0);
	if (!(_2)) {
		zephir_read_property(&_3, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
		_2 = zephir_array_isset(&_3, &name);
	}
	RETURN_MM_BOOL(_2);

}

PHP_METHOD(Nc_Factory_Callback, createInternally) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, callback, _0, _1$$3, _2$$3, _3$$3;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&callback);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&callback);
	zephir_read_property(&_0, this_ptr, SL("callbacks"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!(zephir_array_isset_fetch(&callback, &_0, &name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "No callback for object '%s'");
		ZEPHIR_CALL_FUNCTION(&_3$$3, "sprintf", NULL, 6, &_2$$3, &name);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/factory/callback.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 2, &callback, this_ptr, &name);
	zephir_check_call_status();
	RETURN_MM();

}

