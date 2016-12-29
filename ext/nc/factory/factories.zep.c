
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
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/hash.h"


ZEPHIR_INIT_CLASS(Nc_Factory_Factories) {

	ZEPHIR_REGISTER_CLASS_EX(Nc\\Factory, Factories, nc, factory_factories, nc_factory_factoryabstract_ce, nc_factory_factories_method_entry, 0);

	zend_declare_property_null(nc_factory_factories_ce, SL("factories"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(nc_factory_factories_ce TSRMLS_CC, 1, zend_ce_arrayaccess);
	return SUCCESS;

}

PHP_METHOD(Nc_Factory_Factories, offsetSet) {

	zend_bool _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *factory, factory_sub, _1$$3;
	zval name, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&factory_sub);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &factory);

	zephir_get_strval(&name, name_param);


	_0 = Z_TYPE_P(factory) != IS_OBJECT;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(factory, nc_factory_factoryinterface_ce TSRMLS_CC)));
	}
	if (unlikely(_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Invalid factory: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/factory/factories.zep", 10 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_array(this_ptr, SL("factories"), &name, factory TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Factories, offsetGet) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, factory, _0, _1$$3;
	zval name, _2$$3;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	ZEPHIR_OBS_VAR(&factory);
	zephir_read_property(&_0, this_ptr, SL("factories"), PH_NOISY_CC | PH_READONLY);
	if (unlikely(!(zephir_array_isset_fetch(&factory, &_0, &name, 0 TSRMLS_CC)))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, nc_factory_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Undefined factory: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "nc/factory/factories.zep", 21 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(factory);

}

PHP_METHOD(Nc_Factory_Factories, offsetExists) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("factories"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(zephir_array_isset(&_0, &name));

}

PHP_METHOD(Nc_Factory_Factories, offsetUnset) {

	zval *name_param = NULL, _0;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("factories"), PH_NOISY_CC | PH_READONLY);
	zephir_array_unset(&_0, &name, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(Nc_Factory_Factories, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, factory, _0, _1$$3, *_2$$3, _3$$4;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("factories"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		zephir_read_property(&_1$$3, this_ptr, SL("factories"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "nc/factory/factories.zep", 47);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&factory);
			ZVAL_COPY(&factory, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, &factory, "__isset", NULL, 0, &name);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$4)) {
				RETURN_MM_BOOL(1);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&factory);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(Nc_Factory_Factories, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, factory, _0, _4, _5, _6, _1$$3, *_2$$3, _3$$4;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(&name, name_param);


	zephir_read_property(&_0, this_ptr, SL("factories"), PH_NOISY_CC | PH_READONLY);
	if (zephir_fast_count_int(&_0 TSRMLS_CC) > 0) {
		zephir_read_property(&_1$$3, this_ptr, SL("factories"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_1$$3, 0, "nc/factory/factories.zep", 62);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_1$$3), _2$$3)
		{
			ZEPHIR_INIT_NVAR(&factory);
			ZVAL_COPY(&factory, _2$$3);
			ZEPHIR_CALL_METHOD(&_3$$4, &factory, "__isset", NULL, 0, &name);
			zephir_check_call_status();
			if (zephir_is_true(&_3$$4)) {
				ZEPHIR_RETURN_CALL_METHOD(&factory, "__get", NULL, 0, &name);
				zephir_check_call_status();
				RETURN_MM();
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&factory);
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, nc_factory_exception_ce);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "Cannot fetch object '%s'");
	ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 6, &_5, &name);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 7, &_6);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_4, "nc/factory/factories.zep", 67 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

