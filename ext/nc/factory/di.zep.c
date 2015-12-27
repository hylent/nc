
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
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "Zend/zend_closures.h"


ZEPHIR_INIT_CLASS(Nc_Factory_Di) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Factory, Di, nc, factory_di, nc_factory_factoryabstract_ce, nc_factory_di_method_entry, 0);

	zend_declare_property_null(nc_factory_di_ce, SL("initializers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(Nc_Factory_Di, __invoke) {

	zval *name_param = NULL, *initializer;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &initializer);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("initializers"), name, initializer TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Di, __set) {

	zval *name_param = NULL, *production;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &production);

	zephir_get_strval(name, name_param);


	zephir_update_property_array(this_ptr, SL("productions"), name, production TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Di, __unset) {

	zval *name_param = NULL, *_0, *_1;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("productions"), PH_NOISY_CC);
	zephir_array_unset(&_0, name, PH_SEPARATE);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("initializers"), PH_NOISY_CC);
	zephir_array_unset(&_1, name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Di, __isset) {

	zend_bool _1;
	zval *name_param = NULL, *_0, *_2;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("productions"), PH_NOISY_CC);
	_1 = zephir_array_isset(_0, name);
	if (!(_1)) {
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("initializers"), PH_NOISY_CC);
		_1 = zephir_array_isset(_2, name);
	}
	RETURN_MM_BOOL(_1);

}

PHP_METHOD(Nc_Factory_Di, newProduction) {

	zend_bool _3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *initializer = NULL, *_0, *_1$$3, *_4$$4;
	zval *name = NULL, *_2$$3, *_5$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_OBS_VAR(initializer);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("initializers"), PH_NOISY_CC);
	if (unlikely(!(zephir_array_isset_fetch(&initializer, _0, name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SV(_2$$3, "Invalid production: ", name);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 2, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "nc/factory/di.zep", 33 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = Z_TYPE_P(initializer) != IS_OBJECT;
	if (!(_3)) {
		_3 = !((zephir_instance_of_ev(initializer, zend_ce_closure TSRMLS_CC)));
	}
	if (unlikely(_3)) {
		ZEPHIR_INIT_VAR(_4$$4);
		object_init_ex(_4$$4, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_SV(_5$$4, "Invalid production initializer: ", name);
		ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", NULL, 2, _5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$4, "nc/factory/di.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_RETURN_CALL_FUNCTION("call_user_func", NULL, 15, initializer, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

