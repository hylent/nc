
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Nc_Di) {

	ZEPHIR_REGISTER_CLASS(Nc, Di, nc, di, nc_di_method_entry, 0);

	zend_declare_property_null(nc_di_ce, SL("services"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(nc_di_ce, SL("serviceInitializers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Di, __invoke) {

	zval *name_param = NULL, *initializer;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &initializer);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("serviceInitializers"), name, initializer TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di, __get) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *service = NULL, *initializer = NULL, *_0, *_1, *_2$$4, *_5$$5;
	zval *name = NULL, *_3$$4, *_6$$5;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(service);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&service, _0, name, 0 TSRMLS_CC)) {
		RETURN_CCTOR(service);
	}
	ZEPHIR_OBS_VAR(initializer);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serviceInitializers"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset_fetch(&initializer, _1, name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_2$$4);
		object_init_ex(_2$$4, nc_exception_ce);
		ZEPHIR_INIT_VAR(_3$$4);
		ZEPHIR_CONCAT_SV(_3$$4, "Invalid service: ", name);
		ZEPHIR_CALL_METHOD(NULL, _2$$4, "__construct", NULL, 2, _3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$4, "nc/di.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = Z_TYPE_P(initializer) != IS_OBJECT;
	if (!(_4)) {
		_4 = !((zephir_instance_of_ev(initializer, zend_ce_closure TSRMLS_CC)));
	}
	if (unlikely(_4)) {
		ZEPHIR_INIT_VAR(_5$$5);
		object_init_ex(_5$$5, nc_exception_ce);
		ZEPHIR_INIT_VAR(_6$$5);
		ZEPHIR_CONCAT_SV(_6$$5, "Invalid service initializer: ", name);
		ZEPHIR_CALL_METHOD(NULL, _5$$5, "__construct", NULL, 2, _6$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$5, "nc/di.zep", 26 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_ZVAL_FUNCTION(&service, initializer, NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("services"), name, service TSRMLS_CC);
	RETURN_CCTOR(service);

}

PHP_METHOD(Nc_Di, __set) {

	zval *name_param = NULL, *obj;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &obj);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("services"), name, obj TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Di, __isset) {

	zend_bool _1;
	zval *name_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, name);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("serviceInitializers"), PH_NOISY_CC);
		_1 = zephir_array_isset(_2, name);
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(Nc_Di, __unset) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("services"), PH_NOISY_CC);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("serviceInitializers"), PH_NOISY_CC);
	zephir_array_unset(&_1, name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

